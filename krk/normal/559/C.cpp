#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int mod = 1000000007;
const int Maxn = 2005;
const int Maxm = 200005;

int fac[Maxm], inv[Maxm];
int h, w, n;
ii rc[Maxn];
int dp[Maxn][2];

int Inv(int a)
{
	int p = mod - 2;
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int C(int n, int k)
{
	return ll(fac[n]) * inv[k] % mod * inv[n - k] % mod;
}

int Calc(int r1, int c1, int r2, int c2)
{
	return C(r2 - r1 + c2 - c1, r2 - r1);
}

int main()
{
	fac[0] = inv[0] = 1;
	for (int i = 1; i < Maxm; i++) {
		fac[i] = ll(i) * fac[i - 1] % mod;
		inv[i] = Inv(fac[i]);
	}
	scanf("%d %d %d", &h, &w, &n);
	rc[0] = ii(1, 1);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &rc[i].first, &rc[i].second);
	rc[n + 1] = ii(h, w);
	sort(rc, rc + n + 2);
	dp[0][1] = 1;
	for (int i = 1; i <= n + 1; i++)
		for (int j = 0; j < i; j++)
			if (rc[j].first <= rc[i].first && rc[j].second <= rc[i].second) {
				dp[i][0] = (dp[i][0] + ll(dp[j][1]) * Calc(rc[j].first, rc[j].second, rc[i].first, rc[i].second)) % mod;
				dp[i][1] = (dp[i][1] + ll(dp[j][0]) * Calc(rc[j].first, rc[j].second, rc[i].first, rc[i].second)) % mod;
			}
	printf("%d\n", (dp[n + 1][0] - dp[n + 1][1] + mod) % mod);
	return 0;
}