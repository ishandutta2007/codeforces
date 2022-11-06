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
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000
int dp[2010][2010];
int dp2[2010][2010];

int main() {
	char aa[10];
	char ans[2010];
	int a[N];
	int b[10];
	b[0] = 119;
	b[1] = 36;
	b[2] = 93;
	b[3] = 109;
	b[4] = 46;
	b[5] = 107;
	b[6] = 123;
	b[7] = 37;
	b[8] = 127;
	b[9] = 111;
	int d[N][8];
	int n, k;
	int x, y, z;
	int s;
	bool v = true;
	f(i,2010)ans[i] = 0;
	scanf("%d %d", &n, &k);
	f(i, n) {
		f(j, 10)aa[j] = 0;
		scanf("%s", aa);
		x = 1;
		a[i] = 0;
		f(j, 7) {
			if (aa[j] == '1')a[i] += x;
			x *= 2;
		}
	}
	f(i, n) {
		f(j, 10)d[i][j] = -1;
		f(j, 10) {
			if ((a[i] & b[j]) == a[i]) {
				x = b[j] - (a[i] & b[j]);
				y = 0;
				while (x > 0) {
					if (x % 2 == 1)y++;
					x /= 2;
				}
				d[i][y] = j;
			}
		}
	}
	f(i, 2010) {
		f(j, 2010)dp[i][j] = -1;
	}
	dp[n][k] = 0;
	for (int i = n - 1; i >= 0; i--) {
		f(j, k + 1) {
			if (dp[i + 1][j]>=0) {
				f(ii, 8) {
					if ((j - ii) >= 0) {
						if (d[i][ii] >= 0) {
							if (dp[i][j - ii] < d[i][ii]) {
								dp[i][j - ii] = d[i][ii];
								dp2[i][j - ii] = ii;
							}
						}
					}
				}
			}
		}
	}
	if (dp[0][0] < 0) {
		printf("-1\n");
		return 0;
	}
	x = 0;
	f(i, n) {
		ans[i] = '0' + dp[i][x];
		x += dp2[i][x];
	}
	printf("%s\n", ans);


	return 0;
}