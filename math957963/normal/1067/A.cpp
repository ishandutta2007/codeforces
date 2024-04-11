#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
using namespace std;
#define MOD 998244353
#define f(i,n) for(int i=0;i<(int) n; i++ )
#define N 200010


int main(void) {
	long long dp[200][3];
	long long dp2[200][3];
	long long x;
	int a[N];
	int n;
	scanf("%d", &n);
	f(i, n)scanf("%d", &a[i]);
	f(i, n)a[i]--;
	f(i, 200) {
		f(j, 3) {
			dp[i][j] = 0;
			dp2[i][j] = 0;
		}
	}
	if (a[0] < 0) {
		f(i, 200)dp[i][0] = 1;
	}
	else dp[a[0]][0] = 1;
	for (int i = 1; i < n; i++) {

			x = 0;
			f(j,200){
				dp2[j][0] = x;
				x += dp[j][0];
				x += dp[j][1];
				x += dp[j][2];
				x %= MOD;
			}
			f(j, 200)dp2[j][1] = (dp[j][0] + dp[j][1] + dp[j][2]) % MOD;
			x = 0;
			for (int j = 199; j >= 0; j--) {
				dp2[j][2] = x;
				x += dp[j][1];
				x += dp[j][2];
				x %= MOD;
			}
			if (a[i] >= 0) {
				f(ii, 200) {
					f(jj, 3) {
						if (ii != a[i])dp2[ii][jj] = 0;
					}
				}
			}
			f(ii, 200) {
				f(jj, 3) {
					dp[ii][jj] = dp2[ii][jj];
					dp2[ii][jj] = 0;
				}
			}
	}
	long long ans = 0;
	f(i, 200) {
		ans += dp[i][1];
		ans += dp[i][2];
		ans %= MOD;
	}
	printf("%lld\n", ans);
	return 0;
}