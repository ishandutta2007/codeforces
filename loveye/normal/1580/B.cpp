#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 105;
int n,m,k,p;
ll dp[N][N][N],C[N][N],fac[N];
int main() {
	cin >> n >> m >> k >> p;
	fac[0] = 1; fr(i,1,n) fac[i] = fac[i-1] * i % p;
	fr(i,0,n) {
		C[i][0] = 1;
		fr(j,1,i) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % p;
	}
	fr(j,0,m) dp[j][0][0] = 1;
	fr(i,1,n) dp[1][i][1] = fac[i];

	fr(j,2,m) {
		fo(l,0,n) fr(a,0,k) if(dp[j-1][l][a]) fr(r,0,n-l-1) {
			ll tmp = dp[j-1][l][a] * C[l+r][l] % p;
			fr(b,0,n-a) if(dp[j-1][r][b])
				(dp[j][l+r+1][a+b] += tmp * dp[j-1][r][b]) %= p;
		}
	}

	//fr(j,1,n) fr(i,j,n) fr(l,0,i) cout << j << ' ' << i << ' ' << l << ' ' << dp[j][i][l] << endl;
	cout << dp[m][n][k] << endl;
	return 0;
}