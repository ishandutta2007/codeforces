#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;
typedef vector<pair<int,int>> vpi;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define pi pair<int, int>
#define mp make_pair
#define F first
#define S second

int t, n, m, a, b;
vvi adj;
vb vis;
vi cycle;
vi ans;

void detect(int i) {
    vis[i]=true;
    for (int nb : adj[i]) if (vis[nb]) cycle[nb]=1; else if (cycle[nb]==0) detect(nb);
    if (cycle[i]==0) cycle[i]=-1;
    vis[i]=false;
}

void extend(int i) {
    for (int nb : adj[i]) if (cycle[nb]==-1) {
        cycle[nb]=1;
        extend(nb);
    }
}

void dfs2(int i) {
    if (cycle[i]==1) return;
    for (int nb : adj[i]) if (ans[nb] != 2) {
        ans[nb]=2;
        dfs2(nb);
    }
}

void dfs(int i) {
    if (cycle[i]==1) return;
    if (ans[i]==1) {
        ans[i]=2;
        dfs2(i);
    } else if (ans[i]==0) {
        ans[i]=1;
        for (int nb : adj[i]) dfs(nb);
    }
}
 
void solve() {
    cin >> n >> m;
    adj.clear();
    adj.rsz(n);
    F0R(i, m) {
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
    }
    vis.clear();
    vis.rsz(n, false);
    cycle.clear();
    cycle.rsz(n, 0);
    detect(0);
    F0R(i, n) if (cycle[i]==1) extend(i);
    ans.clear();
    ans.rsz(n, 0);
    dfs(0);
    F0R(i, n) if (cycle[i]==1) cout << -1 << ' ';
    else cout << ans[i] << ' ';
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}