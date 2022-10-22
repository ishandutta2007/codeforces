#include <cstdio>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 2005;
const int lim = 300000000;

int n, h;
ld p;
int x[Maxn];
ld dp[Maxn][Maxn][2][2];
int L[Maxn], R[Maxn];

ld Get(int l, int r, int f1, int f2)
{
	if (l > r) return 0.0;
	if (dp[l][r][f1][f2] < -0.5) {
		ld res = 0.0;
		int sL = x[l - 1] + (f1? h: 0);
		int sR = x[r + 1] - (f2? h: 0);

		res += 0.5 * p * (min(x[l] - sL, h) + Get(l + 1, r, 0, f2));
		int mylst = min(R[l] - 1, r);
		res += 0.5 * (1 - p) * (x[mylst] - x[l] + min(sR - x[mylst], h) + Get(mylst + 1, r, 1, f2));

		res += 0.5 * (1 - p) * (min(sR - x[r], h) + Get(l, r - 1, f1, 0));
		mylst = max(L[r] + 1, l);
		res += 0.5 * p * (x[r] - x[mylst] + min(x[mylst] - sL, h) + Get(l, mylst - 1, f1, 1));

		dp[l][r][f1][f2] = res;
	}
	return dp[l][r][f1][f2];
}

int main()
{
	scanf("%d %d", &n, &h); cin >> p;
	for (int i = 1; i <= n; i++)
		scanf("%d", &x[i]);
	sort(x + 1, x + n + 1);
	x[0] = -lim; x[n + 1] = lim;
	for (int i = 1; i <= n; i++)
		L[i] = x[i - 1] <= x[i] - h? i - 1: L[i - 1];
	for (int i = n; i >= 1; i--)
		R[i] = x[i] + h <= x[i + 1]? i + 1: R[i + 1];
	fill((ld*)dp, (ld*)dp + Maxn * Maxn * 2 * 2, -1.0l);
	cout << fixed << setprecision(10) << Get(1, n, 0, 0) << endl;
	return 0;
}