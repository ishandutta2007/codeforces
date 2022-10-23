#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, q;
const int maxN = 3e5 + 10;
int a[maxN];
int tp[maxN];
int l[maxN];
int r[maxN];
int k[maxN];
bool ok[maxN];
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll f[maxN];
ll mp[2 * maxN];
const ll M = 1e12;
ll fenw[maxN];
int b[maxN];
void upd(int v, ll by) {
    while (v <= n) {
        fenw[v] += by;
        v = (v | (v - 1)) + 1;
    }
}
ll get(int r) {
    ll ans = 0;
    while (r > 0) {
        ans += fenw[r];
        r &= (r - 1);
    }
    return ans;
}
ll get(int l, int r) {
    return get(r) - get(l - 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> q;
    vector<int> vals;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vals.emplace_back(a[i]);
    }
    for (int i = 1; i <= q; i++) {
        cin >> tp[i];
        cin >> l[i] >> r[i];
        if (tp[i] == 2) cin >> k[i];
        if (tp[i] == 1) {
            vals.emplace_back(r[i]);
        }
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
    }
    for (int i = 1; i <= q; i++) {
        if (tp[i] == 1) {
            r[i] = lower_bound(vals.begin(), vals.end(), r[i]) - vals.begin();
        }
        else {
            ok[i] = true;
        }
    }
    memcpy(b, a, sizeof(a));
    for (int iter = 0; iter < 40; iter++) {
        for (int x = 0; x < vals.size(); x++) {
            mp[x] = (rng() | (rng() << 30)) % M;
        }
        memcpy(a, b, sizeof(a));
        for (int i = 0; i <= n; i++) {
            fenw[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            upd(i, mp[a[i]]);
        }
        for (int i = 1; i <= q; i++) {
            if (tp[i] == 1) {
                upd(l[i], mp[r[i]] - mp[a[l[i]]]);
                a[l[i]] = r[i];
            }
            else if (ok[i]) {
                ll s = get(l[i], r[i]);
                if (s % k[i] != 0) {
                    ok[i] = false;
                }
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        if (tp[i] == 2) {
            if (ok[i]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}