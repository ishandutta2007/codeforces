#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef long long ll;

const ll INF = 1ULL<<60ULL;
const ll DINIC_MAXN=2e5+6;
struct edge {
	ll a, b, cap, flow,extra;
};
/*
Set
dinic_numnodes: number of nodes
dinic_src: Source vertex
dinic_dest: Target vertex
Run dinic_reclear AFTER each run
*/
ll dinic_numnodes, dinic_src, dinic_dest, d[DINIC_MAXN], ptr[DINIC_MAXN], q[DINIC_MAXN];
vector<edge> dinic_edge;
vector<ll> dinic_graph[DINIC_MAXN];
void dinic_reclear() {
	dinic_edge.clear();
	for (ll i=0;i<dinic_numnodes;i++) dinic_graph[i].clear();
}
void add_edge (ll a, ll b, ll cap,ll extra) {
	edge e1 = { a, b, cap, 0,extra };
	edge e2 = { b, a, 0, 0,extra };
	dinic_graph[a].push_back ((ll) dinic_edge.size());
	dinic_edge.push_back (e1);
	dinic_graph[b].push_back ((ll) dinic_edge.size());
	dinic_edge.push_back (e2);
}

bool bfs() {
	ll qh=0, qt=0;
	q[qt++] = dinic_src;
	memset (d, -1, dinic_numnodes * sizeof d[0]);
	d[dinic_src] = 0;
	while (qh < qt && d[dinic_dest] == -1) {
		ll v = q[qh++];
		for (size_t i=0; i<dinic_graph[v].size(); ++i) {
			ll id = dinic_graph[v][i],
				to = dinic_edge[id].b;
			if (d[to] == -1 && dinic_edge[id].flow < dinic_edge[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[dinic_dest] != -1;
}
 
ll dfs (ll v, ll flow) {
	if (!flow)  return 0;
	if (v == dinic_dest)  return flow;
	for (; ptr[v]<(ll)dinic_graph[v].size(); ++ptr[v]) {
		ll id = dinic_graph[v][ptr[v]],
			to = dinic_edge[id].b;
		if (d[to] != d[v] + 1)  continue;
		ll pushed = dfs (to, min (flow, dinic_edge[id].cap - dinic_edge[id].flow));
		if (pushed) {
			dinic_edge[id].flow += pushed;
			dinic_edge[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}
 
ll dinic() {
	ll flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, dinic_numnodes * sizeof ptr[0]);
		while (ll pushed = dfs (dinic_src, INF))
			flow += pushed;
	}
	return flow;
}

const ll MAXN=1e5+4;
ll vx[MAXN],vy[MAXN];
vector<ll> bx,by;
ll bxsz,bysz;
ll xs[MAXN];
ll ys[MAXN];
ll lox[MAXN],loy[MAXN];
char ans[MAXN];
ll cx[MAXN],cy[MAXN];
ll dx[MAXN],dy[MAXN];
ll bsx(ll x) {
	ll imin=0,imax=bxsz;
	while(imin<imax) {
		ll imid=(imin+imax)/2;
		if (bx[imid]<x) imin=imid+1;
		else imax=imid;
	}
	if (bx[imin]==x) return imin;
	else return -1;
}
ll bsy(ll x) {
	ll imin=0,imax=bysz;
	while(imin<imax) {
		ll imid=(imin+imax)/2;
		if (by[imid]<x) imin=imid+1;
		else imax=imid;
	}
	if (by[imin]==x) return imin;
	else return -1;
}
ll getbd(ll n, ll d) {
	//return (n-d)/2;
	ll imin=0,imax=n+1;
	while(imin<imax) {
		ll imid=(imin+imax)/2;
		ll left=n-imid;
		if (left-imid>d) imin=imid+1;
		else imax=imid;
	}
	return imin;
}
int main() {
	ios_base::sync_with_stdio(false);
	ll n,m,r,b; scanf("%I64d %I64d %I64d %I64d",&n,&m,&r,&b);
	set<ll> sx,sy;
	for (ll i=0;i<n;i++) {
		ll x,y;
		scanf("%I64d %I64d",&x,&y);
		vx[i]=x,vy[i]=y;
		sx.insert(x); sy.insert(y);
	}
	for (auto &w:sx) bx.PB(w);
	for (auto &w:sy) by.PB(w);
	bxsz=bx.size();
	bysz=by.size();
	for (ll x=0;x<MAXN;x++) {xs[x]=0;ys[x]=0;lox[x]=0;loy[x]=0;dx[x]=INT_MAX;dy[x]=INT_MAX;}
	for (ll i=0;i<n;i++) {
		ll x=bsx(vx[i]);
		ll y=bsy(vy[i]);
		vx[i]=x; vy[i]=y;
		xs[x]++;
		ys[y]++;
		add_edge(x,y+bxsz,1,i);
	}
	ll src=bxsz+bysz;
	ll dest=bxsz+bysz+1;
	for (ll i=0;i<m;i++) {
		ll t,l,d; scanf("%I64d %I64d %I64d",&t,&l,&d);
		if (t==1) {
			ll x=bsx(l);
			if (x==-1) continue;
			chkmax(lox[x],getbd(xs[x],d));
			chkmin(dx[x],d);
		}
		else {
			ll y=bsy(l);
			if (y==-1) continue;
			chkmax(loy[y],getbd(ys[y],d));
			chkmin(dy[y],d);
		}
	}
	for (ll x=0;x<bxsz;x++) {
		ll lo=lox[x];
		ll hi=xs[x]-lo;
		add_edge(src,x,lo,-1);
	}
	for (ll y=0;y<bysz;y++) {
		ll lo=loy[y];
		ll hi=ys[y]-lo;
		add_edge(y+bxsz,dest,lo,-1);
	}
	dinic_numnodes=dest+1;
	dinic_src=src;
	dinic_dest=dest;
	dinic();
	for (ll x=0;x<bxsz;x++) {
		ll lo=lox[x];
		ll hi=xs[x]-lo;
		add_edge(src,x,max(0LL,hi-lo),-1);
	}
	for (ll y=0;y<bysz;y++) {
		ll lo=loy[y];
		ll hi=ys[y]-lo;
		add_edge(y+bxsz,dest,max(0LL,hi-lo),-1);
	}
	dinic();
	bool gored=(r<b);
	for (auto &w:dinic_edge) {
		if (w.extra!=-1&&w.a<bxsz) {
			if (w.flow==1) {
				ans[w.extra]=(gored)?'r':'b';
			}
			else {
				ans[w.extra]=(gored)?'b':'r';
			}
		}
	}
	for (ll i=0;i<MAXN;i++) {cx[i]=0;cy[i]=0;}
	for (ll i=0;i<n;i++) {
		if (ans[i]=='r') {
			cx[vx[i]]++;
			cy[vy[i]]++;
		}
	}
	for (ll i=0;i<bxsz;i++) {
		if (abs(cx[i]-(xs[i]-cx[i]))>dx[i]) {
			printf("-1\n");return 0;
		}
	}
	for (ll i=0;i<bysz;i++) {
		if (abs(cy[i]-(ys[i]-cy[i]))>dy[i]) {
			printf("-1\n");return 0;
		}
	}
	ans[n]='\0';
	ll cost=0;
	for (ll i=0;i<n;i++) {
		if (ans[i]=='r') cost+=r;
		else cost+=b;
	}
	printf("%I64d\n",cost);
	printf("%s\n",ans);
}