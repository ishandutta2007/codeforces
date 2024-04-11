/*
    14.03.2019 18:51:59
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
const int mxn = 10;
#else
const int mxn = 500000 + 10;
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
    int m, k, n, s;
    cin >> m >> k >> n >> s;
    vector< int > a(m);
    vector< int > b(s);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    vector< int > need(mxn, 0);
    int needk = 0;
    for (int i = 0; i < s; ++i) {
        cin >> b[i];
        ++need[b[i]];
        if (need[b[i]] == 1)
            ++needk;
    }
    int ln = m - k * n + k;
    show(ln);
    vector< int > cnt(mxn, 0);
    int cntk = 0;
    int ind = ln - 1;
    bool found = true;
    for (int i = 0; i < min(ln, m); ++i) {
        ++cnt[a[i]];
        if (cnt[a[i]] == need[a[i]])
            ++cntk;
    }
    show(cntk);
    show(cnt);
    show(need);
    show(needk);
    if (cntk < needk) {
        found = false;
        for (int i = min(ln, m); i < m; ++i) {
            ++ind;
            if (cnt[a[i - ln]] == need[a[i - ln]])
                --cntk;
            --cnt[a[i - ln]];
            ++cnt[a[i]];
            if (cnt[a[i]] == need[a[i]])
                ++cntk;
            if (cntk == needk && (i - ln + 1) % k == 0) {
                found = true;
                break;
            }
        }
    }
    if (cntk < needk) {
        cout << -1 << '\n';
        return 0;
    }
    vector< int > del;
    vector< bool > needp(m, false);
    for (int i = ind - ln + 1; i <= ind; ++i) {
        if (need[a[i]] != 0) {
            needp[i] = true;
            --need[a[i]];
        } else {
            del.push_back(i);
        }
    }
    if (del.size() > ln - k)
        del.resize(ln - k);
    cout << del.size() << '\n';
    for (auto k : del) {
        cout << k + 1 << ' ';
    }
    cout << '\n';
    return 0;
}