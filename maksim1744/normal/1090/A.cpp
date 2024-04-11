/*
    26.03.2019 19:14:27
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
    vector<vector<int>> v(n);
    vector<long long> mxs(n);
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        v[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
        mxs[i] = *max_element(v[i].begin(), v[i].end());
    }
    long long mx = *max_element(mxs.begin(), mxs.end());
    long long sm = 0;
    for (int i = 0; i < n; ++i) {
        sm += (mx - mxs[i]) * (long long)v[i].size();
    }
    cout << sm << '\n';
    return 0;
}