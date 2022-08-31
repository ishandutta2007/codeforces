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
mt19937 mrand(random_device{}()); 
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1010;
int n,k,a[N],dp[N][N],sdp[N][N],ans;

int main() {
	scanf("%d%d",&n,&k);
	rep(i,0,n) scanf("%d",a+i);
	sort(a,a+n);
	int M=100001/(k-1);
	for (int d=1;d<=M;d++) {
		rep(i,0,n+1) rep(j,0,k+1) dp[i][j]=sdp[i][j]=0;
		int pr=0; dp[0][0]=sdp[0][0]=1;
		rep(i,1,n+1) {
			while (pr+1<i&&a[i-1]-a[pr]>=d) ++pr;
			rep(j,1,k+1) {
				dp[i][j]=sdp[pr][j-1];
//				printf("%d %d %d\n",i,j,dp[i][j]);
			}
			rep(j,0,k+1) {
				sdp[i][j]=dp[i][j]+sdp[i-1][j];
				if (sdp[i][j]>=mod) sdp[i][j]-=mod;
			}
		}
		ans=(ans+sdp[n][k])%mod;
//		printf("%d %d\n",d,sdp[n][k]);
	}
	printf("%d\n",ans);
}