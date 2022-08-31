/*
    22.01.2019 17:36:27
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
    string s;
    cin >> s;
    bool a0 = true, a1 = true;
    for (auto c : s) {
        if (c == '0') {
            if (a0) {
                cout << 1 << ' ' << 1 << '\n';
                a0 = !a0;
            } else {
                cout << 3 << ' ' << 1 << '\n';
                a0 = !a0;
            }
        } else {
            if (a1) {
                cout << 4 << ' ' << 3 << '\n';
                a1 = !a1;
            } else {
                cout << 4 << ' ' << 1 << '\n';
                a1 = !a1;
            }
        }
    }
    return 0;
}