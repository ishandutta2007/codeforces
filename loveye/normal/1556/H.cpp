#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair

const int N = 55,K = 10,INF = 0x3f3f3f3f,M = N * N;
int n,k,d[N],a[N];
int tot;
struct Edge {int u,v,w;} e[M];
typedef vector<Edge> vec;
struct DSU {
	int f[N],cps;
	void init(int n) {fr(i,1,n) f[i] = i; cps = n;}
	int getf(int x) {return f[x] == x ? x : f[x] = getf(f[x]);}
	int ncnt(int x,int y) {return getf(x) != getf(y);}
	int merge(int x,int y) {
		x = getf(x),y = getf(y);
		return x == y ? 0 : (f[x] = y,--cps,1);
	}
} dsu;

vec e1,e2;
int vis[M],m,X[M][2],pre[M];
#define wet(i) (vis[i] ? -e1[i-1].w : e1[i-1].w)
namespace Graph {
	bool in[M]; pii dis[M];
	int to[M*N],fir[M],eds,nxt[M*N];
	void addedge(int u,int v) {
		to[++eds] = v;
		nxt[eds] = fir[u];
		fir[u] = eds;
		//cout << u << ' ' << v << endl;
	}
	void reset() {fr(i,1,m) fir[i] = 0; eds = 0;}
	void SPFA() {
		queue<int> q;
		fr(i,1,m) {
			pre[i] = 0;
			if(X[i][0]) q.push(i),dis[i] = mp(0,0),in[i] = 1;
			else dis[i] = mp(INF,INF),in[i] = 0;
		}
		while(!q.empty()) {
			int u = q.front(); q.pop(); in[u] = 0;
			pii tmp(dis[u].fi + wet(u),dis[u].se + 1);
			foredge(i,u,v) if(dis[v] > tmp) {
				pre[v] = u,dis[v] = tmp;
				if(!in[v]) q.push(v),in[v] = 1;
			}
		}
	}
} using namespace Graph;

void build0() {
	dsu.init(n);
	for(auto e : e2) dsu.merge(e.u,e.v);
	fr(i,1,m) if(vis[i]) dsu.merge(e1[i-1].u,e1[i-1].v);
	fr(i,1,m) if(!vis[i] && dsu.ncnt(e1[i-1].u,e1[i-1].v)) X[i][0] = 1;
	fr(i,1,m) if(vis[i]) {
		dsu.init(n);
		for(auto e : e2) dsu.merge(e.u,e.v);
		fr(j,1,m) if(vis[j] && i != j) dsu.merge(e1[j-1].u,e1[j-1].v);
		fr(j,1,m) if(!vis[j] && dsu.ncnt(e1[j-1].u,e1[j-1].v))
			addedge(i,j);
	}
}
void update(Edge &e,int d) {if(e.u <= k) a[e.u] += d; if(e.v <= k) a[e.v] += d;}
int chk(Edge &e) {return (e.u > k || a[e.u] < d[e.u]) && (e.v > k || a[e.v] < d[e.v]);}
void build1() {
	fr(i,1,m) if(vis[i]) update(e1[i-1],1);
	fr(i,1,m) if(!vis[i] && chk(e1[i-1])) X[i][1] = 1;
	fr(i,1,m) if(vis[i]) {
		update(e1[i-1],-1);
		fr(j,1,m) if(!vis[j] && chk(e1[j-1])) addedge(j,i);
		update(e1[i-1],1);
	}
	fr(i,1,m) if(vis[i]) update(e1[i-1],-1);
}

int augment() {
	memset(X,0,sizeof X);
	reset(); build0(); build1(); SPFA();
	int id = -1;
	fr(i,1,m) if(X[i][1]) {
		dis[i].fi += wet(i);
		if(id == -1 || dis[i] < dis[id]) id = i;
	} if(id == -1 || dis[id].fi > INF/2) return INF;
	for(int i = id;i;i = pre[i]) vis[i] ^= 1;
	return dis[id].fi;
}
int matroid_intersection(vec &e1,vec &e2) {
	m = e1.size(); ::e1 = e1; ::e2 = e2;
	int res = 0;
	fr(i,1,m) vis[i] = 0;
	fo(i,1,n-e2.size()) {
		//cout << '!' << endl;
		int dlt = augment();
		if(dlt == INF) return INF;
		res += dlt;
	} return res;
}//e2

vec E1,E2,E3,tmp;
int main() {
	scanf("%d%d",&n,&k);
	fr(i,1,k) scanf("%d",d+i);
	fr(i,1,n) fr(j,i+1,n) {
		++tot,scanf("%d",&e[tot].w),e[tot].u = i,e[tot].v = j;
		if(j <= k) E1.push_back(e[tot]);
		else if(i > k) tmp.push_back(e[tot]);
		else E2.push_back(e[tot]);
	}
	sort(tmp.begin(),tmp.end(),[](const Edge &a,const Edge &b) {return a.w < b.w;});
	dsu.init(n);
	for(auto e : tmp) if(dsu.merge(e.u,e.v)) E2.push_back(e);
	int out = INF;
	fo(s,0,1 << E1.size()) {
		E3.clear();
		int ok = 1;
		dsu.init(n);
		fr(i,1,n) a[i] = 0;
		int res = 0;
		fo(i,0,E1.size()) if(s >> i & 1) {
			if(!dsu.merge(E1[i].u,E1[i].v)) {ok = 0; break;}
			E3.push_back(E1[i]); res += E1[i].w;
			++a[E1[i].u]; ++a[E1[i].v];
		}
		fr(i,1,k) if(a[i] > d[i]) {ok = 0; break;}
		if(!ok) continue;
		out = min(out,matroid_intersection(E2,E3) + res);
	}//E3\subset E1
	printf("%d\n",out);
	return 0;
}