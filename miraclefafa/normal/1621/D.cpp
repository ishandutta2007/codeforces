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

const int N=1100;
int n,a[N][N];
void solve() {
	scanf("%d",&n);
	ll ans=0;
	rep(i,0,2*n) rep(j,0,2*n) {
		scanf("%d",&a[i][j]);
		if (i>=n&&j>=n) ans+=a[i][j];
	}
	ans+=min({a[0][n],a[0][2*n-1],a[n-1][n],a[n-1][2*n-1],a[n][0],a[2*n-1][0],a[n][n-1],a[2*n-1][n-1]});
	printf("%lld\n",ans);
}

int _;
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}