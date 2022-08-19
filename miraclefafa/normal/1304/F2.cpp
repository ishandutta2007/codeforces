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
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
 
const int N=55,M=20100;
 
int n,m,k,val[N][M],s[N][M],dp[N][M],pmax[M],smax[M];
int ans;
int main() {
	scanf("%d%d%d",&n,&m,&k);
	rep(i,0,n) {
		rep(j,1,m+1) scanf("%d",&val[i][j]);
		rep(j,1,m+1) s[i][j]=s[i][j-1]+val[i][j];
	}
	rep(j,1,m-k+2) {
		dp[0][j]=s[0][j+k-1]-s[0][j-1]+s[1][j+k-1]-s[1][j-1];
		//printf("%d %d %d\n",0,j,dp[0][j]);
	}
	rep(i,1,n) {
		rep(j,1,m-k+2) pmax[j]=max(pmax[j-1],dp[i-1][j]);
		per(j,1,m-k+2) smax[j]=max(smax[j+1],dp[i-1][j]);
		multiset<int> s1,s2;
		for (int j=1;j<1+k-1;j++) s2.insert(dp[i-1][j]+s[i][j-1]);
		rep(j,1,m-k+2) {
			if (j-k>=1) dp[i][j]=max(dp[i][j],pmax[j-k]);
			if (j+k<=m-k+1) dp[i][j]=max(dp[i][j],smax[j+k]);
			s1.insert(dp[i-1][j]-s[i][j+k-1]);
			if (j-k>=1) s1.erase(s1.lower_bound(dp[i-1][j-k]-s[i][j-1]));
			if (!s1.empty()) dp[i][j]=max(dp[i][j],*s1.rbegin()+s[i][j-1]);
 
			if (j+k-1<=m-k+1) s2.insert(dp[i-1][j+k-1]+s[i][j+k-2]);
			if (j-1>=1) s2.erase(s2.lower_bound(dp[i-1][j-1]+s[i][j-2]));
			if (!s2.empty()) dp[i][j]=max(dp[i][j],*s2.rbegin()-s[i][j+k-1]);
 
			dp[i][j]+=s[i][j+k-1]-s[i][j-1]+s[i+1][j+k-1]-s[i+1][j-1];
		}
	}
	rep(i,0,n) rep(j,1,m-k+2) ans=max(ans,dp[i][j]);
	printf("%d\n",ans);
}