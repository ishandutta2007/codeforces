/*
    13.01.2019 15:59:09
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#include "C:/C++ libs/print.h"
#define show(x) cout << "     | " << #x << " = " << to_string(x) << endl;
#else
#define show(x) 42;
#define print(x) 42;
#define printTree(x) 42;
#define printMatrix(x) 42;
#endif

int main() {
    int t;
    cin >> t;
    for (int ttt = 0; ttt < t; ++ttt) {
        long long l, r;
        cin >> l >> r;
        show(l);
        show(r);
        cout << l << ' ' << l * 2 << '\n';
    }
    return 0;
}