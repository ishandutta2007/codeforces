#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint n, m, mod, N;
llint a[1<<20], b[65][25], B[25];
int p[1<<20][25];
llint ans[1<<20];
llint pop[1<<20];

void mul(llint b[], llint x[], llint y[])
{
	for(int i = 0; i < N; i++){
		for(int j = 1; j <= n; j++) p[i][j] = 0;
		p[i][0] = x[i];
	}
	for(int i = 0; i < n; i++){
		for(int k = n; k >= 1; k--){
			for(int j = 0; j < N; j++){
				if(j & (1<<i)) continue;
				p[j][k] += p[j|(1<<i)][k-1];
				if(p[j][k] >= mod) p[j][k] -= mod;
				p[j|(1<<i)][k] += p[j][k-1];
				if(p[j|(1<<i)][k] >= mod) p[j|(1<<i)][k] -= mod;
			}
		}
	}
	for(int i = 0; i < N; i++){
		y[i] = 0;
		for(int j = 0; j <= n; j++){
			y[i] += p[i][j] * b[j] % mod;
			if(y[i] >= mod) y[i] -= mod;
		}
	}
}

llint dp[21][21][21][21][21];
void mul2(llint b[], llint b2[], llint d[])
{
	for(int len = 1; len <= n; len++){
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				for(int k = 0; k <= n; k++){
					dp[i][i+len][j][j+len][k] = 0;
				}
			}
		}
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			dp[i][i][j][j][0] = b[i]*b2[j]%mod;
		}
	}
	
	for(int len = 1; len <= n; len++){
		for(int i = 0; i+len <= n; i++){
			for(int j = 0; j+len <= n; j++){
				
				for(int k = 0; k <= len-1; k++){
					dp[i][i+len][j][j+len][k] = (dp[i][i+len-1][j][j+len-1][k] + dp[i+1][i+1+len-1][j+1][j+1+len-1][k]);
					if(dp[i][i+len][j][j+len][k] >= mod) dp[i][i+len][j][j+len][k] -= mod;
				}
				dp[i][i+len][j][j+len][len] = (dp[i][i+len-1][j+1][j+1+len-1][len-1] + dp[i+1][i+1+len-1][j][j+len-1][len-1]);
				if(dp[i][i+len][j][j+len][len] >= mod) dp[i][i+len][j][j+len][len] -= mod;
			}
		}
	}
	for(int i = 0; i <= n; i++) d[i] = dp[0][n][0][n][i];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> mod;
	N = 1<<n;
	for(int i = 0; i < N; i++) cin >> a[i], a[i] %= mod;
	for(int i = 0; i <= n; i++) cin >> b[0][i];
	for(int i = 1; i < N; i++) pop[i] = pop[i&(i-1)] + 1;
	
	for(int i = 1; i <= 60; i++) mul2(b[i-1], b[i-1], b[i]);
	
	B[0] = 1;
	for(int i = 0; i < 60; i++){
		if(m & (1LL<<i)) mul2(b[i], B, B);
	}
	
	mul(B, a, ans);
	
	for(int i = 0; i < N; i++) cout << ans[i] << "\n";
	flush(cout);
	
	return 0;
}