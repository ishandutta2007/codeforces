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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=510;
int n,a[N],dp[N][N];
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,1,n+1) dp[i][i-1]=dp[i][i]=1;
	rep(j,2,n+1) per(i,1,j) {
		dp[i][j]=n;
		if (a[i]==a[j]) dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
		rep(k,i,j) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
	}
	printf("%d\n",dp[1][n]);
}