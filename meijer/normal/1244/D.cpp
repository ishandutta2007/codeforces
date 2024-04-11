#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e18
#define pb push_back
#define fi first
#define se second

const int MX=1e5;
ll n, c[3][MX], u, v;
vi adjList[MX];
ll anses[MX][3];
ll ansCol[MX];

ll getCost(ll u, ll p, ll col) {
    if(col == 3) col = 0;
    for(int v:adjList[u])
        if(v != p)
            return c[col][u] + getCost(v,u,col+1);
    return c[col][u];
}
void fillAns(ll u, ll p, ll col) {
    if(col == 3) col = 0;
    ansCol[u] = col+1;
    for(int v:adjList[u])
        if(v != p)
            fillAns(v,u,col+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,3) RE(j,n) cin>>c[i][j];
    RE(i,n-1) cin>>u>>v, u--, v--, adjList[u].pb(v), adjList[v].pb(u);
    RE(i,n) {
        if(adjList[i].size() > 2) {
            cout<<-1<<endl;
            return 0;
        }
    }
    ll ans=INF;
    RE(i,n) {
        if(adjList[i].size() == 1) {
            RE(j,3) anses[i][j] = getCost(i,-1,j);
            RE(j,3) ans = min(ans, anses[i][j]);
        }
    }
    cout<<ans<<endl;
    RE(l,n) {
        if(adjList[l].size() == 1) {
            RE(i,3) {
                if(anses[l][i] == ans){
                    fillAns(l, -1, i);
                    RE(j,n) cout<<(j==0?"":" ")<<ansCol[j];
                    cout<<endl;
                    return 0;
                }
            }
        }
    }
}