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

const int N=10100;
int n,t[N],s[N],_;
ll dp[N];
void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",t+i);
	rep(i,1,n+1) scanf("%d",s+i),dp[i]=0;
	for (int i=2;i<=n;i++) for (int j=i-1;j>=1;j--) {
		if (t[i]!=t[j]) {
			ll w=abs(s[i]-s[j]);
			ll p1=max(dp[i],dp[j]+w),p2=max(dp[j],dp[i]+w);
			dp[i]=p1; dp[j]=p2;
		}
	}
	printf("%lld\n",*max_element(dp+1,dp+n+1));
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}