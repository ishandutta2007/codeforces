/*
    15.03.2019 16:31:59
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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map< int, int > mp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            ++mp[a[i] + a[j]];
        }
    }
    int mx = 0;
    for (auto p : mp) {
        mx = max(mx, p.second);
    }
    cout << mx << '\n';
    return 0;
}