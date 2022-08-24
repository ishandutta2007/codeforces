#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, q;
const int maxN = 2e5 + 10;
int a[maxN];
int b[maxN];
ll pref[maxN];
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
struct Fenwick{
    vector<int> fenw;
    int n;
    Fenwick(int _n) {
        n = _n;
        fenw.resize(n + 1);
    }
    void upd(int v, ll by) {
        by = (by % mod + mod) % mod;
        while (v <= n) {
            fenw[v] = sum(fenw[v], by);
            v = (v | (v - 1)) + 1;
        }
    }
    int get(int l, int r) {
        return sub(get(r), get(l - 1));
    }
    int get(int r) {
        int ans = 0;
        while (r > 0) {
            ans = sum(ans, fenw[r]);
            r &= (r - 1);
        }
        return ans;
    }
};
int l[maxN], r[maxN];
vector<int> ask[maxN];
int delta[maxN];
int ans[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        delta[i] = a[i + 1] - a[i];
    }

    vector<ll> t = {0LL};
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        pref[i] = pref[i - 1] + b[i];
        t.emplace_back(pref[i]);
    }
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    for (int i = 1; i <= q; i++) {
        cin >> l[i] >> r[i];
        ask[r[i]].emplace_back(i);
        ask[l[i] - 1].emplace_back(i);
    }
    Fenwick f1(t.size()), f2(t.size());
    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(t.begin(), t.end(), pref[i]) - t.begin() + 1;
        int val = (pref[i] % mod + mod) % mod;
        for (int c : ask[i]) {
            //delta[i] * (p[i] - p[pos])
            int coef = sub(f1.get(pos, t.size()), f1.get(1, pos));
            coef = sub(coef, mult(val, sub(f2.get(pos, t.size()), f2.get(1, pos))));
            if (r[c] == i) {
                ans[c] = sum(ans[c], coef);
            }
            else {
                ans[c] = sub(ans[c], coef);
            }
        }
        //(
        f1.upd(pos, mult(delta[i], val));
        f2.upd(pos, delta[i]);
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}