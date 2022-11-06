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
#define N 524288
vector<long long>a;
vector<long long>c;
vector<long long>d;
vector<long long>e;
long long dp[60][N];
long long dp2[60][N];
bool c2[60];
long long b[60];
long long x, y, z, s;
long long n, k, m, sz;
long long ans[60];
long long ans2[60];

int main() {
	f(i, 60)c2[i] = false;
	b[0] = 1;
	f(i, 59)b[i + 1] = b[i] * 2;
	scanf("%lld %lld", &n, &m);
	f(i, n) {
		scanf("%lld", &x);
		a.push_back(x);
	}
	f(i, m)c2[i] = true;
	f(j, m) {
		f(i, n) {
			if (a[i] % b[j + 1] >= b[j]) {
				c2[j] = false;
				k++;
				for (long long ii = i + 1; ii < n; ii++) {
					if (a[ii] % b[j + 1] >= b[j])a[ii] = a[ii] ^ a[i];
				}
				f(ii, c.size()) {
					if (c[ii] % b[j + 1] >= b[j])c[ii] = c[ii] ^ a[i];
				}
				c.push_back(a[i]);
				a[i] = 0;
				break;
			}
		}
	}
	sz = c.size();
	f(i, m + 1)ans[i] = 0;
	f(i, sz) {
		x = c[i];
		y = 1;
		z = 0;
		f(j, m) {
			if (c2[j]) {
				if (x%b[j + 1] >= b[j])z += y;
				y = y * 2;
			}
		}
		d.push_back(z);
	}
	if (sz < 18) {
		e.push_back(0);
		f(i, sz) {
			f(j, b[i]) {
				e.push_back(e[j] ^ d[i]);
			}
		}

		f(i, e.size()) {
			x = e[i];
			y = 0;
			f(ii, m) {
				if (x % 2 == 1)y++;
				x /= 2;
			}
			x = i;
			f(ii, m) {
				if (x % 2 == 1)y++;
				x /= 2;
			}
			ans[y]++;
		}
	}
	else {
		f(i, 60) {
			f(j, N) {
				dp[i][j] = 0;
				dp2[i][j] = 0;
			}
		}
		dp[0][0] = 1;
		f(ii, sz) {
			f(i, ii+1) {
				f(j, b[m - sz]) {
					dp2[i + 1][(j^d[ii])] += dp[i][j];
					dp2[i][j] += dp[i][j];
				}
			}
			f(i, ii+2) {
				f(j, b[m - sz]) {
					dp[i][j] = dp2[i][j] % MOD;
					dp2[i][j] = 0;
				}
			}
		}
			f(j, b[m - sz]) {
				x = j;
				y = 0;
				while (x > 0) {
					if (x % 2 == 1)y++;
					x /= 2;
				}
				f(i, sz + 1) {
				if ((y+i) <= m)ans[(y+i)] = (ans[(y+i)] + dp[i][j]) % MOD;
			}
		}
	}



	f(i, n - sz) {
		f(j, m + 1) {
			ans[j] = (ans[j] * 2) % MOD;
		}
	}
	f(i, m)printf("%lld ", ans[i]);
	printf("%lld\n", ans[m]);
	return 0;
}