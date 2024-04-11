/*
    06.04.2019 14:49:46
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
    vector<long long> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    vector<long long> d(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        d[i] = s[i + 1] - s[i];
    }
    sort(d.begin(), d.end());
    vector<long long> sm(n);
    sm[0] = 0;
    for (int i = 0; i < n - 1; ++i) {
        sm[i + 1] = sm[i] + d[i];
    }
    int q;
    cin >> q;
    for (int iii = 0; iii < q; ++iii) {
        long long l, r;
        cin >> l >> r;
        r -= l;
        ++r;
        int ind = lower_bound(d.begin(), d.end(), r) - d.begin();
        // show(d, ind);
        cout << sm[ind] + (long long)(n - 1 - ind) * r + r << ' ';
    }
    cout << '\n';
    return 0;
}