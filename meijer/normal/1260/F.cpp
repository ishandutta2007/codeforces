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

const ll MX=1e5+2e4, MX2=MX*2, MOD=1e9+7;
int n, l[MX], r[MX];
set<int> adj[MX], adjTemp[MX];
int sz[MX], centP[MX], centI[MX];
int H[MX], depth[MX], node[MX2], nodes=0;
int spt[MX2][20], LOG2[MX2];
ll curSum=0, totSumCent[MX], totCntCent[MX];
vll sumCent[MX], cntCent[MX];
ll mult=1, INV[MX];

ll modpow(ll x_, ll N_) {
    if(N_ == 0) return 1;
    ll a = modpow(x_,N_/2);
    a = (a*a)%MOD;
    if(N_%2) a = (a*x_)%MOD;
    return a;
}
ll inv(ll x_) {
    return modpow(x_, MOD-2);
}
ll m(ll x_) {
	return (x_+MOD)%MOD;
}
int dfsSize(int u, int p=-1) {
	sz[u] = 1;
	for(int v:adjTemp[u])
		if(v != p)
			sz[u] += dfsSize(v, u);
	return sz[u];
}
int dfsCent(int u, int p, int mxSize) {
	for(int v:adjTemp[u])
		if(v != p && sz[v] > mxSize)
			return dfsCent(v, u, mxSize);
	return u;
}
void findCentroid(int u=0, int p=-1, int i=0) {
	int compSize = dfsSize(u);
	int cent 	 = dfsCent(u,-1,compSize/2);
	centP[cent] = p;
	centI[cent] = i;
	totSumCent[cent] = totCntCent[cent] = 0;
	sumCent[cent].assign(adjTemp[cent].size(), 0);
	cntCent[cent].assign(adjTemp[cent].size(), 0);
	int j=0;
	for(int v:adjTemp[cent]) {
		adjTemp[v].erase(cent);
		findCentroid(v, cent, j++);
	}
	adjTemp[cent].clear();
}
void dfsLCA(int u=0, int p=-1, int d=0) {
	H[u] = nodes;
	depth[u] = d;
	node[nodes++] = u;
	for(int v:adj[u])
		if(v != p)
			dfsLCA(v, u, d+1), node[nodes++] = u;
}
int getMinNode(int u, int v) {
	return depth[u] < depth[v] ? u : v;
}
void fillSparseTable() {
	RE(i,nodes) spt[i][0] = node[i];
	for(int j=1; (1<<j) <= nodes; j++)
		for(int i=0; i+(1<<j)-1 < nodes; i++)
			spt[i][j] = getMinNode(spt[i][j-1], spt[i+(1<<(j-1))][j-1]);
}
int sparseQuery(int i, int j) {
	if(j < i) swap(i,j);
	int k = LOG2[j-i+1];
	return getMinNode(spt[i][k], spt[j-(1<<k)+1][k]);
}
int dist(int u, int v) {
	return depth[u]+depth[v]-2*depth[sparseQuery(H[u], H[v])];
}
void addNode(int x) {
	totCntCent[x] = m(totCntCent[x] + INV[x]);
	curSum = m(curSum + m(m(totSumCent[x]*mult)*INV[x]));

	int y = centP[x];
	int i = centI[x];
	while(y != -1) {
		ll d = dist(x, y);
		curSum = m(curSum + m(m(m(totSumCent[y] - sumCent[y][i])*mult)*INV[x]));
		curSum = m(curSum + m(m(m(m(totCntCent[y] - cntCent[y][i])*mult)*INV[x])*d));
		cntCent[y][i] = m(cntCent[y][i] + INV[x]);
		sumCent[y][i] = m(sumCent[y][i] + m(d*INV[x]));
		totCntCent[y] = m(totCntCent[y] + INV[x]);
		totSumCent[y] = m(totSumCent[y] + m(d*INV[x]));
		i = centI[y];
		y = centP[y];
	}
}
void removeNode(int x) {
	totCntCent[x] = m(totCntCent[x] - INV[x]);
	curSum = m(curSum - m(m(totSumCent[x]*mult)*INV[x]));

	int y = centP[x];
	int i = centI[x];
	while(y != -1) {
		ll d = dist(x, y);
		curSum = m(curSum - m(m(m(totSumCent[y] - sumCent[y][i])*mult)*INV[x]));
		curSum = m(curSum - m(m(m(m(totCntCent[y] - cntCent[y][i])*mult)*INV[x])*d));
		cntCent[y][i] = m(cntCent[y][i] - INV[x]);
		sumCent[y][i] = m(sumCent[y][i] - m(d*INV[x]));
		totCntCent[y] = m(totCntCent[y] - INV[x]);
		totSumCent[y] = m(totSumCent[y] - m(d*INV[x]));
		i = centI[y];
		y = centP[y];
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,n) cin>>l[i]>>r[i];
    RE(i,n) mult = (mult * (r[i]-l[i]+1))%MOD;
    RE(i,n) INV[i] = inv(r[i]-l[i]+1);
    RE(i,n-1) {
    	int a, b; cin>>a>>b; a--; b--;
    	adj[a].insert(b), adj[b].insert(a);
    }
    RE(i,n) adjTemp[i] = adj[i];
    LOG2[1]=0; REP(i,2,MX2) LOG2[i] = LOG2[i/2]+1;
    findCentroid();
    dfsLCA();
    fillSparseTable();

    priority_queue<iii, viii, greater<iii>> events;
    RE(i,n) events.push({l[i], 1, i}), events.push({r[i], 3, i});
    REP(i,1,MX) events.push({i, 2, 0});
    ll ans=0;
    while(!events.empty()) {
    	int c, q, u;
    	iii p = events.top(); events.pop();
    	tie(c,q,u) = p;
    	if(q == 1) {
    		addNode(u);
    	}
    	if(q == 2) {
    		ans = (ans + curSum)%MOD;
    	}
    	if(q == 3) {
    		removeNode(u);
    	}
    }
    cout<<ans<<endl;
}