#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

inline ll getint() {
	ll ret=0;bool ok=0;
	for(;;) {
		int c=getchar();
		if(c>='0'&&c<='9')ret=(ret<<3)+ret+ret+c-'0',ok=1;
		else if(ok)return ret;
	}
}

const int N=1010000;
ll ss;
int go[N*3],ff[N*3],a[N*2],stk[N*3],vis[N*3];
int fst[N*2],y[N*2],nxt[N*2];
int ret,n,q;
void dfs(int u,int d) {
	stk[d]=u; vis[u]=1;
	if (d>=ret-1) ff[u]=stk[d-(ret-1)];
	for (int j=fst[u];j;j=nxt[j]) dfs(y[j],d+1);
}
void gao(ll x) {
	if (x>=ss) { puts("1");return;}
	ll s=0; int r=0;
	while (s<=x) s+=a[++r];
	go[1]=r;
	rep(i,2,n+1) {
		s-=a[i-1];
		while (s<=x) s+=a[++r];
		go[i]=r;
	}
	rep(i,1,n+1) go[i+n]=go[i]+n;
	int p=1; ret=0;
	while (p<=n) ret++,p=go[p];
	// check if k-1 is possible
	rep(i,1,2*n+1) fst[i]=0,vis[i]=0;
	int tot=1;
	rep(i,1,2*n+1) if (go[i]<=2*n) {
		y[tot]=i; nxt[tot]=fst[go[i]]; fst[go[i]]=tot++;
	}
	rep(i,1,n+1) ff[i]=2*n+1;
	per(i,1,2*n+1) if (!vis[i]) dfs(i,0);
	rep(i,1,n+1) if (ff[i]>=i+n) {
		printf("%d\n",ret-1);
		return;
	}
	printf("%d\n",ret);
}
int main() {
	scanf("%d%d",&n,&q);
	rep(i,1,n+1) a[i]=getint(),ss+=a[i];
	rep(i,n+1,n+n+1) a[i]=a[i-n];
	rep(i,0,q) gao(getint());
}