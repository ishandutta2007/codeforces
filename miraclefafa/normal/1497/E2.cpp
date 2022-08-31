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

const int N=201000;
int n,k,a[N],_;
int dp[N][22];

void solve() {
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) {
		scanf("%d",a+i);
		for (int k=2;k*k<=a[i];k++) while (a[i]%(k*k)==0) {
			a[i]/=k*k;
		}
	}
	map<int,int> pre;
	VI ps(k+1,0);
	for (int i=1;i<=n;i++) {
		if (pre.count(a[i])) ps.pb(pre[a[i]]);
		pre[a[i]]=i;
		sort(all(ps));
		if (SZ(ps)>k+1) ps.erase(ps.begin());
		//printf("%d\n",i);
		//for (auto x:ps) printf("%d ",x); puts("");
		for (int j=0;j<=k;j++) dp[i][j]=1<<30;
		for (int j=0;j<=k;j++) {
			for (int l=0;l+j<=k;l++) dp[i][l+j]=min(dp[i][l+j],dp[ps[k-j]][l]+1);
		}
		//rep(j,0,k+1) printf("%d ",dp[i][j]); puts("");
	}
	printf("%d\n",dp[n][k]);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}