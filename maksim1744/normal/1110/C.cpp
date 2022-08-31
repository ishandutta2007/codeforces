/*
    07.02.2019 16:45:26
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
    int q;
    cin >> q;
    for (int test = 0; test < q; ++test) {
        long long a;
        cin >> a;
        long long p = 1;
        while (p - 1 < a) {
            p <<= 1;
        }
        if (a == p - 1) {
            long long b = 2;
            while (b * b < a) {
                if (a % b == 0) {
                    cout << a / b << '\n';
                    break;
                }
                ++b;
            }
            if (a % b != 0) {
                cout << 1 << '\n';
            }
        } else {
            cout << p - 1 << '\n';
        }
    }
    return 0;
}