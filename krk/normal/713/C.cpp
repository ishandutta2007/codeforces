#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 3005;
const ll Inf = 4000000000000000000ll;

int n;
int a[Maxn];
vector <int> un;
ll dp[Maxn][Maxn];
ll res = Inf;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); a[i] -= i;
		un.push_back(a[i]);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	fill((ll*)dp, (ll*)dp + Maxn * Maxn, Inf);
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		ll best = Inf;
		for (int j = 0; j < un.size(); j++) {
			best = min(best, dp[i][j]);
			dp[i + 1][j] = min(dp[i + 1][j], best + abs(a[i] - un[j]));
		}
	}
	for (int j = 0; j < un.size(); j++)
		res = min(res, dp[n][j]);
	printf("%I64d\n", res);
	return 0;
}