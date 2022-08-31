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

const int M=201000;
const int N=10000000;

int l[M],dep[M],r[M],VV,Q,tot,p[M][20],q,mm[M*2];
VI e[M];

int fst[N+100],y[M*2],nxt[M*2];
PII vec[M*2];
int que[M*2];
ll ret[M];

void dfs(int u,int f) {
	l[u]=++tot;
	p[u][0]=f;
	dep[u]=dep[f]+1;
	rep(j,0,SZ(e[u])) if (e[u][j]!=f)
		dfs(e[u][j],u);
	r[u]=tot;
}

#define LOGN 18
int lca(int u,int v) {
	if (dep[u]>dep[v]) swap(u,v);
	per(i,0,LOGN) if (dep[p[v][i]]>=dep[u]) v=p[v][i];
	if (u==v) return u;
	per(i,0,LOGN) if (p[v][i]!=p[u][i]) u=p[u][i],v=p[v][i];
	return p[u][0];
}

int pr[N/5],pp[N+100];
bool mark[N+100];

void add(int u,int v) {
	tot++;y[tot]=v;nxt[tot]=fst[u];fst[u]=tot;
}

void init() {
	pp[1]=1;
	rep(i,2,N+1) {
		if (!pp[i]) {
			pp[i]=i,pr[++tot]=i;
			ll v=i;
			while (v<=N) {
				mark[v]=1;
				v=v*i;
			}
		}
		for (int j=1;j<=tot&&pr[j]*i<=N;j++) {
			pp[i*pr[j]]=pr[j];
			if (pp[i]==pr[j]) break;
		}
	}
}

int n,u,v,a[M],U[M],V[M],W[M],z[M];

int query(int x) {
//	printf("qq %d ",x);
	x=l[x];
	auto it=lower_bound(vec+1,vec+VV+1,mp(x+1,-(int)1e9))-1;
//	printf("%d\n",it->se);
	return it->se;
}
int main() {
	init();
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	tot=0;
	dfs(1,0);
	rep(j,1,LOGN) rep(i,1,n+1) p[i][j]=p[p[i][j-1]][j-1];
	tot=0;

	rep(i,1,n+1) {
		scanf("%d",a+i);
		add(a[i],i);
	}
	scanf("%d",&q);
	rep(i,1,q+1) {
		scanf("%d%d%d",U+i,V+i,W+i);
		z[i]=lca(U[i],V[i]);
		add(W[i],-i);
		ret[i]=1;
	}

	rep(i,2,N+1) if (mark[i]) {
		Q=0; VV=0;
		int pr=pp[i];
		for (int j=i;j<=N;j+=i) {
			for (int k=fst[j];k;k=nxt[k]) {
				int z=y[k];
				if (mm[z+100001]==i) continue;
				mm[z+100001]=i;
//				printf("zz %d\n",z);
				if (z>0) {
					vec[++VV]=mp(l[z],1);
					vec[++VV]=mp(r[z]+1,-1);
				} else que[Q++]=-z;
			}
		}
		if (Q==0||VV==0) continue;
		sort(vec+1,vec+VV+1);
		rep(i,1,VV+1) vec[i].se+=vec[i-1].se;
/*		rep(i,1,VV+1) {
			printf("gg %d %d %d\n",i,vec[i].fi,vec[i].se);
		}*/
		rep(c,0,Q) {
			int j=que[c];
			int cnt=query(U[j])+query(V[j])-query(z[j])-query(p[z[j]][0]);
//			printf("ff %d %d %d\n",i,j,cnt);
			ret[j]=ret[j]*powmod(pr,cnt)%mod;
		}
	}
	rep(i,1,q+1) printf("%lld\n",ret[i]);
}