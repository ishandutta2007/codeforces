/*
    19.03.2019 23:03:12
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
    int sm = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sm += a[i];
    }
    sort(a.begin(), a.end());
    int ans = sm;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= a[i]; ++j) {
            if (a[i] % j == 0) {
                ans = min(ans, sm - a[i] - a[0] + a[i] / j + a[0] * j);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}