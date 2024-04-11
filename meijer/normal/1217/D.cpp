#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX=5100;
ll n, m, u, v;
vi adjList[MX];
ll dfsNum[MX], dfsLow[MX], S[MX];
ll dfsCount=0;
bitset<MX> visited;
bitset<MX> col;
bool cycle=0;

void scc(int u) {
    dfsLow[u] = dfsNum[u] = dfsCount++;
    visited[u] = 1;
    REP(i,0,adjList[u].size()) {
        int v=adjList[u][i];
        if(dfsNum[v] == -1) scc(v);
        if(visited[v]) {
            if(dfsLow[v] < dfsLow[u])
                cycle = 1;
        }
    }
    visited[u] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    REP(i,0,m) cin>>u>>v, adjList[u-1].push_back(v-1), col[i]=u<v;
    REP(i,0,n) dfsNum[i]=-1, dfsLow[i]=0;
    visited.reset();
    REP(i,0,n)
        if(dfsNum[i] == -1)
            scc(i);
    if(cycle == 0) {
        cout<<1<<endl;
        cout<<1;
        REP(i,1,m) cout<<" 1";
        cout<<endl;
    } else {
        cout<<2<<endl;
        REP(i,0,m) {
            if(i!=0) cout<<" ";
            cout<<(int)col[i]+1;
        }
        cout<<endl;
    }
}