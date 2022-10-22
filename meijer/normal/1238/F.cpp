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

const int MX=4e5;
int q, n, x, y;
vi adjList[MX];
vi c[MX];
int mem[MX][2];

ii pushPair(ii p, int v) {
    return ii(max(p.first, v), max(p.second, min(v, p.first)));
}
void dfs(int u, int p) {
    for(int v:adjList[u])
        if(v != p)
            dfs(v, u), c[u].pb(v);
}
int getAns(int u, bool p) {
    if(mem[u][p] == -1) {
        ii best={0,0};
        for(int v:c[u])
            best = pushPair(best, getAns(v,1));
        if(p) {
            mem[u][p] = 1 + best.first + max(0, (int)c[u].size()-1);
        } else {
            mem[u][p] = 1 + best.first + best.second + max(0, (int)c[u].size()-2);
        }
    }
    return mem[u][p];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    while(q--) {
        cin>>n;
        RE(i,n) adjList[i].clear();
        RE(i,n) c[i].clear();
        RE(i,n-1) cin>>x>>y, x--, y--, adjList[x].pb(y), adjList[y].pb(x);
        dfs(0,-1);
        RE(i,n) mem[i][0]=mem[i][1]=-1;
        int ans=0;
        RE(i,n) {
            ans = max(ans, getAns(i, 0) + (i==0? 0 : 1));
        }
        cout<<ans<<endl;
    }
}