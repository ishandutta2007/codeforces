/*
    23.03.2019 16:11:01
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
    int tt;
    cin >> tt;
    for (int test = 0; test < tt; ++test) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s == string(n, '<') || s == string(n, '>')) {
            cout << 0 << '\n';
            continue;
        }
        int i1 = 0;
        while (i1 < n && s[i1] != '>') ++i1;
        int i2 = n - 1;
        while (i2 >= 0 && s[i2] != '<') --i2;
        cout << min(i1, n - 1 - i2) << '\n';
    }
    return 0;
}