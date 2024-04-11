#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(ll a=ll(c-1); a>=ll(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const ll MX=3e5;
ll n, m, w[MX], a, b, s;
vi adjList[MX];
bitset<MX> visited;
bitset<MX> perm;
ll par[MX];
ll mem[MX];

bool dfs(ll u, ll p) {
    if(perm[u])
        return 1;
    if(visited[u])
        return perm[u] = 1;
    visited[u] = 1;
    par[u] = p;
    for(ll v:adjList[u])
        if(v != p)
            if(dfs(v, u))
                perm[u] = 1;
    visited[u] = 0;
    return perm[u];
}
ll getMax(ll u, ll p) {
    if(mem[u] == -1) {
        if(perm[u]) return mem[u]= 0;
        return mem[u]=w[u]+getMax(par[u], u);
    }
    return mem[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    RE(i,n) cin>>w[i];
    RE(i,m) cin>>a>>b, a--, b--, adjList[a].pb(b), adjList[b].pb(a);
    cin>>s; s--;
    visited.reset(); perm.reset();
    dfs(s, -1);
    perm[s] = 1;
    ll ans=0;
    RE(i,n) mem[i] = -1;
    RE(i,n) {
        if(!perm[i] && adjList[i].size() == 1) {
            ans = max(ans, getMax(i, -1));
        }
    }
    RE(i,n)
        if(perm[i])
            ans += w[i];
    cout<<ans<<endl;
}