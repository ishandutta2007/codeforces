/*
    16.03.2019 17:10:51
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
    vector< vector< int > > where(n);
    for (int i = 0; i < n * 2; ++i) {
        int u;
        cin >> u;
        --u;
        where[u].push_back(i);
    }
    int i1 = 0, i2 = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int i3 = where[i][0], i4 = where[i][1];
        ans += min(abs(i3 - i1) + abs(i4 - i2), abs(i4 - i1) + abs(i3 - i2));
        i1 = i3;
        i2 = i4;
    }
    cout << ans << '\n';
    return 0;
}