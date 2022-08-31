/*
    07.02.2019 16:35:40
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
    int b, k;
    cin >> b >> k;
    vector< int > a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    if (b % 2 == 0) {
        if (a.back() % 2 == 0) {
            cout << "even\n";
        } else {
            cout << "odd\n";
        }
    } else {
        int sm = 0;
        for (int i = 0; i < k; ++i) {
            sm += a[i];
        }
        if (sm % 2 == 0) {
            cout << "even\n";
        } else {
            cout << "odd\n";
        }
    }
    return 0;
}