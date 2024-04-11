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
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=550;
int n,k;
ll comb[N][N],dp[N],pd[N];
ll pw[N*N];
int main() {
	scanf("%d%d",&n,&k);
	dp[0]=1;
	rep(i,0,n+1) {
		comb[i][0]=comb[i][i]=1;
		rep(j,1,i) comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
	}
	for (int w=1;w<=k;w++) {
		per(i,0,n) pd[i]=dp[i],dp[i]=0;
		pw[0]=1;
		rep(i,1,n*n+1) pw[i]=pw[i-1]*(k+1-w)%mod;
		rep(i,0,n) rep(j,0,n) if (i+j<=n-1) {
			dp[i+j]=(dp[i+j]+comb[n-1-i][j]*pw[j*(j-1)/2+i*j]%mod*pd[i])%mod;
		}
	}
	printf("%lld\n",dp[n-1]);
}