#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 5e5 + 10;
const ll INF = 1e18;
ll merge(ll x, ll y) {
    return max(x, y);
}
struct SegmentTree {
    int n;
    vector<ll> t;
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = -INF;
            return;
        }
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
    SegmentTree(int _n) {
        n = _n;
        t.resize(4 * n);
        build(1, 1, n);
    }
    void upd(int v, int tl, int tr, int pos, ll all) {
        if (tl == tr) {
            t[v] = max(t[v], all);
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm) upd(2 * v, tl, tm, pos, all);
        else upd(2 * v + 1, tm + 1, tr, pos, all);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
    ll get(int v, int tl, int tr, int l, int r) {
        if (l > r) return -INF;
        if (tl == l && tr == r) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        if (r <= tm) return get(2 * v, tl, tm, l, r);
        else if (l > tm) return get(2 * v + 1, tm + 1, tr, l, r);
        else {
            return merge(get(2 * v, tl, tm, l, tm), get(2 * v + 1, tm + 1, tr, tm + 1, r));
        }
    }
};
ll a[maxN];
ll pref[maxN];
int where[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<ll> c;
        c.emplace_back(pref[0]);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pref[i] = pref[i - 1] + a[i];
            c.emplace_back(pref[i]);
        }
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        SegmentTree f1(c.size()), f2(c.size()), f3(c.size());
        vector<ll> dp(n + 1, -1e18);
        int N = c.size();
        for (int i = 0; i <= n; i++) {
            where[i] = lower_bound(c.begin(), c.end(), pref[i]) - c.begin() + 1;
//            cout << where[i] << " ??? " << endl;
        }
        dp[0] = 0;
        f1.upd(1, 1, N, where[0], 0);
        f2.upd(1, 1, N, where[0], 0);
        f3.upd(1, 1, N, where[0], 0);
        for (int i = 1; i <= n; i++) {
            ll s1 = f1.get(1, 1, N, 1, where[i] - 1) + i;
            ll s2 = f2.get(1, 1, N, where[i], where[i]);
            ll s3 = f3.get(1, 1, N, where[i] + 1, N) - i;
            dp[i]  = max({s1, s2, s3});
            f1.upd(1, 1, N, where[i], dp[i] - i);
            f2.upd(1, 1, N, where[i], dp[i]);
            f3.upd(1, 1, N, where[i], dp[i] + i);
        }
        cout << dp[n] << '\n';
    }
    return 0;
}