/*
    16.03.2019 14:37:00
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
    int n, m;
    cin >> n >> m;
    vector< vector< int > > a(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        a[u].push_back((v - u + n) % n);
    }
    for (int i = 0; i < n; ++i) {
        sort(a[i].begin(), a[i].end());
    }
    vector< long long > t(n, 0);
    for (int i = 0; i < n; ++i) {
        if (a[i].size() == 0)
            continue;
        t[i] = (a[i].size() - 1) * n + a[i].front();
    }
    show(t);
    for (int i = 0; i < n; ++i) {
        long long tt = 0;
        for (int j = i; j < n; ++j) {
            if (t[j] != 0)
                tt = max(tt, t[j] + (j - i));
        }
        for (int j = 0; j < i; ++j) {
            if (t[j] != 0)
                tt = max(tt, t[j] + (j - i + n) % n);
        }
        cout << tt << ' ';
    }
    cout << '\n';
    return 0;
}