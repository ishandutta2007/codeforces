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

const int N=5100;
const int inf=0x20202020;
int dp[2800][210][2][110],cnt,n,a[N],s[N];
int solve(int l,int r,int p,int k) {
	int &ret=dp[l][r-l+100][p][k];
	if (dp[l][r-l+100][p][k]!=0xa0a0a0a0) return ret;
	if (p==0) {
		ret=-inf;
		if (l+k+r<=n) ret=max(ret,solve(l+k,r,1,k)+s[l+k]-s[l]);
		if (l+k+1+r<=n) ret=max(ret,solve(l+k+1,r,1,k+1)+s[l+k+1]-s[l]);
		if (l+k+r>n) ret=0;
	} else {
		ret=inf;
		if (l+k+r<=n) ret=min(ret,solve(l,r+k,0,k)-(s[n-r]-s[n-r-k]));
		if (l+k+1+r<=n) ret=min(ret,solve(l,r+k+1,0,k+1)-(s[n-r]-s[n-r-k-1]));
		if (l+k+r>n) ret=0;
	}
//	printf("%d %d %d %d %d\n",l,r,p,k,ret);
	return ret;
}
int main() {
	memset(dp,0xa0,sizeof(dp));
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i),s[i]=s[i-1]+a[i];
	printf("%d\n",solve(0,0,0,1));
}