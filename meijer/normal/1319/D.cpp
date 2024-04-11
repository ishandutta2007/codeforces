#include <bits/stdc++.h>

using namespace std;

#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,b) REP(a,0,b)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int MX = 3e5, MOD=1e9+7;
int n, m, k, p[MX], t;
vi adj[MX];
int ways[MX], dist[MX];
set<int> nxt[MX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    RE(i,m) {
        int u, v; cin>>u>>v; u--; v--;
        adj[v].pb(u);
    }
    cin>>k;
    RE(i,k) cin>>p[i], p[i]--;
    t = p[k-1];
    RE(i,n) dist[i]=INF; dist[t]=0;
    RE(i,n) ways[i]=0; ways[t]=1;
    queue<int> q; q.push(t);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v:adj[u]) {
            if(dist[v] == INF) {
                dist[v] = dist[u]+1;
                ways[v] = 1;
                q.push(v);
                nxt[v].insert(u);
            } else if(dist[v] == dist[u]+1) {
                ways[v]++;
                nxt[v].insert(u);
            }
        }
    }
    int mn=0, mx=0;
    RE(i,k-1) {
        if(!nxt[p[i]].count(p[i+1])) {
            mn++; mx++;
        } else if(ways[p[i]] > 1) {
            mx++;
        }
    }
    cout<<mn<<" "<<mx<<endl;
    return 0;
}