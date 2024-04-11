/*
    26.03.2019 20:25:59
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
    int c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;
    if (c3 == 0) {
        cout << (int)(c1 == c4) << '\n';
    } else {
        c1 *= 2;
        c4 *= 2;
        c1 -= 1;
        c4 -= 1;
        if (c1 < 0 || c4 < 0 || c1 != c4) cout << 0 << '\n';
        else cout << 1 << '\n';
    }
    return 0;
}