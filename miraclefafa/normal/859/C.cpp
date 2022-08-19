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

const int N=55;
int n,a[N],dp[N][2],s;
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i),s+=a[i];
	dp[n][1]=a[n]; dp[n][0]=0;
	per(i,1,n) {
		dp[i][1]=max(a[i]+dp[i+1][0],dp[i+1][1]);
		dp[i][0]=min(dp[i+1][1],a[i]+dp[i+1][0]);
	}
	printf("%d %d\n",s-dp[1][1],dp[1][1]);
}