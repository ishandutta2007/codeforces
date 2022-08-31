/*
    17.03.2019 20:26:40
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
    int w, h;
    cin >> w >> h;
    int u1, d1, u2, d2;
    cin >> u1 >> d1 >> u2 >> d2;
    while (h >= 0) {
        w += h;
        if (h == d1) {
            w = max(0, w - u1);
        }
        if (h == d2) {
            w = max(0, w - u2);
        }
        --h;
    }
    cout << w << '\n';
    return 0;
}