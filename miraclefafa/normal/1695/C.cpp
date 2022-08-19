#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=2100;
int _,n,m,a[N][N],dp[N][N],pd[N][N];
const int inf=1<<30;
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&n,&m);
		rep(i,1,n+1) rep(j,1,m+1) {
			scanf("%d",&a[i][j]);
		}
		if ((n+m)%2==0) {
			puts("NO");
			continue;
		}
		dp[1][1]=a[1][1];
		rep(i,1,n+1) rep(j,1,m+1) {
			if (i==1&&j==1) continue;
			dp[i][j]=-inf;
			if (i>1) dp[i][j]=max(dp[i][j],dp[i-1][j]);
			if (j>1) dp[i][j]=max(dp[i][j],dp[i][j-1]);
			dp[i][j]+=a[i][j];
		}

		pd[1][1]=a[1][1];
		rep(i,1,n+1) rep(j,1,m+1) {
			if (i==1&&j==1) continue;
			pd[i][j]=inf;
			if (i>1) pd[i][j]=min(pd[i][j],pd[i-1][j]);
			if (j>1) pd[i][j]=min(pd[i][j],pd[i][j-1]);
			pd[i][j]+=a[i][j];
		}
		puts((pd[n][m]<=0&&dp[n][m]>=0)?"YES":"NO");
	}
}