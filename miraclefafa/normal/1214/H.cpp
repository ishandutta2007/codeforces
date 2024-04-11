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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head


#define LOGN 19

const int N=201000;
int p[N][22],dep[N];
int n,k,u,v,lev[N],vis[N],col[N];
VI e[N];
void dfs(int u,int f) {
	p[u][0]=f;
	dep[u]=dep[f]+1;
	for (auto v:e[u]) if (v!=f) {
		dfs(v,u);
	}
}
int lca(int u,int v) {
	if (dep[u]>dep[v]) swap(u,v);
	per(i,0,LOGN) if (dep[p[v][i]]>=dep[u]) v=p[v][i];
	if (u==v) return u;
	per(i,0,LOGN) if (p[v][i]!=p[u][i]) u=p[u][i],v=p[v][i];
	return p[u][0];
}
int dist(int u,int v) {
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}

int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	dfs(1,0);
	rep(j,1,LOGN) rep(i,1,n+1) p[i][j]=p[p[i][j-1]][j-1];
	int pu=1,pd=0;
	rep(i,1,n+1) {
		int d=dist(1,i);
		if (d>pd) pd=d,pu=i;
	}
	int pv=pu; pd=0;
	rep(i,1,n+1) {
		int d=dist(pu,i);
		if (d>pd) pd=d,pv=i;
	}
//	printf("%d %d %d\n",pu,pv,pd);
	rep(i,1,n+1) {
		int d1=dist(pu,i);
		if (d1+dist(pv,i)==pd) {
			vis[i]=1;
			lev[i]=d1;
		}
	}
	if (k==2) {
		puts("Yes");
		rep(i,1,n+1) printf("%d%c",dep[i]%2+1," \n"[i==n]);
		return 0;
	}
	--k;
	rep(i,1,n+1) {
		if (vis[i]) continue;
		int d1=dist(i,pu),d2=dist(i,pv);
		if (d1>=k&&d2>=k) {
			puts("No");
			return 0;
		}
		if (d1<k&&d2<k) {
			if (d1==d2) lev[i]=0;
			else if (d1>d2) lev[i]=d1;
			else lev[i]=pd-d2;
		} else if (d1>=k) {
			lev[i]=d1;
		} else {
			lev[i]=pd-d2;
		}
	}
	puts("Yes");


	rep(i,1,n+1) {
		printf("%d%c",lev[i]%(k+1)+1," \n"[i==n]);
		col[i]=lev[i]%(k+1)+1;
	}
/*	rep(i,1,n+1) rep(j,1,n+1) if (dist(i,j)==k) {
		set<int> cc;
		rep(z,1,n+1) if (dist(i,z)+dist(z,j)==k) cc.insert(col[z]);
		assert(SZ(cc)==k+1);
	}*/
}