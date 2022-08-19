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

int t,n,m,u,v,g[30],ret,rew,mark[30],f[30],pa[30][30];
int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }
void dfs(int S,int u,int v) {
	if (v>=ret) return;
	if (u==n) {
		bool suc=1;
		int ff=-1;
		rep(i,0,n) if (S&(1<<i)) {
			if (ff==-1) ff=find(i); else {
				if (find(i)!=ff) {
					suc=0; break;
				}
			}
		} else {
			if ((g[i]&S)==0) { suc=0; break; }
		}
		if (suc) {
			ret=v,rew=S;
		}
	} else {
		rep(i,0,n) pa[u][i]=f[i];
		int su=find(u);
		rep(i,0,n) if (g[u]&S&(1<<i)) f[find(i)]=su;
		dfs(S|(1<<u),u+1,v+1);
		rep(i,0,n) f[i]=pa[u][i];
		dfs(S,u+1,v);
	}
}
void dfs(int u) {
	mark[u]=0;
	rep(v,0,n) if ((g[u]&(1<<v))&&mark[v]) dfs(v);
	printf("%d ",u+1);
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		--u; --v;
		g[u]|=(1<<v); g[v]|=(1<<u);
	}
	if (m==n*(n-1)/2) {
		puts("0");
		return 0;
	}
	ret=n+1;
	rep(i,0,n) g[i]|=(1<<i),f[i]=i;
	dfs(0,0,0);
	printf("%d\n",ret);
	rep(i,0,n) if (rew&(1<<i)) {
		mark[i]=1;
	}
	rep(i,0,n) if (mark[i]) {
		dfs(i);
		return 0;
	}
}