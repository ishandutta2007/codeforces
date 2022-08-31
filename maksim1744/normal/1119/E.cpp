/*
    06.04.2019 14:59:58
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 25
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
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long sm = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        long long d = min(a[i] / 2, sm);
        a[i] -= d * 2;
        sm -= d;
        ans += d + a[i] / 3;
        a[i] -= (a[i] / 3) * 3;
        sm += a[i];
    }
    cout << ans << '\n';
    return 0;
}