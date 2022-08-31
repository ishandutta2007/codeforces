#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = (int)1e9 + 7;
const int maxN = 250 * 1000 + 10;
int n;
int p[maxN];
int dp[maxN];
int l[maxN], r[maxN];
int l2[maxN], r2[maxN];
struct SegmentTree {
    int n;
    vector<pair<int,int>> t;


    void merge(int v) {
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }

    void build(int v, int tl, int tr, const vector<pair<int,int>> &all) {
        if (tl == tr) {
            t[v] = all[tl - 1];
            return;
        }
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm, all);
        build(2 * v + 1, tm + 1, tr, all);
        merge(v);
    }

    explicit SegmentTree(const vector<pair<int,int>> &f) {
        n = f.size();
        t.resize(4 * n);
        build(1, 1, n, f);
    }

    void upd(int v, int tl, int tr, int pos, pair<int, int> &all) {
        if (tl == tr) {
            t[v] = all;
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm) upd(2 * v, tl, tm, pos, all);
        else upd(2 * v + 1, tm + 1, tr, pos, all);
        merge(v);
    }

    pair<int,int> get(int v, int tl, int tr, int l, int r) {
        if (tr < l || tl > r) return make_pair(1e9, -1);
        if (l <= tl && tr <= r) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
    }
};
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    vector<pair<int,int>> st1, st2;
    dp[1] = 0;
    st1.emplace_back(-1e9, 0);
    st2.emplace_back(1e9, 0);
    vector<pair<int,int>> f1, f2;
    for (int i = 1; i <= n; i++) {
        while (!st1.empty() && st1.back().first > p[i]) {
            st1.pop_back();
        }
        while (!st2.empty() && st2.back().first < p[i]) {
            st2.pop_back();
        }
        l[i] = st1.back().second + 1;
        r[i] = st2.back().second + 1;
        f1.emplace_back(l[i], i);
        f2.emplace_back(r[i], i);
        st1.emplace_back(p[i], i);
        st2.emplace_back(p[i], i);
    }
    st1.clear();
    st2.clear();
    st1.emplace_back(-1e9, n + 1);
    st2.emplace_back(1e9, n + 1);
    for (int i = n; i >= 1; i--) {
        while (!st1.empty() && st1.back().first > p[i]) {
            st1.pop_back();
        }
        while (!st2.empty() && st2.back().first < p[i]) {
            st2.pop_back();
        }
        l2[i] = st1.back().second - 1;
        r2[i] = st2.back().second - 1;
        st1.emplace_back(p[i], i);
        st2.emplace_back(p[i], i);
    }
    auto s1 = SegmentTree(f1);
    auto s2 = SegmentTree(f2);
    queue<int> q;
    for (int i = 2; i <= n; i++) {
        dp[i] = -1;
    }
    dp[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
//        cout << v << " ???? " << r2[v] << " " << l2[v]<< endl;
        pair<int,int> t = {1e9, 1e9};
        while (true) {
            auto it = s1.get(1, 1, n, v + 1, r2[v]);
//            cout << " ??? " << it.first << " " << it.second << endl;
            if (it.first <= v) {
                dp[it.second] = dp[v] + 1;
                q.push(it.second);
//                cout << it.second << endl;
                s1.upd(1, 1, n, it.second, t);
                s2.upd(1, 1, n, it.second, t);
            }
            else {
                break;
            }
        }
        while (true) {
            auto it = s2.get(1, 1, n, v + 1, l2[v]);
//            cout << it.first << " " << it.second << endl;
            if (it.first <= v) {
                dp[it.second] = dp[v] + 1;
                q.push(it.second);
                s1.upd(1, 1, n, it.second, t);
                s2.upd(1, 1, n, it.second, t);
            }
            else {
                break;
            }
        }
    }
    cout << dp[n] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}