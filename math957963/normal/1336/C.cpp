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
#include<map>
using namespace std;
#define MOD 998244353
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 3010


int main() {
	char a[N];
	f(i, N)a[i] = 0;
	char b[N];
	f(i, N)b[i] = 0;
	long long dp2[N][N];
	long long dp1[N][N];
	long long n, m, k;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%s", a);
	scanf("%s", b);
	n = strlen(a);
	m = strlen(b);
	f(i, N) {
		f(j, N)dp2[i][j] = 0;
	}
	for (long long i = m; i <= n; i++)dp2[i][0] = 1;
	for (long long i = n - 1; i >= 0; i--) {
		f(j, m + 1) {
			if (a[i] == b[j])dp2[i][j + 1] = (dp2[i][j + 1] + dp2[i + 1][j]) % MOD;
			dp2[i][j] = (dp2[i][j] + dp2[i + 1][j]) % MOD;
		}
	}
	f(i, N) {
		f(j, N)dp1[i][j] = 0;
	}
	f(i, m)dp1[i][i] = 1;
	ans = (ans + dp2[0][m]) % MOD;
	x = 1;
	for (long long i = 1; i <= n; i++) {
		s = (dp2[i][m] * x) % MOD;
		x = (x * 2) % MOD;
		ans = (ans + s) % MOD;
	}
	for (long long i = 0; i < m; i++) {
		f(j, m - i) {
			if (j > 0) {
				if (b[j - 1] == a[i]) {
					dp1[j - 1][j + i] = (dp1[j - 1][j + i] + dp1[j][j + i]) % MOD;
				}
			}
			if (b[j + i] == a[i]) {
				dp1[j][j + i + 1] = (dp1[j][j + i + 1] + dp1[j][j + i]) % MOD;
			}
			if ((i + j + 1) == m) {
				s = (dp1[j][j + i + 1] * dp2[i + 1][m - i - 1]) % MOD;
				ans = (ans + s) % MOD;
			}
		}
	}

	printf("%lld\n", ans);


	return 0;
}