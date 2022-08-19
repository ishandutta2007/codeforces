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

int n,m,x;
bool dp[510][510],pd[510][510];
int main() {
	scanf("%d%d",&n,&m);
	dp[0][0]=1;
	rep(i,0,n) {
		scanf("%d",&x);
		rep(j,0,m+1) rep(k,0,m+1) pd[j][k]=dp[j][k],dp[j][k]=0;
		rep(j,0,m+1) rep(k,0,m+1) {
			dp[j][k]|=pd[j][k];
			if (j+x<=m) dp[j+x][k]|=pd[j][k];
			if (k+x<=m) dp[j][k+x]|=pd[j][k];
		}
	}
	VI ret;
	rep(j,0,m+1) if (dp[j][m-j]) ret.pb(j);
	printf("%d\n",SZ(ret));
	for (auto p: ret) {
		printf("%d ",p);
	}
	puts("");
}