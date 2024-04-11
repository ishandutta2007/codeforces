/*
    27.03.2019 18:06:58
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
    long long w1, w2, h1, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    long long ans = h1 + h2 + 2 + h1 + 1 + h2 + 1 + w1 + w2 + w1 - w2;
    cout << ans << '\n';
    return 0;
}