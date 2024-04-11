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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=201000;
int stk[N],top,a[N],l[N],r[N],b[N],vis[N];
int n,q,pl,pr;
ll ans;
void dfs(int u,int *a,int pl,int pr) {
	if (l[u]) dfs(l[u],a,pl,u-1);//,sz[u]+=sz[l[u]];
	if (r[u]) dfs(r[u],a,u+1,pr);//,sz[u]+=sz[r[u]];
	ans+=(ll)-a[u]*(pr-u+1)*(u-pl+1);
}
void build(int *a,int n) {
	int top=0;
	rep(i,1,n+1) l[i]=r[i]=0,vis[i]=0;
	rep(i,1,n+1) {
		int k=top;
		while (k>0&&a[stk[k-1]]>a[i]) --k;
		if (k) r[stk[k-1]]=i;
		if (k<top) l[i]=stk[k];
		stk[k++]=i;
		top=k;
	}
	//rep(i,1,n+1) printf("V %d %d\n",l[i],r[i]);
	rep(i,1,n+1) vis[l[i]]=vis[r[i]]=1;
	int rt=0;
	rep(i,1,n+1) if (!vis[i]) rt=i;
	ans=0;
	dfs(rt,a,1,n);
}

int main() {
//	freopen("in","r",stdin);
	scanf("%d%d",&n,&q);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,0,q) {
		scanf("%d%d",&pl,&pr);
		rep(j,pl,pr) b[j-pl+1]=-abs(a[j+1]-a[j]);
		build(b,pr-pl);
		printf("%lld\n",ans);
	}
}