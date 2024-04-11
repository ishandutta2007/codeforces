#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3 * (int)1e5 + 100;
int bal[maxN];
string s;
int n;
pair < int, int > unite(pair < int, int > a, pair < int, int > b) {
    if (a.first < b.first) return a;
    if (a.first > b.first) return b;
    a.second += b.second;
    return a;
}
int best = -5;
int l, r;
void upd(int val, int _l, int _r) {
    if (val > best) {
        best = val;
        l = _l;
        r = _r;
    }
}
pair < int, int > pref[maxN];
pair < int, int > suf[maxN];
int tp[maxN];
int VAL = 0;
pair < int, int > vals[maxN];
void solve(int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    solve(l, mid);
    solve(mid + 1, r);
    for (int i = mid; i >= l; i--) {
        vals[i] = make_pair(bal[i], 1);
        if (i < mid) vals[i] = unite(vals[i], vals[i + 1]);
    }
    vals[mid + 1] = make_pair(1e9, 0);
    for (int i = mid + 2; i <= r; i++) {
        vals[i] = make_pair(bal[i - 1], 1);
        if (i > mid + 1) vals[i] = unite(vals[i - 1], vals[i]);
    }
    pair < int, int > best1 = make_pair(-1e9, 0);
    pair < int, int > best2 = make_pair(-1e9, 0);
    for (int i = l; i <= mid; i++) {
        if (vals[i].first >= VAL + 2 && pref[i - 1].first >= VAL && tp[i] == 1) {
            int c1 = 0;
            if (vals[i].first == VAL + 2) c1 += vals[i].second;
            if (pref[i - 1].first == VAL) c1 += pref[i - 1].second;
            best1 = max(best1, make_pair(c1, i));
        }
    }
    for (int i = mid + 1; i <= r; i++) {
        if (vals[i].first >= VAL + 2 && suf[i].first >= VAL && tp[i] == -1) {
            int c2 = 0;
            if (vals[i].first == VAL + 2) c2 += vals[i].second;
            if (suf[i].first == VAL) c2 += suf[i].second;
            best2 = max(best2, make_pair(c2, i));
        }
    }
    upd(best1.first + best2.first, best1.second, best2.second);
    best1 = make_pair(-1e9, 0);
    best2 = make_pair(-1e9, 0);
    for (int i = l; i <= mid; i++) {
        if (vals[i].first >= VAL - 2 && pref[i - 1].first >= VAL && tp[i] == -1) {
            int c1 = 0;
            if (vals[i].first == VAL - 2) c1 += vals[i].second;
            if (pref[i - 1].first == VAL) c1 += pref[i - 1].second;
            best1 = max(best1, make_pair(c1, i));
        }
    }
    for (int i = mid + 1; i <= r; i++) {
        if (vals[i].first >= VAL - 2 && suf[i].first >= VAL && tp[i] == 1) {
            int c2 = 0;
            if (vals[i].first == VAL - 2) c2 += vals[i].second;
            if (suf[i].first == VAL) c2 += suf[i].second;
            best2 = max(best2, make_pair(c2, i));
        }
    }
    upd(best1.first + best2.first, best1.second, best2.second);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') tp[i + 1] = 1;
        else tp[i + 1] = -1;
    }
    bal[0] = 0;
    pref[0] = make_pair(1e9, 0);
    for (int i = 1; i <= n; i++) {
        bal[i] = bal[i - 1];
        if (tp[i] == 1) bal[i]++;
        else bal[i]--;
        pref[i] = unite(pref[i - 1], make_pair(bal[i], 1));
    }
    if (bal[n] != 0) {
        cout << 0 << '\n' << 1 << " " << 1;
        return 0;
    }
    suf[n] = make_pair(0, 1);
    for (int i = n - 1; i >= 0; i--) suf[i] = unite(suf[i + 1], make_pair(bal[i], 1));
    best = pref[n].second;
    l = 1;
    r = 1;
    int mn = pref[n].first;
    for (int cur_mn = mn - 2; cur_mn <= mn + 2; cur_mn++) {
        VAL = cur_mn;
        solve(1, n);
    }
    cout << best << '\n' << l << " " << r;
    return 0;
}