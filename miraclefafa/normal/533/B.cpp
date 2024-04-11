#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=201000;
int n,p,e[N];
ll dp[N][2],tmp[2];
VI s[N];
void dfs(int x) {
	dp[x][0]=0; dp[x][1]=-(1ll<<60);
	for (auto v:s[x]) {
		dfs(v);
		rep(j,0,2) tmp[j]=dp[x][j];
		tmp[0]=max(dp[x][0]+dp[v][0],dp[x][1]+dp[v][1]);
		tmp[1]=max(dp[x][0]+dp[v][1],dp[x][1]+dp[v][0]);
		rep(j,0,2) dp[x][j]=tmp[j];
	}
	dp[x][1]=max(dp[x][1],dp[x][0]+e[x]);
}
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%d%d",&p,e+i);
		if (p!=-1) s[p].pb(i);
	}
	dfs(1);
	printf("%I64d\n",max(dp[1][0],dp[1][1]));
}