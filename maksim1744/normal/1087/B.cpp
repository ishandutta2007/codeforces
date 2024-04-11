/*
    25.03.2019 20:04:53
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
    long long ans = -1;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            for (long long d1 : {i, n / i}) {
                long long d2 = n / d1;
                long long x = d1 * k + d2;
                if (d2 < k && (ans == -1 || ans > x))
                    ans = x;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}