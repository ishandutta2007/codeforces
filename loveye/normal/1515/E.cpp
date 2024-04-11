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
#define I inline void
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 405;
int n,MOD;
LL dp[N][N],ans,C[N][N],f[N];
int main() {
	cin >> n >> MOD;
	C[0][0] = 1;
	fr(i,1,n) {
		C[i][0] = 1;
		fr(j,1,i) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
	}
	fr(i,1,n) fr(j,1,i) (f[i] += C[i-1][j-1]) %= MOD;
	dp[0][0] = 1;
	fr(i,1,n) fr(j,1,n-i) fr(k,1,i)
		(dp[i][j] += dp[i-k][j-1] * f[k] % MOD * C[i][k]) %= MOD;
	fr(i,0,n) fo(j,0,n-i)
		(ans += dp[i][j] * f[n-i-j] % MOD * C[n-j][i]) %= MOD;
	cout << ans << endl;
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}