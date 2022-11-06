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


int main() {
	int dp[110][110][2];
	f(i, 110) {
		f(j, 110) {
			dp[i][j][0] = 10000;
			dp[i][j][1] = 10000;
		}
	}
	int a[N];
	f(i, N)a[i] = 0;
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	x = n / 2;
	y = n;
	f(i, n) {
		scanf("%d", &a[i]);
		if (a[i] != 0) {
			if (a[i] % 2 == 0)x--;
			y--;
		}
	}
	if (a[0] == 0) {
		if (x > 0)dp[0][x - 1][0] = 0;
		if ((y - x) > 0)dp[0][x][1] = 0;
		y--;
	}
	else if (a[0] % 2 == 0) {
		dp[0][x][0] = 0;
	}
	else {
		dp[0][x][1] = 0;
	}
	for(int i=1;i<n;i++) {
		if (a[i] == 0) {
			f(j, 100) {
				if (j > 0) {
					dp[i][j - 1][0] = min(dp[i - 1][j][0], dp[i - 1][j][1] + 1);
				}
				if ((y - j) > 0) {
					dp[i][j][1] = min(dp[i - 1][j][1], dp[i - 1][j][0] + 1);
				}
}
			y--;
		}
		else if (a[i] % 2 == 0) {
			f(j, 100) {
				dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1] + 1);
			}
		}
		else {
			f(j, 100) {
				dp[i][j][1] = min(dp[i - 1][j][1], dp[i - 1][j][0] + 1);
			}
		}
	}
	ans = min(dp[n - 1][0][0], dp[n - 1][0][1]);
	printf("%d\n", ans);


	return 0;
}