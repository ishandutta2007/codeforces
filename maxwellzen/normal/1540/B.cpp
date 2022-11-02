#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
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

ll MOD = 1e9+7;
ll mod_exp(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b&1) r = (r*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }
    return r;
}

ll inv(ll a) {
    return mod_exp(a, MOD-2);
}

int n, a, b, tim=0, ldep;
const int nodes=201;
vi st, ed;
vector<vi> adj, up;
vector<vll> dist;
ll half = inv(2), ninv=inv(n), expval[nodes][nodes];

void dfs(int i, int parent) {
    up[i][0]=parent;
    st[i]=tim;
    tim++;
    for (int nb : adj[i]) {
        if (nb!=parent) dfs(nb, i);
    }
    ed[i]=tim-1;
}

bool anc(int i, int j) {
    return st[i]<=st[j] && ed[i]>=ed[j];
}

int lca(int i, int j) {
    if (anc(j, i)) return j;
    if (anc(i, j)) return i;
    for (int d = ldep-1; d >= 0; d--) {
        if (! anc(up[i][d], j)) i=up[i][d];
    }
    return up[i][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    FOR(i, 1, nodes) {expval[0][i]=1; expval[i][0]=0;}
    FOR(i, 1, nodes) FOR(j, 1, nodes) expval[i][j]=(half*expval[i-1][j] + half*expval[i][j-1])%MOD;
    cin >> n;
    adj.rsz(n);
    dist.rsz(n, vll(n, 1000));
    F0R(i, n) dist[i][i]=0;
    F0R(i, n-1) {
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
        dist[a][b]=1;
        dist[b][a]=1;
    }
    F0R(k, n) F0R(i, n) F0R(j, n) dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
    st.rsz(n), ed.rsz(n);
    while (pow(2, ldep) <= n) ldep++;
    ldep++;
    up.rsz(n, vi(ldep));
    ll ans = 0;
    F0R(root, n) {
        dfs(root, root);
        for (int i = 1; i < up[0].size(); i++) {
            for (int j = 0; j < n; j++) {
                up[j][i] = up[up[j][i-1]][i-1];
            }
        }
        F0R(i, n) F0R(j, i) {
            int com = lca(i, j);
            ans += expval[dist[i][com]][dist[j][com]];
            ans %= MOD;
        }
    }
    ans *= inv(n);
    ans %= MOD;
    cout << ans << '\n';
}