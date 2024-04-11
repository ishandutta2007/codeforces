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

int n,v[1010],dp[1010][4];
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",v+i);
	rep(i,1,n+1) {
		dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
		if (v[i]==1||v[i]==3) dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
		else dp[i][1]=1<<30;
		if (v[i]==2||v[i]==3) dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
		else dp[i][2]=1<<30;
	}
	printf("%d\n",min(dp[n][0],min(dp[n][1],dp[n][2])));
}