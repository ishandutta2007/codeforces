/*
    22.01.2019 18:02:28
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#include "C:/C++ libs/print.h"
#define show(x) cout << "     " << #x << " = " << to_string(x) << endl;
#else
#define show(x) 42;
#define print(x) 42;
#define printTree(x) 42;
#define printMatrix(x) 42;
#endif

int main() {
    while (true) {
        string s;
        cin >> s;
        if (s == "mistake" || s == "end") {
            return 0;
        }
        int y = 1;
        int x = 0;
        while (true) {
            cout << "? " << x << ' ' << y << endl;
            char c;
            cin >> c;
            if (c == 'y') { // a > y
                x = y;
                y = x * 2;
            } else { // x < a <= y
                break;
            }
        }
        long long l = x, r = y;
        while (r - l > 1) {
            cout << "? " << ((l + r) / 2 + 1) / 2 << ' ' << (l + r) / 2 << endl;
            char c;
            cin >> c;
            if (c == 'x') {
                r = (l + r) / 2;
            } else {
                l = (l + r) / 2;
            }
        }
        cout << "! " << r << endl;
    }
    return 0;
}