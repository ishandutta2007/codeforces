#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=2010;
int n,k,p,a[N],b[N];
int dp[N][N];
int main() {
	scanf("%d%d%d",&n,&k,&p);
	rep(i,1,n+1) scanf("%d",a+i); sort(a+1,a+n+1);
	rep(i,1,k+1) scanf("%d",b+i); sort(b+1,b+k+1);
	dp[0][0]=0;
	rep(j,1,k+1) dp[0][j]=0;
	rep(i,1,n+1) {
		dp[i][0]=2100000000;
		rep(j,1,k+1) {
			dp[i][j]=max(abs(a[i]-b[j])+abs(b[j]-p),dp[i-1][j-1]);
//			printf("%d %d %lld\n",i,j,dp[i][j]);
		}
		rep(j,1,k+1) dp[i][j]=min(dp[i][j],dp[i][j-1]);
	}
	printf("%d\n",dp[n][k]);
}