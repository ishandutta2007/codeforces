#include<bits/stdc++.h>
using namespace std;

int read();
#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &
#define cl const LL &
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 3e5 + 5,MOD = 998244353;
int n,m;
string s[N];
inline LL qpow(LL a,int x) {
	LL res = 1;
	for(;x;x >>= 1) (x & 1) && (res = res * a % MOD),a = a * a % MOD;
	return res;
}
int cnt;
LL pw[N],ans,dp[N][2],f[N],dp2[N][2];
int main() {
	cin >> n >> m;
	fo(i,0,n) cin >> s[i];
	fo(i,0,n) fo(j,0,m) if(s[i][j] == 'o') ++cnt;
	pw[0] = 1; fr(i,1,n*m) pw[i] = pw[i-1] * 2 % MOD;
	dp2[0][0] = 1;
	dp2[0][1] = 0;
	fr(i,1,max(n,m)) {
		dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp2[i-1][1] + dp[i-1][1]) % MOD;
		dp[i][1] = dp[i-1][0];
		dp2[i][0] = (dp2[i-1][0] + dp2[i-1][1] + dp2[i-1][1]) % MOD;
		dp2[i][1] = dp2[i-1][0];
		f[i] = (dp[i][0] + dp[i][1]) % MOD;
		//cout << dp[i][0] << ' ' << dp[i][1] << endl;
	}
	fo(i,0,n) {
		int res = 0;
		fo(j,0,m) if(s[i][j] == 'o') ++res;
		else (ans += pw[cnt-res] * f[res]) %= MOD,res = 0;
		(ans += pw[cnt-res] * f[res]) %= MOD;
	}
	fo(j,0,m) {
		int res = 0;
		fo(i,0,n) if(s[i][j] == 'o') ++res;
		else (ans += pw[cnt-res] * f[res]) %= MOD,res = 0;
		(ans += pw[cnt-res] * f[res]) %= MOD;
	}
	cout << ans << endl;
	return 0;
}