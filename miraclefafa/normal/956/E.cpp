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

const int N=10100,V=10000;
bitset<V+1> sz[N][2],f[2];
int n,m,l,r,p1[N],p2[N],ss,dp[N],pd[N],ret;
VI imp,unimp;
int main() {
	scanf("%d%d%d",&n,&l,&r);
	rep(i,0,n) scanf("%d",p1+i);
	rep(i,0,n) scanf("%d",p2+i);
	rep(i,0,n) 
		if (p2[i]==1) imp.pb(p1[i]);
		else unimp.pb(p1[i]);
	int m=SZ(imp);
	if (m==0) { puts("0"); return 0; }
	sort(all(imp));
	f[0][0]=1;
	for (auto p:unimp) f[0]=f[0]|(f[0]<<p);
	sz[m][0]=f[0];
	per(i,0,m) {
		f[1]=f[0]|f[1]|(f[1]<<imp[i]);
		f[0]=f[0]<<imp[i];
		sz[i][0]=f[0];
		sz[i][1]=f[1];
	}
	dp[0]=0;
	rep(i,1,V+1) dp[i]=1e8;
	rep(i,0,V+1) pd[i]=dp[i];
	int sm=0;
	rep(k,0,m+1) {
		rep(i,0,r+1) if (i+sm<=r) {
			if (i<=l) {
				if (sz[k][0][i]) ret=max(ret,k-pd[l-i]);
				if (sz[k][1][i]) ret=max(ret,k-pd[l-i]+1);
			} else {
				if (sz[k][0][i]) ret=max(ret,k);
				if (sz[k][1][i]) ret=max(ret,k+1);				
			}
		}
		if (k<m) {
			per(i,imp[k],V+1) dp[i]=min(dp[i],dp[i-imp[k]]+1);
			pd[V]=dp[V];
			per(i,0,V) pd[i]=min(pd[i+1],dp[i]);
			sm+=imp[k];
		}
	}
	printf("%d\n",ret);
}