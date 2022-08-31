/*
    31.03.2019 23:19:06
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
    long long a0, b0;
    cin >> a0 >> b0;
    long long mn = 1e9l * 1e9l, mx = 0;
    for (long long x = 1; x <= n; ++x) {
        for (auto a : {-a0, a0}) {
            for (auto b : {-b0, b0}) {
                long long l = x * k + a + b;
                while (l < 0)
                    l += n * k;
                long long cnt = n * k / __gcd(l, n * k);
                mn = min(mn, cnt);
                mx = max(mx, cnt);
            }
        }
    }
    cout << mn << ' ' << mx << '\n';
    return 0;
}