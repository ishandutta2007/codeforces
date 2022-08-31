/*
    01.04.2019 18:48:24
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
    if (n == 0) {
        cout << 15 << '\n';
    } else if (n == 1) {
        cout << 14 << '\n';
    } else if (n == 2) {
        cout << 12 << '\n';
    } else if (n == 3) {
        cout << 13 << '\n';
    } else if (n == 4) {
        cout << 8 << '\n';
    } else if (n == 5) {
        cout << 9 << '\n';
    } else if (n == 6) {
        cout << 10 << '\n';
    } else if (n == 7) {
        cout << 11 << '\n';
    } else if (n == 8) {
        cout << 0 << '\n';
    } else {
        cout << n - 8 << '\n';
    }
    return 0;
}