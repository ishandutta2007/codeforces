#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 2005;
const int Maxm = 40;
const ll Inf = 1000000000000000000ll;

int n;
int B[Maxn][Maxn];
ll dp[Maxm][Maxn], add;

int main()
{
	int mn = 1000000007;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			scanf("%d", &B[i][j]); B[j][i] = B[i][j];
			mn = min(mn, B[i][j]);
		}
	add = ll(n - 1) * mn;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) if (i != j)
			B[i][j] -= mn;
	int from = min(n - 1, Maxm - 1);
	for (int i = 0; i < n; i++) {
		dp[from][i] = Inf;
		for (int j = 0; j < n; j++) if (i != j) {
			ll cand = from == n - 1? B[i][j]: 2 * B[i][j];
			dp[from][i] = min(dp[from][i], cand);
		}
	}
	for (int i = from - 1; i >= 1; i--)
		for (int j = 0; j < n; j++) {
			dp[i][j] = Inf;
			for (int k = 0; k < n; k++) if (j != k)
				dp[i][j] = min(dp[i][j], min(2ll * B[j][k], B[j][k] + dp[i + 1][k]));
		}
	for (int i = 0; i < n; i++)
		printf("%I64d\n", dp[1][i] + add);
	return 0;
}