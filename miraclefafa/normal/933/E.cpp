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

const int N=301000;
map<int,ll> dp[N];
map<int,PII> pre[N],way[N];
int n,a[N];
PII cur;
VI ret,ret2;
void upd(int p,int v,ll cost,PII ww) {
	if (!dp[p].count(v)||cost<dp[p][v]) {
		dp[p][v]=cost;
		way[p][v]=ww;
		pre[p][v]=cur;
	} 
}
void dfs(int n,int v) {
	if (n==1) return;
	if (way[n][v].fi!=-1) ret.pb(way[n][v].fi);
	if (way[n][v].se!=-1) ret.pb(way[n][v].se);
	dfs(pre[n][v].fi,pre[n][v].se);
}
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,1,n+1) dp[i].clear(),pre[i].clear(),way[i].clear();
	dp[1][a[1]]=0;
	rep(i,1,n) {
		ll mv=1ll<<60;
		for (auto p:dp[i]) {
			int v=p.fi; ll w=p.se;
			if (w>=mv) continue;
			mv=w;
			cur=mp(i,v);
			if (v==0) upd(i+1,a[i+1],w,mp(-1,-1));
			upd(i+1,max(a[i+1]-v,0),w+min(v,a[i+1]),mp(i,-1));
			if (i+2<=n&&a[i+1]<=a[i+2]) upd(i+2,a[i+2]-a[i+1],w+a[i+1],mp(i+1,-1));
			if (i+2<=n&&a[i+1]>=a[i+2]) upd(i+2,0,w+a[i+2]+min(v,(a[i+1]-a[i+2])),mp(i,i+1));
		}
	}
	int mv=-1; ll w=1ll<<60;
	for (auto p:dp[n]) if (p.se<w) w=p.se,mv=p.fi;
	dfs(n,mv);
	reverse(all(ret));
	for (auto p:ret) {
		if (a[p]>0&&a[p+1]>0) {
			int z=min(a[p],a[p+1]);
			a[p]-=z; a[p+1]-=z;
			ret2.pb(p);
		}
	}
	printf("%d\n",SZ(ret2));
	for (auto p:ret2) printf("%d ",p);
	puts("");
}