#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=300;
int n, k, a[MX], u, v;
vi adjList[MX];
vi children[MX];
int mem[MX][MX];

void dfs(int u=0, int p=-1) {
    for(int v:adjList[u])
        if(v != p)
            dfs(v, u), children[u].pb(v);
}
int getAns(int u, int i) {
    if(i < 0) i=0;
    if(mem[u][i] == -1) {
        mem[u][i] = 0;
        if(i == 0) {
            mem[u][i] = a[u];
            for(int v : children[u])
                mem[u][i] += getAns(v,k);
        }
        REP(j,k/2,k+1) {
            int cAns=0;
            vii anses;
            int sum = 0;
            for(int v : children[u]) {
                anses.pb({getAns(v,max(i-1,j)), getAns(v,max(i-1,k-j-1))});
                sum += getAns(v,max(i-1,j));
            }
            for(ii p : anses) {
                cAns = max(cAns, sum - p.first + p.second);
            }
            mem[u][i] = max(mem[u][i], cAns);
        }
    }
    return mem[u][i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    RE(i,n) cin>>a[i];
    RE(i,n-1)
        cin>>u>>v, u--, v--, adjList[u].pb(v), adjList[v].pb(u);
    dfs();
    RE(i,n) RE(j,k+2) mem[i][j] = -1;
    cout<<getAns(0,0)<<endl;
}