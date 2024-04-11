#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
ll t;
const int maxN = 2e5 + 10;
ll pref[maxN];
ll g[maxN], c[maxN];
ll d[maxN];
struct SG{
    vector<vector<ll>> A, B;
    int n;
    void build(int v, int tl, int tr, vector<ll>& a, vector<ll>& b) {
        if (tl == tr) {
            A[v] = {a[tl]};
            B[v] = {b[tl]};
            return;
        }
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm, a, b);
        build(2 * v + 1, tm + 1, tr, a, b);
        merge (A[v*2].begin(), A[v*2].end(), A[v*2+1].begin(), A[v*2+1].end(),
               back_inserter (A[v]));
        merge (B[v*2].begin(), B[v*2].end(), B[v*2+1].begin(), B[v*2+1].end(),
               back_inserter (B[v]));
    }
    SG(vector<ll>& a, vector<ll>& b) {
        n = a.size();
        A.resize(4 * n + 10);
        B.resize(4 * n + 10);
        build(1, 0, n - 1, a, b);
    }

    int find_bad(int v, int tl, int tr, int l, int r, ll x) {
        if (tr < l || tl > r) return n;
        if (l <= tl && tr <= r) {
            //A[i] <= x <= B[i]
            //ravnosilno
            //check(A[i] <= x <= B[i])
            //cnt(B[i] >= x) != cnt(A[i] - 1 >= x)
            //cnt(B[i]) >= x
            //cnt(
            int f1 = lower_bound(A[v].begin(), A[v].end(), x) - A[v].begin();
            int f2 = lower_bound(B[v].begin(), B[v].end(), x) - B[v].begin();
            if (f1 == f2) {
                return n;
            }
        }
        if (tl == tr) return tl;
        int tm = (tl + tr) / 2;
        int p1 = find_bad(2 * v, tl, tm, l, r, x);
        if (p1 != n) return p1;
        return find_bad(2 * v + 1, tm + 1, tr, l, r, x);
    }
    int find_bad(int l, ll x) {
        //find_bad from x
        l--;
        return find_bad(1, 0, n - 1, l, n - 1, x) + 1;
    }
};
ll dp[maxN];
ll L[maxN];
ll norm(ll f) {
    f %= t;
    if (f < 0) f += t;
    return f;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> g[i] >> c[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> d[i];
        pref[i] = pref[i - 1] + d[i];
    }
    //
    vector<ll> a, b;
    for (int i = 1; i <= n; i++) {
        L[i] = pref[i - 1] + c[i];
        L[i] = norm(L[i]);
        a.emplace_back(g[i] - 1 - L[i]);
        b.emplace_back(t - 1 - L[i]);
    }
    auto st = SG(a, b);
    for (int i = n; i >= 1; i--) {
        ll cur_ti = norm(-c[i] - pref[i - 1]);
        int p1 = st.find_bad(i, cur_ti);
        int p2 = st.find_bad(i, cur_ti - t);
        p1 = min(p1, p2);
        if (p1 == n + 1) {
            dp[i] = 0;
        }
        else {
            ll he_will = norm(cur_ti + pref[p1 - 1] + c[p1]);
            assert(he_will >= g[p1] && he_will < t);
            dp[i] = (t - he_will) + dp[p1];
        }
    }

    vector<ll> cands;
    for (int i = 1; i <= n; i++) {
        cands.emplace_back(norm(-c[i] - pref[i - 1]));
        cands.emplace_back(norm(g[i] - 1 - pref[i - 1] - c[i]));
    }
    ll best = 1e18;
    for (auto& it : cands) {
        ll cur_ti = it;
        //0 .. t - 1
        int p1 = st.find_bad(1, cur_ti);
        int p2 = st.find_bad(1, cur_ti - t);
        p1 = min(p1, p2);
        if (p1 == n + 1) {
            best = 0;
        }
        else {
            ll he_will = norm(cur_ti + pref[p1 - 1] + c[p1]);
            assert(he_will >= g[p1] && he_will < t);
            best = min(best, t - he_will + dp[p1]);
        }
    }
    best += pref[n - 1];
    cout << best << '\n';


    return 0;
}