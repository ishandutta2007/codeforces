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

int n, m, a[MAXN];
vector<int> adj[MAXN];
ll sum, ans;

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    rep(i, m) {
        cin >> a[i];
        if (i>0) sum += abs(a[i]-a[i-1]);
    }
    ans = sum;
    rep(i, m) {
        for (int d=-1; d<=1; d+=2) {
            int j = d+i;
            if (j<0 || j>=m) continue;
            if (a[i] != a[j])
                adj[a[i]].push_back(a[j]);
        }
    }

    for (int i=1; i<=n; i++) {
        if (adj[i].empty()) continue;
        sort(adj[i].begin(), adj[i].end());
        int x = adj[i][sz(adj[i])/2];
        ll cur = sum;
        rep(j, adj[i].size())
            cur += abs(adj[i][j]-x)-abs(adj[i][j]-i);
        ans = min(ans, cur);
    }

    cout << ans << '\n';
    return 0;
}