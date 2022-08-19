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

const int N=101000;
int pb[N],pr[N],n,m,dp[N][2];
char L[N],R[N],U[N],D[N];
int solve(char *L,char *R,char *U,char *D,int n,int m,char r,char b) {
	dp[0][0]=dp[0][1]=0;
	rep(i,0,n) {
		dp[0][0]+=(L[i]==b);
		dp[0][1]+=(L[i]==r);
	}
	dp[0][0]+=(U[0]==b)+(D[0]==b);
	dp[0][1]+=(U[0]==r)+(D[0]==r);
	rep(i,1,m) {
		dp[i][0]=min(dp[i-1][0],dp[i-1][1]+n)+(U[i]==b)+(D[i]==b);
		dp[i][1]=min(dp[i-1][1],dp[i-1][0]+n)+(U[i]==r)+(D[i]==r);
	}
	rep(i,0,n) {
		dp[m-1][0]+=(R[i]==b);
		dp[m-1][1]+=(R[i]==r);
	}
	return min(dp[m-1][0],dp[m-1][1]);
}
int main() {
	scanf("%d%d%*d",&n,&m);
	scanf("%s%s%s%s",L,R,U,D);
	int pR=0;
	rep(i,0,n) pR+=(L[i]=='R')+(R[i]=='R');
	rep(i,0,m) pR+=(U[i]=='R')+(D[i]=='R');
	int ans=min(pR,2*(n+m)-pR);
	ans=min(ans,solve(L,R,U,D,n,m,'R','B'));
	ans=min(ans,solve(U,D,L,R,m,n,'R','B'));
	printf("%d\n",ans);
}