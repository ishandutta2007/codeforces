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

const int N=5010;
int n,nxt[N][30];
ll dp[N][N];
char s[N];
int main() {
	scanf("%d",&n);
	scanf("%s",s);
	rep(j,0,26) nxt[n][j]=n;
	per(i,0,n) {
		rep(j,0,26) nxt[i][j]=nxt[i+1][j];
		nxt[i][s[i]-'a']=i;
	}
	dp[0][0]=1;
	rep(i,0,n) rep(j,0,n) if (dp[i][j]) {
		dp[i][j]%=mod;
		rep(c,0,26) if (nxt[j][c]<n) dp[i+1][nxt[j][c]]+=dp[i][j];
	}
	ll ans=0;
	rep(i,0,n) ans+=dp[n][i];
	printf("%lld\n",ans%mod);
}