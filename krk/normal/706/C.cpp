#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const ll Inf = 1000000000000000000ll;

char tmp[Maxn];
int c[Maxn];
int n;
string str[Maxn], inv[Maxn];
ll dp[Maxn][2];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	for (int i = 0; i < n; i++) {
		scanf("%s", tmp); str[i] = tmp;
		inv[i] = str[i];
		reverse(inv[i].begin(), inv[i].end());
	}
	fill((ll*)dp, (ll*)dp + Maxn * 2, Inf);
	dp[1][0] = 0; dp[1][1] = c[0];
	for (int i = 1; i < n; i++) {
		if (str[i - 1] <= str[i]) dp[i + 1][0] = min(dp[i + 1][0], dp[i][0]);
		if (inv[i - 1] <= str[i]) dp[i + 1][0] = min(dp[i + 1][0], dp[i][1]);
		if (str[i - 1] <= inv[i]) dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + c[i]);
		if (inv[i - 1] <= inv[i]) dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + c[i]);
	}
	ll res = min(dp[n][0], dp[n][1]);
	if (res >= Inf) printf("-1\n");
	else printf("%I64d\n", res);
	return 0;
}