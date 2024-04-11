#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int n;
ll a[200010], fr[200010], dp[200010], leaf[200010];
VVI to;
void dfs(int u) {
    if (to[u].size() == 0) {
        fr[u] = 0;
        dp[u] = a[u];
        leaf[u] = 1;
        return;
    }
    ll ans = 0;
    for(int v: to[u]) {
        dfs(v);
        chmax(ans, dp[v]);
        leaf[u] += leaf[v];
    }
    ll tot_fr = 0;
    for(int v: to[u]) {
        tot_fr += fr[v] + (ans - dp[v]) * leaf[v];
    }
    if (a[u] <= tot_fr) {
        tot_fr -= a[u];
    } else {
        a[u] -= tot_fr;
        ll c = (a[u] + leaf[u] - 1) / leaf[u];
        tot_fr = c * leaf[u] - a[u];
        ans += c;
    }
    fr[u] = tot_fr;
    dp[u] = ans;
    return;
}

int main() {
    cin >> n;
    to.resize(n);
    rep(i, n-1) {
        int p;
        cin >> p;
        --p;
        to[p].push_back(i+1);
    }
    rep(i, n) cin >> a[i];
    dfs(0);
    cout << dp[0] << endl;
}