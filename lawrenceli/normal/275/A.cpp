#include <iostream>
using namespace std;

int arr[5][5];

int main() {
    for (int i=1; i<=3; i++) {
        for (int j=1; j<=3; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i=1; i<=3; i++) {
        for (int j=1; j<=3; j++) {
            int n=1+arr[i][j]+arr[i+1][j]+arr[i-1][j]+arr[i][j+1]+arr[i][j-1];
            cout << n%2;
        }
        cout << endl;
    }
}