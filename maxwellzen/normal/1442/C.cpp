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

int n, m, a, b;
ll MOD = 998244353;
vll two;

bool lesser(pi p, pi q) {
    if (p.S==q.S) return p.F<q.F;
    if (max(p.S, q.S)>20) return p.S<q.S;
    return p.F+two[p.S]<q.F+two[q.S];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vi adj[n][2];
    pi dist[n][2];
    bool vis[n][2], cont=true;
    set<int> track;
    priority_queue<pi, vpi, greater<pi>> pq;
    F0R(i, m) {
        cin >> a >> b;
        a--; b--;
        adj[a][0].pb(b);
        adj[b][1].pb(a);
    }
    F0R(i, n) F0R(j, 2) {dist[i][j]=mp(-1,-1); vis[i][j]=false;}
    int iteration=0;
    two.rsz(n+2);
    two[0]=0;
    two[1]=1;
    FOR(i, 2, n+2) two[i]=(two[i-1]*2)%MOD;
    FOR(i, 2, n+2) two[i]=(two[i]+two[i-1])%MOD;
    dist[0][0]=mp(0,0);
    track.insert(0);
    while (cont) {
        cont=false;
        int w = iteration%2;
        for (int i : track) pq.push(mp(dist[i][w].F, i));
        track.clear();
        while (! pq.empty()) {
            pi cur = pq.top();
            pq.pop();
            int u = cur.S;
            if (vis[u][w]) continue;
            vis[u][w]=true;
            if (dist[u][1-w].F==-1 || lesser(mp(dist[u][w].F, iteration+1), dist[u][1-w])) {
                track.insert(u);
                dist[u][1-w] = mp(dist[u][w].F, iteration+1);
                vis[u][1-w]=false;
                cont=true;
            }
            for (int nb : adj[u][w]) {
                if (dist[nb][w].F==-1 || lesser(mp(dist[u][w].F+1, iteration), dist[nb][w])) {
                    dist[nb][w] = mp(dist[u][w].F+1, iteration);
                    pq.push(mp(dist[nb][w].F, nb));
                    vis[nb][w]=false;
                    cont=true;
                }
            }
        }
        iteration++;
    }
    // F0R(j, 2) {
    //     F0R(i, n) cout << dist[i][j].F << ' ' << dist[i][j].S << '\n';
    //     cout << '\n';
    // }
    if (dist[n-1][0].F==-1 || (dist[n-1][1].F != -1 && lesser(dist[n-1][1], dist[n-1][0])))
        cout << (dist[n-1][1].F+two[dist[n-1][1].S])%MOD << '\n';
    else 
        cout << (dist[n-1][0].F+two[dist[n-1][0].S])%MOD << '\n';
}