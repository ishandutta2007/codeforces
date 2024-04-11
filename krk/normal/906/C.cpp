#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Maxn = 22;
const int Inf = 100;

int n, m;
int know[Maxn];
int dp[1 << Maxn];
int par[1 << Maxn], wth[1 << Maxn];
vector <int> ans;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b); a--; b--;
		know[a] |= 1 << b;
		know[b] |= 1 << a;
	}
	int i = 0;
	while (i < n && __builtin_popcount(know[i]) >= n - 1) i++;
	if (i >= n) { printf("0\n"); return 0; } 
	fill(dp, dp + (1 << Maxn), Inf);
	for (int i = 0; i < n; i++)
		dp[1 << i] = 0;
	for (int i = 1; i < 1 << n; i++) if (dp[i] < Inf) {
		int cur = i;
		while (cur) {
			int b = (cur & -cur);
			int ind = __builtin_popcount(b - 1);
			int j = (i | know[ind]);
			if (dp[i] + 1 < dp[j]) {
				dp[j] = dp[i] + 1; par[j] = i; wth[j] = ind;
			}
			cur ^= b;
		}
	}
	int v = (1 << n) - 1;
	int res = dp[v];
	printf("%d\n", res);
	for (int i = 0; i < res; i++) {
		int wr = wth[v]; v = par[v];
		ans.push_back(wr + 1);
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		printf("%d%c", ans[i], i + 1 < ans.size()? ' ': '\n');
	return 0;
}