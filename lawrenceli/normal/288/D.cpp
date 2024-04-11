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

const int MAXN = 80100;

int n;
vector<int> adj[MAXN];
ll sub[MAXN], dp[MAXN], ans;

ll c2(ll x) { return x*(x-1)/2; }
ll sq(ll x) { return x*x; }

void dfs(int cur, int p=-1) {
    sub[cur] = 1;
    ll a=0, b=0, c=0, d=0, e=0;
    rep(i, adj[cur].size()) {
        int nxt = adj[cur][i];
        if (nxt == p) continue;
        dfs(nxt, cur);
        sub[cur] += sub[nxt], dp[cur] += dp[nxt]-sub[nxt]*c2(sub[nxt]);
        a += c2(sub[nxt]), b += dp[nxt], c += sq(sub[nxt]), d += c2(sub[nxt])*sub[nxt], e += c2(sub[nxt])*sq(sub[nxt]);
        ans -= dp[nxt]*sub[nxt];
    }
    dp[cur] += a*sub[cur];
    ans += dp[cur]-a+b*(sub[cur]-1)+(sub[cur]-1+(sq(sub[cur]-1)-c)/2)*c2(n-sub[cur])+((sq(sub[cur]-1)-c)*a)/2-d*(sub[cur]-1)+e;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0);
    cout << ans << '\n';
    return 0;
}