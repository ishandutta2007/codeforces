#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = (int)1e6 + 10;
vector < int > g[maxN];
int p[maxN];
int a[maxN];
ll s = 0;
ll tr[maxN];
set < ll > all;
void dfs(int v) {
    tr[v] = a[v];
    for (int to : g[v]) {
        dfs(to);
        tr[v] += tr[to];
    }
    if (s % tr[v] == 0) {
        if ((s / tr[v]) <= n) all.insert(tr[v]);
    }
}
int val[maxN];
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
set < ll > ok;
ll id[maxN];
ll sm[maxN];
map < ll, int > f;
int dp[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        g[p[i]].push_back(i + 1);
    }
    dfs(1);
    int sz = 1;
    int oth = 1;
    for (ll t : all) {
        memset(sm, 0, sizeof sm);
        bool can = true;
        for (int i = n; i >= 1; i--) {
            if (sm[i] + a[i] > t) {
                can = false;
                break;
            }
            if (sm[i] + a[i] == t) {
                continue;
            }
            if (i == 1) {
                can = false;
                break;
            }
            sm[p[i - 1]] += (sm[i] + a[i]);
        }
        if (can) {
            f[t] = oth;
            oth++;
            ok.insert(t);
        }
    }
    for (ll x : ok) {
        //cout << x << endl;
        int id = f[x];
        dp[id] = 1;
        for (ll y : ok) {
            if (y >= x) continue;
            if (x % y == 0) dp[id] = sum(dp[id], dp[f[y]]);
        }
    }
    cout << dp[f[s]];
    return 0;
}