/*
    27.03.2019 22:43:31
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
    long long n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    if (s == t) {
        cout << n << '\n';
        return 0;
    }
    long long ans = 0;
    long long cnt = 1;
    int ind = 0;
    while (s[ind] == t[ind])
        ++ind;
    ans = ind;
    long long erased = 0;
    for (int i = ind; i < n; ++i) {
        cnt = cnt * 2;
        long long delta = 0;
        if (s[i] == 'b') ++delta;
        if (t[i] == 'a') ++delta;
        delta -= erased;
        cnt -= max(0ll, delta);
        if (cnt >= k) {
            ans += (long long)(n - i) * k;
            break;
        }
        showt(i, cnt, delta, erased);
        // if (cnt >= k + 2) {
        //     erased = 2;
        // } else if (cnt >= k + 1) {
        //     erased = max(erased, 1ll);
        // }
        // if (erased < 10)
        //     erased *= 2;
        ans += cnt;
    }
    cout << ans << '\n';
    return 0;
}