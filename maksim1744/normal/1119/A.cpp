/*
    06.04.2019 14:36:06
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 25
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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (a[0] != a[n - 1]) {
        cout << n - 1 << '\n';
    } else {
        int i1 = 0;
        while (a[i1] == a[0])
            ++i1;
        int i2 = n - 1;
        while (a[i2] == a[n - 1])
            --i2;
        cout << max(n - 1 - i1, i2) << '\n';
    }
    return 0;
}