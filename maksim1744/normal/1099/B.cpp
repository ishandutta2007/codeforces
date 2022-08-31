/*
    17.03.2019 20:22:34
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
    long long n;
    cin >> n;
    long long l = 0, r = n + 5;
    while (r - l > 1) {
        long long m = (l + r) / 2;
        if (m / 2 * (m - m / 2) >= n) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << '\n';
    return 0;
}