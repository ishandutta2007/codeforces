#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL power(LL x, LL y, LL m) {
	LL ret = 1;
	for (x %= m; y; y >>= 1) {
		if (y & 1) ret = ret * x % m;
		x = x * x % m;
	}
	return ret;
}
#define N 405

int n, m;

bool vis[N];
int ans;

void dfs(int x) {
	bool flag = false, LL, RR;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			flag = true;
			if (i > 1 && vis[i - 2] && !vis[i - 1]) LL = true, vis[i - 1] = 1;
			else LL = false;
			if (vis[i + 2] && !vis[i + 1]) RR = true, vis[i + 1] = 1;
			else RR = false;
			dfs(x + 1);
			vis[i] = false;
			if (LL) vis[i - 1] = false;
			if (RR) vis[i + 1] = false;
		}
	}
	if (!flag) {
		ans++;
		return;
	}
}

/*LL dp[N][N][2][2];
bool vis[N][N][2][2];
*/

LL fac[N], inv[N], C[N][N];
/*
LL solve(int step, int x, int l, int r) {
	if (l > r) swap(l, r);
	if (x == 1) return (step == 0 && l && r) || (step == 1 && (!l || !r));
	if (step > x || step <= 0) return 0;
	if (step == x && (l || r)) return l + r < 2;
	if (vis[step][x][l][r]) return dp[step][x][l][r];
	vis[step][x][l][r] = 1;
	LL &cur = dp[step][x][l][r]; cur = 0;
	for (int i = 2; i < x; i++) {
		for (int k = max(step - 1 - (x - i), (i - 1) / 2), ed = min(i - 1, step - 1 - (x - i) / 2); k <= ed; k++) {
			LL lpart = solve(k,  i - 1, l, 1);
			LL rpart = solve(step - 1 - k, x - i, 1, r);
			cur += lpart * rpart % m * C[step - 1][k];
		}
		cur %= m;
	}
	cur += solve(step - 1, x - 1, 1, r);
	cur += solve(step - 1,x - 1,  l, 1);
	cur %= m;
	return cur;
}

*/
LL f[N][N];

int main() {
	cin >> n >> m;
//	dfs(0);
//	cerr << ans << endl;
//	exit(0);
	time_t st = clock();
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % m;
	inv[n] = power(fac[n], m - 2, m);
	for (int i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % m;
	C[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			C[i][j] = fac[i] * inv[j] % m * inv[i - j] % m;
		}
	}

	f[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		f[i][i] = f[i - 1][i - 1] * 2 % m;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) if (f[i][j]) {
			for (int k = i + 2; k <= n; k++) {
				int right = k - i - 1;
				(f[k][j + right] += (f[i][j] * f[right][right]) % m * C[j + right][right]) %= m;
			}
		}
	}
	LL ans = f[n][n];

	for (int i = 2; i < n; i++) {
		int left = i - 1, right = n - i;
		for (int k = 0; right + k <= n; k++) {
			ans += f[left][k] * f[right][right] % m * C[right + k][k] % m;
		}
	}
	
	ans %= m;

//	LL ans = 0;
//	for (int i = 0; i <= n; i++) ans += f[n][i];
//	int useless = 0, useful = 0;

/*
	for (int step = 0; step <= n; step++)
		for (int x = step; x <= min(n, 2 * step + 1); x++) 
			for (int l = 0; l <= 1; l++) {
				for (int r = (x == n ? l : 1); r <= 1; r++) {
					LL &cur = dp[x][step][l][r]; cur = 0;
					if (x == 1) {cur = (step == 0 && l && r) || (step == 1 && (!l || !r)); continue;}
					if (step == x && (l || r)) {cur = (l + r < 2); continue;}
					for (int i = 2; i < x; i++) {
						for (int k = max(step - 1 - (x - i), (i - 1) / 2), ed = min(i - 1, step - 1 - (x - i) / 2); k <= ed; k++) {
							LL lpart = dp[i - 1][k][l][1];
							LL rpart = dp[x - i][step - 1 - k][r][1];
							cur += lpart * rpart % m * C[step - 1][k];
						}
						cur %= m;
					}
					cur += dp[x - 1][step - 1][l][1];
					cur += dp[x - 1][step - 1][r][1];
					cur %= m;
				}
			}

	LL ans = 0;
	for (int i = n / 2 + 1; i <= n; i++) ans += dp[n][i][0][0];
*/
	printf("%d\n", int(ans % m));
	//cerr << clock() - st << endl;
}