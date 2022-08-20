/*
    15.03.2019 16:20:14
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
    int n, k;
    cin >> n >> k;
    vector< int > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int d = 0;
    int m = 0;
    int last = min(k, n);
    vector< int > t(n, 0);
    set< int > now;
    for (int i = 0; i < min(n, k); ++i) {
        now.insert(i);
    }
    set< int > ans;
    while (now.size() > 0) {
        assert(now.size() <= k);
        for (auto u : now) {
            ++t[u];
            if (t[u] == d) {
                ans.insert(u);
            }
        }
        vector< int > ok;
        for (auto u : now) {
            if (t[u] == a[u]) {
                ok.push_back(u);
                ++m;
            }
        }
        for (auto u : ok) {
            now.erase(u);
            if (last < n) {
                now.insert(last);
                ++last;
            }
        }
        d = (100 * m + n / 2) / n;
    }
    cout << ans.size() << '\n';
    return 0;
}