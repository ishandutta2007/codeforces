#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &
#define cl const LL &
#define I inline void
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 2e5 + 5,MOD = 1e9 + 7;
#define int long long
int dp[N][10],n,m;
signed main() {
	ios::sync_with_stdio(0);
	int t; cin >> t;
	fr(i,0,9) dp[0][i] = 1;
	fr(i,1,200000) {
		fr(j,0,8) dp[i][j] = dp[i-1][j+1];
		dp[i][9] = (dp[i-1][0] + dp[i-1][1]) % MOD;
	}
	while(t--) {
		cin >> n >> m;
		int ans = 0;
		while(n) (ans += dp[m][n % 10]) %= MOD,n /= 10;
		cout << ans << endl;
	}
	return 0;
}