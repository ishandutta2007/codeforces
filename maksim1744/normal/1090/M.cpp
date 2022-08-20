/*
    26.03.2019 19:33:27
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a.push_back(a.back());
    int last = -1;
    int mx = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == a[i + 1]) {
            mx = max(i - last, mx);
            last = i;
        }
    }
    cout << mx << '\n';
    show(mx);
    return 0;
}