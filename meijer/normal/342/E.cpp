#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=1e5+1e4, MX2=MX*2, MOD=1e9+7;
int n, m, a, b;
set<int> adj[MX], adjTemp[MX];
int parentCent[MX];
int sz[MX];
int node[MX2], depth[MX], H[MX], curNode=0, spt[MX2][19];
int LOG2[MX2];
int ans[MX];

int dfsSZ(int u, int p=-1) {
	sz[u] = 1;
	for(int v:adjTemp[u])
		if(v != p)
			sz[u] += dfsSZ(v, u);
	return sz[u];
}
int dfsCent(int u, int p, int mxSize) {
	for(int v:adjTemp[u])
		if(v != p && sz[v] > mxSize)
			return dfsCent(v, u, mxSize);
	return u;
}
void decompose(int u, int p=-1) {
	int subSize = dfsSZ(u);
	int cent 	= dfsCent(u,-1,subSize/2);
	parentCent[cent] = p;
	for(int v:adjTemp[cent]) {
		adjTemp[v].erase(cent);
		decompose(v, cent);
	}
	adjTemp[cent].clear();
}
void dfsLCA(int u=0, int p=-1, int d=0) {
	H[u] = curNode;
	depth[u] = d;
	node[curNode++] = u;
	for(int v:adj[u])
		if(v != p)
			dfsLCA(v,u,d+1), node[curNode++]=u;
}
int minNode(int u, int v) {
	return depth[u] < depth[v] ? u : v;
}
void fillSparse() {
	RE(i,curNode)
		spt[i][0] = node[i];
	for(int j=1; (1<<j) <= curNode; j++)
		for(int i=0; i+(1<<j)-1 < curNode; i++)
			spt[i][j] = minNode(spt[i][j-1], spt[i+(1<<(j-1))][j-1]);
}
int query(int i, int j) {
	if(j < i) swap(i,j);
	int k=LOG2[j-i+1];
	return minNode(spt[i][k], spt[j-(1<<k)+1][k]);
}
int dist(int u, int v) {
	return depth[u] + depth[v] - 2*depth[query(H[u], H[v])];
}
void update(int x) {
	int y = x;
	while(y != -1) {
		ans[y] = min(ans[y], dist(x,y));
		y = parentCent[y];
	}
}
int query(int x) {
	int y = x;
	int ANS = INF;
	while(y != -1) {
		ANS = min(ANS, dist(x, y)+ans[y]);
		y = parentCent[y];
	}
	return ANS;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    RE(i,n-1) cin>>a>>b, a--, b--, adj[a].insert(b), adj[b].insert(a);
    RE(i,n) adjTemp[i] = adj[i];
    LOG2[1]=0; REP(i,2,MX2) LOG2[i] = LOG2[i/2]+1;
    decompose(0);
    dfsLCA();
    fillSparse();
    RE(i,n) ans[i] = INF;
    update(0);

    RE(i,m) {
    	cin>>a>>b; b--;
    	if(a == 1) {
    		update(b);
    	} else {
    		cout<<query(b)<<endl;
    	}
    }
}