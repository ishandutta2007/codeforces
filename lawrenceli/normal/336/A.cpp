#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int x, y;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    cin >> x >> y;
    if (x<0) {
        if (y<0) {
            x=abs(x); y=abs(y);
            cout << -(x+y) << ' ' << 0 << ' ' << 0 << ' ' << -(x+y) << endl;
        }
        else {
            x=abs(x); y=abs(y);
            cout << -(x+y) << ' ' << 0 << ' ' << 0 << ' ' << (x+y) << endl;
        }
    }
    else {
        if (y<0) {
            x=abs(x); y=abs(y);
            cout << 0 << ' ' << -(x+y) << ' ' << (x+y) << ' ' << 0 << endl;
        }
        else {
            x=abs(x); y=abs(y);
            cout << 0 << ' ' << (x+y) << ' ' << (x+y) << ' ' << 0 << endl;
        }
    }
}