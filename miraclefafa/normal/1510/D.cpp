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
typedef long double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000;
int n,d;
db dp[N][12],val[N];
int a[N];
VI ans;
void dfs(int x,int d) {
	if (x==0) return;
	if (dp[x-1][d]==dp[x][d]) {
		dfs(x-1,d);
		return;
	} else {
		rep(j,0,12) if (j*a[x-1]%10==d&&dp[x-1][j]+val[x-1]==dp[x][d]) {
			ans.pb(a[x-1]);
			dfs(x-1,j);
			return;
		}
	}
	assert(0);
}
int main() {
	scanf("%d%d",&n,&d);
	rep(i,0,n+1) rep(j,0,10) dp[i][j]=-1e10;
	dp[0][11]=0;
	for (int i=0;i<n;i++) {
		scanf("%d",a+i);
		val[i]=log(a[i]);
		rep(j,0,12) {
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			dp[i+1][j*a[i]%10]=max(dp[i+1][j*a[i]%10],dp[i][j]+val[i]);
		}
	}
	if (dp[n][d]<0) {
		puts("-1");
		return 0;
	}
	dfs(n,d);
	printf("%d\n",SZ(ans));
	for (auto x:ans) printf("%d ",x);
	puts("");
}