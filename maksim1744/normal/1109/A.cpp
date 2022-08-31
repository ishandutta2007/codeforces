/*
    16.03.2019 22:34:20
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
    vector< long long > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector< long long > x(n + 1);
    x[0] = 0;
    for (int i = 0; i < n; ++i) {
        x[i + 1] = x[i] ^ a[i];
    }
    vector< map< int, long long > > mp(2);
    for (int i = 0; i < n + 1; ++i) {
        mp[i % 2][x[i]]++;
    }
    long long ans = 0;
    for (int i = 0; i < 2; ++i) {
        for (auto p : mp[i]) {
            ans += p.second * (p.second - 1) / 2;
        }
    }
    cout << ans << '\n';
    return 0;
}