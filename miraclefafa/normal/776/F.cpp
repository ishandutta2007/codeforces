#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=1001000;
int n,m,x,y,fcnt,Q,ouf,u,v,p[N],rk[N];
struct edge {
	edge *pre,*nxt,*op;
	int id,sp,sr; // sp start
	bool fg;
}e[N];
//map<int,edge*> eg[V];

bool cmp(edge* a,edge* b) {
	return a->sr<b->sr;
}

struct point {
	vector<edge*> e;
}pnt[N];
vector<edge*> f[N];
VI id[N];
bool cmpp(int a,int b) {
	return id[a]<id[b];
}

void add(int x,int y,int p) {
	e[p].op=e+p+m;
	e[p].sp=x;
	e[p].sr=(y-x+m)%m;
	e[p+m].op=e+p;
	e[p+m].sp=y;
	e[p+m].sr=(x-y+m)%m;
	pnt[x].e.pb(e+p);
	pnt[y].e.pb(e+p+m);
}
void init() {
	scanf("%d%d",&n,&m);
	if (m==0) {
		puts("1"); exit(0);
	}
	int cntm=0;
	m+=n;
	rep(i,0,n) add(i+1,(i+1)%n+1,cntm++);
	rep(i,0,m-n) {
		scanf("%d%d",&u,&v);
		add(u,v,cntm++);
	}
	rep(i,1,n+1) {
		sort(all(pnt[i].e),cmp);
		for (vector<edge*>::iterator pr=--pnt[i].e.end(),nt=pnt[i].e.begin();nt!=pnt[i].e.end();pr=nt++)
			(*pr)->nxt=*nt,(*nt)->pre=(*pr);
	}
	per(i,1,n+1) rep(j,0,SZ(pnt[i].e)) if (!pnt[i].e[j]->fg) {
		fcnt++;
		edge *cure=pnt[i].e[j];
		while (!cure->fg) {
			cure->fg=1;
			cure->id=fcnt;
			f[fcnt].pb(cure);
			id[fcnt].pb(cure->sp);
			x=cure->sp,y=cure->op->sp;
			cure=cure->op->nxt;
		}
		if (SZ(f[fcnt])==n) {
			for (auto p:f[fcnt]) p->id=-1;
			f[fcnt].clear(); id[fcnt].clear(); --fcnt;
		}
	}
	rep(i,1,fcnt+1) {
		p[i]=i;
		sort(all(id[i])); reverse(all(id[i]));
	}
	sort(p+1,p+fcnt+1,cmpp);
	rep(i,1,fcnt+1) rk[p[i]]=i;
}

VI E[N];
int q[N],fa[N],vis[N],sz[N],ms[N],col[N];
int find(int u) {
	int t=1;q[0]=u;fa[u]=-1;
	rep(i,0,t) {
		u=q[i];
		rep(j,0,E[u].size()) {
			int v=E[u][j];
			if (!vis[v]&&v!=fa[u]) fa[q[t++]=v]=u;
		}
		ms[q[i]]=0;
		sz[q[i]]=1;
	}
	for (int i=t-1;i>=0;i--) {
		ms[q[i]]=max(ms[q[i]],t-sz[q[i]]);
		if (ms[q[i]]*2<=t) return q[i];
		sz[fa[q[i]]]+=sz[q[i]];
		ms[fa[q[i]]]=max(ms[fa[q[i]]],sz[q[i]]);
	}
	return 0;
}
void solve(int u,int dep) {
	u=find(u);
	col[u]=dep; vis[u]=1;
	for (auto v:E[u]) if (!vis[v]) solve(v,dep+1);
}
int main() {
	init();
	rep(p,0,m) {
		if (e[p].id==-1||e[p+m].id==-1) continue;
		u=rk[e[p].id],v=rk[e[p+m].id];
		E[u].pb(v); E[v].pb(u);
	}
	solve(u,1);
	rep(i,1,fcnt+1) printf("%d ",col[i]);
}