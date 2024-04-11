#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int num[5];

int main() {
    for (int i=0; i<4; i++) cin >> num[i];
    int d=num[1]-num[0];
    if (num[1]+d == num[2] && num[2]+d == num[3]) {
        cout << num[3]+d << endl;
        return 0;
    }
    if (num[1]*num[1] == num[0]*num[2] && num[2]*num[2] == num[1]*num[3]) {
        int x = num[3]*num[3], y = num[2];
        if (x%y==0) {
            cout << x/y << endl;
            return 0;
        }
    }
    cout << 42 << endl;
}