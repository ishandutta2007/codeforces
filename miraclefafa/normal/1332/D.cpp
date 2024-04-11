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

const int N=510;
int k,a[N][N],dp[N][N],n=10;
int main() {
	scanf("%d",&k);
	//for (int i=0;i<=300000;i++) if ((i&k)==k&&__builtin_popcount(k^i)==1) cand.pb(i);
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) {
		//if (i+j<=3) a[i][j]=(1<<17)-1;
		//else a[i][j]=(1<<17)-1-k;
		a[i][j]=(1<<18)-1;
	}
	a[1][3]=(1<<18)-1-k;
	a[3][1]=(1<<18)-1-k;
	a[2][2]=k;
	a[n][n]=k;
	dp[0][1]=a[1][1];
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) {
		dp[i][j]=max(dp[i-1][j]&a[i][j],dp[i][j-1]&a[i][j]);
	}
	printf("%d %d\n",n,n);
	rep(i,1,n+1) rep(j,1,n+1) printf("%d%c",a[i][j]," \n"[j==n]);
//	printf("%d\n",dp[n][n]);
}