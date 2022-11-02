#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

const int MAXN = 3005;

int n, x[MAXN];
vector<pii> adj[MAXN];
int t, sze, num, sum;
bool vis[MAXN];

void dfs(int cur) {
    if (vis[cur]) return;
    vis[cur] = 1;
    sze++;
    num += x[cur];
    for (int i=0; i<adj[cur].size(); i++)
        if (adj[cur][i].se < t)
            dfs(adj[cur][i].fi);
}

bool check(int mid) {
    t = mid;
    memset(vis, 0, sizeof(vis));
    for (int i=0; i<n; i++)
        if (!vis[i]) {
            sze = num = 0;
            dfs(i);
            if (sze > sum-num) return 0;
        }
    return 1;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back(pii(b, c));
        adj[b].push_back(pii(a, c));
    }
    for (int i=0; i<n; i++) {
        cin >> x[i];
        sum += x[i];
    }

    int lo = 0, hi = 10000;
    while (lo < hi) {
        int mid = (lo+hi+1)/2;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << '\n';
    return 0;
}