/*
    08.03.2019 12:23:15
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
    string s, t;
    cin >> s >> t;
    if (t.size() > s.size()) {
        cout << s << '\n';
        return 0;
    }
    vector< int > z(t.size(), 0);
    int l = 0, r = 0;
    for (int i = 1; i < t.size(); ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < t.size() && t[z[i]] == t[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    // show(z);
    int p = -1;
    for (int i = 1; i < t.size(); ++i) {
        if (z[i] + i == t.size()) {
            p = i;
            break;
        }
    }
    if (p == -1) {
        p = t.size();
    }
    // show(p);
    int n0 = 0, n1 = 0;
    for (auto item : s) {
        if (item == '0') ++n0;
        else ++n1;
    }
    int t0 = 0, t1 = 0;
    for (int i = 0; i < p; ++i) {
        if (t[i] == '0') ++t0;
        else ++t1;
    }
    int cnt = 1000000;
    // show(n0, n1, t0, t1);
    if (t0 != 0) {
        cnt = min(cnt, n0 / t0);
    }
    if (t1 != 0) {
        cnt = min(cnt, n1 / t1);
    }
    string tp = t.substr(0, p);
    for (int i = 0; i < cnt; ++i) {
        cout << tp;
        n0 -= t0;
        n1 -= t1;
    }
    int ind = 0;
    while (n0 != 0 && n1 != 0) {
        cout << t[ind];
        if (t[ind] == '0') --n0;
        else --n1;
        ++ind;
        if (ind == p) ind = 0;
    }
    cout << string(n1, '1');
    cout << string(n0, '0');
    cout << '\n';
    return 0;
}