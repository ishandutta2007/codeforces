/*
    26.03.2019 20:32:03
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
    vector<long long> a(n);
    long long sm = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sm += a[i];
    }
    sort(a.rbegin(), a.rend());
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int q;
        cin >> q;
        --q;
        cout << sm - a[q] << '\n';
    }
    return 0;
}