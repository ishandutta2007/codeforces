#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

const int MAXN = 100100;

int n;
vector<pii> adj[MAXN];
int sub[MAXN], sum[MAXN];
ll dp[MAXN];

bool cmp(pii p1, pii p2) {
    return ll(p1.fi)*p2.se < ll(p2.fi)*p1.se;
}

void dfs(int cur, int p=-1) {
    sub[cur] = 1;
    vector<pii> v;
    rep(i, adj[cur].size()) {
        int nxt = adj[cur][i].fi, d = adj[cur][i].se;
        if (nxt == p) continue;
        dfs(nxt, cur);
        sub[cur] += sub[nxt];
        sum[cur] += sum[nxt] + adj[cur][i].se;
        v.push_back(pii(2*(sum[nxt]+adj[cur][i].se), sub[nxt]));
        dp[cur] += dp[nxt]+adj[cur][i].se*sub[nxt];
    }
    sort(v.begin(), v.end(), cmp);
    ll x = 0;
    rep(i, v.size()) {
        dp[cur] += ll(v[i].se)*x;
        x += v[i].fi;
    }
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    rep(i, n-1) {
        int a, b, t;
        cin >> a >> b >> t;
        a--, b--;
        adj[a].push_back(pii(b, t));
        adj[b].push_back(pii(a, t));
    }

    dfs(0);
    cout << fixed << setprecision(10) << (long double)(dp[0])/(n-1) << '\n';
    return 0;
}