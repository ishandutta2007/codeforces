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
int mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=30100;
struct node {
	node *s[2];
	int s0,s1,cnt,tot;
}pool[5100000],*cur=pool,*rt;
int fib[N],a[N];
void add(int x,node *p,int dep,int k) {
	if (dep==-1) {
		p->tot+=k; 
		if (p->tot) {
			p->cnt=1; p->s0=0; p->s1=x%mod;
		} else {
			p->cnt=0; p->s0=0; p->s1=0;
		}
		return;
	}
	int w=(x>>dep)&1;
	add(x,p->s[w],dep-1,k);
	if ((!p->s[0]||p->s[0]->cnt==0)&&(!p->s[1]||p->s[1]->cnt==0)) {
		p->s0=p->s1=p->cnt=0;
	} else if (!p->s[0]||p->s[0]->cnt==0) {
		p->s0=p->s[1]->s0,p->s1=p->s[1]->s1;
		p->cnt=p->s[1]->cnt;
	} else if (!p->s[1]||p->s[1]->cnt==0) {
		p->s0=p->s[0]->s0,p->s1=p->s[0]->s1;
		p->cnt=p->s[0]->cnt;
	} else {
		int m=p->s[0]->cnt;
		p->s0=(p->s[0]->s0+fib[m-1]*p->s[1]->s0+fib[m]*p->s[1]->s1)%mod;
		p->s1=(p->s[0]->s1+fib[m]*p->s[1]->s0+fib[m+1]*p->s[1]->s1)%mod;
		p->cnt=p->s[0]->cnt+p->s[1]->cnt;
	}
} 
namespace Mo {
	const int N=201000;
	int Q,l[N],r[N],f[N],l0,r0,ans[N],n;
	VI ne[N];
	struct point {
		int x, y, o;
		point(int a, int b, int c): x(a), y(b), o(c) {}
	};
	inline bool operator<(const point &a, const point &b) {
		if (a.x != b.x) return a.x > b.x;
		else return a.y < b.y;
	}
	vector<point> p;
	struct edge {
		int s, t, d;
		edge(const point &a, const point &b): s(a.o), t(b.o),
			d(abs(a.x - b.x) + abs(a.y - b.y)) {}
	};
	inline bool operator<(const edge &a, const edge &b) {return a.d < b.d;}
	vector<edge> e;
	int g[N],z[N];
	void addedge() {
		sort(all(p));
	    memset(g,0,sizeof(g));
	    z[0]=N;
		rep(i,0,SZ(p)) z[i+1]=p[i].x-p[i].y;
		rep(i,0,SZ(p)) {
	        int k = 0, t = p[i].x + p[i].y;
	        for (int j = t; j; j -= j & -j)
	            if (z[g[j]] < z[k]) k = g[j];
	        if (k) e.pb(edge(p[i], p[k - 1]));
	        k = z[i + 1];
	        for (int j = t; j <N; j += j & -j)
	            if (k < z[g[j]]) g[j] = i + 1;
	    }
	}
	void updata(int i, bool j,bool k=0) {
		// j=1 insert  j=0 delete
		// k=0 left k=1 right
	//	printf("Modify %d %d\n",i,j);
		if (j==1) add(a[i],rt,30,1); else add(a[i],rt,30,-1);
	}
	void init(int l,int r) {
		rep(i,l,r+1) updata(i,1);
	}
	inline int query() {
		return rt->s1;
	}
	int find(int x) { if (f[x] != x) f[x] = find(f[x]); return f[x];}
	void dfs(int i,int p) {
		int l1 = l[i], r1 = r[i];
		per(j,l1,l0) updata(j,1,0);
		rep(j,r0+1,r1+1) updata(j,1,1);
		rep(j,l0,l1) updata(j,0,0);
		per(j,r1+1,r0+1) updata(j,0,1);
		ans[i]=query();l0=l1;r0=r1;
		rep(j,0,SZ(ne[i])) if (ne[i][j]!=p) dfs(ne[i][j],i);
	}
	void solve() {
		p.clear();e.clear();
		rep(i,1,Q+1) ans[i]=0;
		rep(i,1,Q+1) p.pb(point(l[i],r[i],i));
		addedge();
		rep(i,0,SZ(p)) p[i].y =n-p[i].y+1;
		addedge();
		rep(i,0,SZ(p)) {
			int j =n-p[i].x+1;
			p[i].x = p[i].y; p[i].y = j;
		}
		addedge();
		rep(i,0,SZ(p)) p[i].x=n-p[i].x+1;
		addedge();
		sort(all(e));
		rep(i,1,Q+1) ne[i].clear(),f[i]=i;
		rep(i,0,SZ(e)) {
			int j=e[i].s,k=e[i].t;
			if (find(j)!=find(k)) f[f[j]]=f[k],ne[j].pb(k),ne[k].pb(j);
		}
		l0=l[1];r0=r[1];
		init(l0,r0);
		dfs(1,0);
	}
};

using namespace Mo;
int main() {
//	freopen("H.in","r",stdin);
	scanf("%d%d",&n,&mod);
	fib[0]=0; fib[1]=1;
	rep(i,2,n+1) fib[i]=(fib[i-1]+fib[i-2])%mod;
	rt=cur++;
	rep(i,1,n+1) {
		node *p=rt;
		scanf("%d",a+i);
		for (int j=30;j>=0;j--) {
			int w=(a[i]>>j)&1;
			if (!p->s[w]) p->s[w]=cur++;
			p=p->s[w];
		}
	}
	scanf("%d",&Q);
	rep(i,1,Q+1) scanf("%d%d",l+i,r+i);
	solve();
	rep(i,1,Q+1) printf("%d\n",ans[i]);
}