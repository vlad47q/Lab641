#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void inputArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = "; cin >> arr[i];
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(5) << arr[i];
    }
    cout << endl;
}

int countOfElemsGreaterThan(int* arr, int size, int C) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > C) {
            counter++;
        }
    }
    return counter;
}

int bimBimBamBamBomBom(int* arr, int size) {
    int maxAbs = 0, maxAbsIndex = 0;
    int mtpr = 1;

    for (int i = 0; i < size; i++) {
        if (abs(arr[i]) > maxAbs) {
            maxAbs = abs(arr[i]);
            maxAbsIndex = i;
        }
    }
    if (maxAbsIndex != size) {
        for (int j = maxAbsIndex + 1; j < size; j++) {
            mtpr *= arr[j];
        }
    }

    return mtpr;
}

int* fakeSortArray(int* arr, int size) {
    int* arrayCopy = new int[size];
    int negativeIndex = 0;
    int positiveIndex = 0;

    for (int i = 0; i < size; i++) {
        arrayCopy[i] = arr[i];
        if (arr[i] < 0) {
            positiveIndex++;
        }
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            arrayCopy[negativeIndex] = arr[i];
            negativeIndex++;
        }
        else {
            arrayCopy[positiveIndex] = arr[i];
            positiveIndex++;
        }
    }
    return arrayCopy;
}


int main() {
    int size, c;
    cout << "input size: "; cin >> size;
    cout << "input C: "; cin >> c;

    int* dynamicArray = new int[size];

    inputArray(dynamicArray, size);
    printArray(dynamicArray, size);

    cout << "Count of elems greater than " << c << " is: " << countOfElemsGreaterThan(dynamicArray, size, c) << endl;
    cout << "Multiplier of elements that goes after the element that has a highest abs in the array = " << bimBimBamBamBomBom(dynamicArray, size) << endl;

    int* fsArray = fakeSortArray(dynamicArray, size);

    cout << "Old array: " << endl;
    printArray(dynamicArray, size);

    cout << "Fakesorted array: " << endl;
    printArray(fsArray, size);

    return 0;
}
