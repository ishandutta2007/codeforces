/*
    07.02.2019 16:39:38
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
    long long n, m, k;
    cin >> n >> m >> k;
    vector< long long > b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    long long sm = b.back() - b.front() + 1;
    show(sm);
    vector< long long > a(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        a[i] = b[i + 1] - b[i] - 1;
    }
    sort(a.begin(), a.end());
    show(a);
    for (int i = n - 2; i >= max((long long)0, n - 1 - (k - 1)); --i) {
        sm -= a[i];
    }
    cout << sm << '\n';
    return 0;
}