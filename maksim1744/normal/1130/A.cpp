/*
    16.03.2019 17:13:56
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

int main() {
    int n;
    cin >> n;
    vector< int > a(n);
    int np = 0, nm = 0, n0 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) ++n0;
        if (a[i] > 0) ++np;
        if (a[i] < 0) ++ nm;
    }
    int half = (n + 1) / 2;
    if (np >= half) cout << 1 << '\n';
    else if (nm >= half) cout << -1 << '\n';
    else cout << 0 << '\n';
    return 0;
}