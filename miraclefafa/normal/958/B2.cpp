#include <bits/stdc++.h>
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
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
struct ele {
	int u,pre;
};
priority_queue<ele> q;
int dep[N],p[N],f[N],u[N],v[N],ret[N],d[N],spe[N],od[N],tot,n,m,Q,k;
VI e[N];
bool operator < (const ele &x,const ele &y) {
	return dep[x.u]-dep[x.pre]>dep[y.u]-dep[y.pre];
}
int find(int x) { return f[x]==x?x:f[x]=find(f[x]);}
void dfs1(int u,int f) {
	dep[u]=dep[f]+1; p[u]=f;
	rep(j,0,SZ(e[u])) {
		int v=e[u][j];
		if (v!=f) dfs1(v,u);
	}
}
int main() {
	scanf("%d",&n);
	m=n-1;
	rep(i,1,n+1) f[i]=i;
	rep(i,0,n-1) {
		scanf("%d%d",u+i,v+i);
		if (find(u[i])!=find(v[i])) {
			e[u[i]].pb(v[i]);
			e[v[i]].pb(u[i]);
			f[find(u[i])]=find(v[i]);
		} else spe[i]=1;
	}
	dfs1(1,0);
	rep(i,1,n+1) f[i]=i;
	rep(i,0,m) if (spe[i]) {
		int x=find(u[i]),y=find(v[i]);
		while (x!=y) {
			if (dep[x]<dep[y]) swap(x,y);
			f[x]=find(p[x]);
			x=f[x];
		}
	}
	rep(i,1,n+1) e[i].clear();
	rep(i,1,n+1) if (find(i)==i) od[i]=++tot;
	rep(i,2,n+1) if (find(i)==i) {
		int x=od[i],y=od[find(p[i])];
		e[x].pb(y); e[y].pb(x);
	}
	n=tot;
	dfs1(1,0);
	int cen=max_element(dep+1,dep+n+1)-dep;
	dfs1(cen,0);
	cen=max_element(dep+1,dep+n+1)-dep;
	int len=dep[cen];
	rep(i,0,len/2) cen=p[cen];
	dfs1(cen,0);
	e[cen].pb(0); e[0].pb(cen);
	rep(i,1,n+1) { d[i]=SZ(e[i])-1; f[i]=i;} 
	rep(i,1,n+1) if (d[i]<2) f[i]=p[i];
	rep(i,1,n+1) if (d[i]==0) q.push((ele){i,find(i)});
	m=SZ(q);
//	printf("%d\n",m);
	ret[SZ(q)]=n-1;
	while (!q.empty()) {
		ele l=q.top(); q.pop();
		int u=l.u,pre=l.pre;
		if (find(u)!=pre) q.push((ele){u,find(u)});
		else {
			ret[SZ(q)]=ret[SZ(q)+1]-(dep[u]-dep[pre]);
			if ((--d[pre])<2&&pre!=cen) f[pre]=p[pre];
		}
	}
	printf("1");
	rep(i,2,n+1) printf(" %d",ret[min(i,m)]+1);
	puts("");
}