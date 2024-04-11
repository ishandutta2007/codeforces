/*
    16.03.2019 21:49:35
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
    vector< int > t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    int mx = 0;
    for (int iii = 0; iii < 2; ++iii) {
        vector< int > l1(n, 0), r2(n, 0);
        l1[0] = (t[0] == 1);
        for (int i = 1; i < n; ++i) {
            if (t[i] == 2) l1[i] = 0;
            else l1[i] = l1[i - 1] + 1;
        }
        r2[n - 1] = (t[n - 1] == 2);
        for (int i = n - 2; i >= 0; --i) {
            if (t[i] == 1) r2[i] = 0;
            else r2[i] = r2[i + 1] + 1;
        }
        for (int i = 1; i < n; ++i) {
            mx = max(mx, min(l1[i - 1], r2[i]));
            mx = max(mx, min(r2[i - 1], l1[i]));
        }
        for (int i = 0; i < n; ++i) {
            t[i] = 3 - t[i];
        }
    }
    cout << mx * 2 << '\n';
    return 0;
}