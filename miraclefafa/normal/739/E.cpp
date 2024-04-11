#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <ctime>
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
int n,a,b,cnt[N][N];
double p[N],u[N],f[N],dp[N][N];
int main() {
	scanf("%d%d%d",&n,&a,&b);
	rep(i,0,n) scanf("%lf",p+i);
	rep(i,0,n) scanf("%lf",u+i),f[i]=p[i]+u[i]-p[i]*u[i];
	double l=-5e4,r=5e4;
	while (clock()<=4*CLOCKS_PER_SEC) {
		double md=(l+r)*0.5;
		rep(i,0,n+1) rep(j,0,i+1) dp[i][j]=-1e10,cnt[i][j]=0;
		dp[0][0]=0;
		rep(i,1,n+1) rep(j,0,i+1) {
			if (j<i&&dp[i-1][j]>dp[i][j]) dp[i][j]=dp[i-1][j],cnt[i][j]=cnt[i-1][j];
			if (j>0&&dp[i-1][j-1]+p[i-1]>dp[i][j]) dp[i][j]=dp[i-1][j-1]+p[i-1],cnt[i][j]=cnt[i-1][j-1];
			if (j<i&&dp[i-1][j]+u[i-1]+md>dp[i][j]) dp[i][j]=dp[i-1][j]+u[i-1]+md,cnt[i][j]=cnt[i-1][j]+1;
			if (j>0&&dp[i-1][j-1]+f[i-1]+md>dp[i][j]) dp[i][j]=dp[i-1][j-1]+f[i-1]+md,cnt[i][j]=cnt[i-1][j-1]+1;
		}
		if (cnt[n][a]<b) l=md; else r=md;
	}
	printf("%.10f\n",dp[n][a]-b*0.5*(l+r));
}