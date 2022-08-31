/*
    13.03.2019 20:45:27
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
    vector< vector< int > > a(n, vector< int >(m)), b(n, vector< int >(m));
    for (auto& line : a)
        for (auto& k : line)
            cin >> k;
    for (auto& line : b)
        for (auto& k : line)
            cin >> k;
    vector< vector< int > > da(n + m + 2), db(n + m + 2);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            da[i + j].push_back(a[i][j]);
            db[i + j].push_back(b[i][j]);
        }
    }
    for (int i = 0; i < n + m + 2; ++i) {
        sort(da[i].begin(), da[i].end());
        sort(db[i].begin(), db[i].end());
    }
    cout << (da == db ? "YES" : "NO") << '\n';
    return 0;
}