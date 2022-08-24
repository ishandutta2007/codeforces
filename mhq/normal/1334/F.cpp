#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
struct Fenw{
    vector < ll > fenw;
    int n;
    Fenw(int _n) {
        n = _n;
        fenw.resize(n + 1);
    }
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
};
int n;
const int maxN = 5e5 + 10;
ll p[maxN];
int m;
vector < int > in_c[maxN];
int a[maxN];
int b[maxN];
ll dp[maxN];
const ll INF = 1e18;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        in_c[a[i]].emplace_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    Fenw gre(n), sma(n);
    for (int i = 1; i <= n; i++) {
        gre.upd(i, p[i]);
    }
    ll best = INF;
    for (int i = 1; i <= m; i++) {
        if (i > 1) {
            for (int v = b[i - 2] + 1; v <= b[i - 1]; v++) {
                for (int c : in_c[v]) {
                    gre.upd(c, -p[c]);
                    sma.upd(c, min(p[c], 0LL));
                }
            }
        }
        int l = 0;
        ll cur_b = INF;
        for (int v : in_c[b[i]]) {
            while (l < in_c[b[i - 1]].size() && in_c[b[i - 1]][l] < v) {
                int ind = in_c[b[i - 1]][l];
                if (dp[ind] == INF) {
                    l++;
                    continue;
                }
                cur_b = min(cur_b, dp[ind] - gre.get(ind) - sma.get(ind));
                l++;
            }
            if (i == 1) {
                dp[v] = gre.get(v - 1) + sma.get(v - 1);
                continue;
            }
            if (cur_b == INF) {
                dp[v] = INF;
            }
            else {
                dp[v] = cur_b + gre.get(v - 1) + sma.get(v - 1);
            }
        }
    }
    for (int i = b[m - 1] + 1; i <= b[m]; i++) {
        for (int c : in_c[i]) {
            gre.upd(c, -p[c]);
            sma.upd(c, min(p[c], 0LL));
        }
    }
    for (int v : in_c[b[m]]) {
        if (dp[v] == INF) continue;
        best = min(best, dp[v] + gre.get(n) - gre.get(v) + sma.get(n) - sma.get(v));
    }
    if (best == INF) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        cout << best;
    }
    return 0;
}