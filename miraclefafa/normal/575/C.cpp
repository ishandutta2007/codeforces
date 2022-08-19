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

const int N=30;
int dx[N],dy[N],b[N],v[N][N],a[N][N],B[N][N],n,T,tot,slack[N],f[N],g[N],ret,tot2,opt[N];
PII perm[N];
int state[185000],val[185000];
bool hungary(int x) {
	if (x==-1) return 1;
	f[x]=1;
	rep(i,0,n) {
		if (g[i]) continue;
		int t=dx[x]+dy[i]-v[x][i];
		if (!t) {
			g[i]=1;
			if (hungary(b[i])) { 
				b[i]=x;
				return 1;
			}
		} else slack[i]=min(slack[i],t);
	}
	return 0;
}
void dfs(int d,int s1,int s2) {
	int s=0,u=perm[d].se;
	rep(i,0,n) s+=dx[i]+dy[i];
	if (s+opt[d]<=ret) return;
	if (d==n) {
		int r=0;
		rep(i,0,n) r+=dx[i]+dy[i];
		ret=max(ret,r);
	}
	int pdx[30],pdy[30],p[30];
	rep(i,0,n) pdx[i]=dx[i],pdy[i]=dy[i],p[i]=b[i];
	if (s1!=n/2) {
		rep(j,0,n) v[u][j]=a[u][j];
		rep(i,0,n) dx[u]=max(dx[u],v[u][i]);
		memset(slack,0x20,sizeof(slack));
		rep(i,0,n) f[i]=g[i]=0;
		while (!hungary(u)) {
			int d=0x20202020;
			rep(j,0,n) if (!g[j]) d=min(d,slack[j]);
			rep(j,0,n) {
				if (f[j]) dx[j]-=d;
				if (g[j]) dy[j]+=d;
			}
			rep(j,0,n) f[j]=g[j]=0;
		}
		dfs(d+1,s1+1,s2);
		rep(i,0,n) dx[i]=pdx[i],dy[i]=pdy[i],b[i]=p[i];
	}
	if (s2!=n/2) {
		rep(j,0,n) v[u][j]=B[u][j];
		rep(i,0,n) dx[u]=max(dx[u],v[u][i]);
		memset(slack,0x20,sizeof(slack));
		rep(i,0,n) f[i]=g[i]=0;
		while (!hungary(u)) {
			int d=0x20202020;
			rep(j,0,n) if (!g[j]) d=min(d,slack[j]);
			rep(j,0,n) {
				if (f[j]) dx[j]-=d;
				if (g[j]) dy[j]+=d;
			}
			rep(j,0,n) f[j]=g[j]=0;
		}
		dfs(d+1,s1,s2+1);
		rep(i,0,n) dx[i]=pdx[i],dy[i]=pdy[i],b[i]=p[i];
	}
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) rep(j,0,n) scanf("%d",&a[i][j]);
	rep(i,0,n) rep(j,0,n) scanf("%d",&B[i][j]);

	rep(i,0,n) {
		rep(j,0,n) v[i][j]=max(a[i][j],B[i][j]);
		perm[i]=mp(*max_element(v[i],v[i]+n),i);
	}
	sort(perm,perm+n); reverse(perm,perm+n);
	rep(i,0,n) b[i]=-1;
	per(d,0,n) {
		int u=perm[d].se;
		rep(i,0,n) dx[u]=max(dx[u],v[u][i]);
		memset(slack,0x20,sizeof(slack));
		rep(i,0,n) f[i]=g[i]=0;
		while (!hungary(u)) {
			int d=0x20202020;
			rep(j,0,n) if (!g[j]) d=min(d,slack[j]);
			rep(j,0,n) {
				if (f[j]) dx[j]-=d;
				if (g[j]) dy[j]+=d;
			}
			rep(j,0,n) f[j]=g[j]=0;
		}
		opt[d]=0;
		rep(i,0,n) opt[d]+=dx[i]+dy[i];
	}
	rep(i,0,n) b[i]=-1,dx[i]=dy[i]=0;
	dfs(0,0,0);
	printf("%d\n",ret);
}