/*
    01.04.2019 18:06:44
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

vector<int> a;

int solve(int l, int r) {
    bool ok = true;
    for (int i = l; i < r; ++i) {
        if (a[i + 1] < a[i]) {
            ok = false;
            break;
        }
    }
    if (ok) return r - l + 1;
    return max(solve(l, (l + r) / 2), solve((l + r) / 2 + 1, r));
}

int main() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << solve(0, n - 1) << '\n';
    return 0;
}