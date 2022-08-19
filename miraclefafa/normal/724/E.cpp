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

const int N=10100;
ll dp[N],pd[N];
int n,c,p[N],q[N];
int main() {
	scanf("%d%d",&n,&c);
	rep(i,0,n) scanf("%d",p+i);
	rep(i,0,n) scanf("%d",q+i);
	memset(dp,0x20,sizeof(dp));
	dp[0]=0;
	rep(i,0,n) {
		rep(j,0,i+1) pd[j]=dp[j],dp[j]=1ll<<60;
		rep(j,0,i+1) {
			dp[j+1]=min(pd[j]+q[i],dp[j+1]);
			dp[j]=min(dp[j],pd[j]+p[i]+(ll)j*c);
		}
	}
	ll ret=1ll<<60;
	rep(i,0,n+1) ret=min(ret,dp[i]);
	printf("%lld\n",ret);
}