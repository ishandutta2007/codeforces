/*
    21.03.2019 18:35:34
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
    string s;
    cin >> s;
    long long sm = 0;
    for (int i = 0; i < n; ++i) {
        if (((int)(s[i] - '0')) % 2 == 0) {
            sm += (long long)(i + 1);
        }
    }
    cout << sm << '\n';
    return 0;
}