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

int n,k,_;
int dp[1010][1010][2];

void solve() {
	scanf("%d%d",&n,&k);
	rep(i,0,n+1) dp[0][i][0]=1,dp[0][i][1]=1;
	rep(i,1,k) {
		dp[i][0][0]=1;
		rep(j,1,n+1) dp[i][j][0]=(dp[i][j-1][0]+dp[i-1][j][1])%mod;
		dp[i][n][1]=1;
		per(j,0,n) dp[i][j][1]=(dp[i][j+1][1]+dp[i-1][j][0])%mod;
	}
	printf("%d\n",dp[k-1][0][1]);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}