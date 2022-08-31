/*
    19.03.2019 23:13:41
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
    int n, v;
    cin >> n >> v;
    int sm = min(v, n - 1);
    int now = min(v, n - 1) - 1;
    for (int i = 2; i <= n; ++i) {
        if (n - i <= now) continue;
        sm += max(0, min(v - now, n - now - i)) * i;
        now = min(n - i, v);
        --now;
    }
    cout << sm << '\n';
    return 0;
}