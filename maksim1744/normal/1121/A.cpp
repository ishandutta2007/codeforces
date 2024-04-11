/*
    15.03.2019 16:35:16
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
    int n, m, k;
    cin >> n >> m >> k;
    vector< int > p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    vector< int > s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    set< int > best;
    for (int i = 0; i < m; ++i) {
        int b = -1;
        int ib = -1;
        for (int j = 0; j < n; ++j) {
            if (s[j] - 1 == i && p[j] > b) {
                ib = j;
                b = p[j];
            }
        }
        best.insert(ib + 1);
    }
    int ans = 0;
    vector< int > c(k);
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
        if (best.find(c[i]) == best.end())
            ++ans;
    }
    cout << ans << '\n';
    return 0;
}