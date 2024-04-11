/*
    26.03.2019 19:40:45
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
    if (m == (long long)n * (long long)(n - 1) / 2) {
        cout << "NO\n";
        return 0;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int i1, i2;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() < n - 1) {
            vector<bool> has(n, false);
            has[i] = true;
            for (auto k : g[i]) {
                has[k] = true;
            }
            i1 = i;
            for (int j = 0; j < n; ++j) {
                if (!has[j]) {
                    i2 = j;
                    break;
                }
            }
        }
    }
    int ind = 0;
    int num = 1;
    vector<int> v(n);
    while (ind < n) {
        if (ind == i1) {
            v[ind] = n - 1;
        } else if (ind == i2) {
            v[ind] = n;
        } else {
            v[ind] = num++;
        }
        ++ind;
    }
    cout << "YES\n";
    for (auto k : v) {
        cout << k << ' ';
    }
    cout << '\n';
    v[i1] = n;
    for (auto k : v) {
        cout << k << ' ';
    }
    cout << '\n';
    return 0;
}