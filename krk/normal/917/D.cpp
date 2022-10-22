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

typedef pair <int, int> ii;
typedef long long ll;

const int mod = 1000000007;
const int Maxn = 105;

int C[Maxn][Maxn];
int n;
vector <int> neigh[Maxn];
int cnt[Maxn];
int root;
int dp[Maxn][Maxn][Maxn];
int res[Maxn];

int Inv(int a)
{
	int res = 1;
	int p = mod - 2;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

void Count(int v, int p = 0)
{
	cnt[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Count(u, v); cnt[v] += cnt[u];
	}
}

int getCentroid(int v, int p, int siz)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		if (cnt[u] > siz / 2) return getCentroid(u, v, siz);
	}
	return v;
}

void Solve(int v, int p = 0)
{
	vector <ii> seq;
	cnt[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Solve(u, v); cnt[v] += cnt[u];
		seq.push_back(ii(cnt[u], u));
	}
	sort(seq.begin(), seq.end());
	int my = 1;
	dp[v][0][1] = 1;
	for (int i = 0; i < seq.size(); i++) {
		int u = seq[i].second;
		for (int j = my; j >= 0; j--)
			for (int k = my; k >= 0; k--) if (dp[v][j][k]) {
				int ways = dp[v][j][k]; dp[v][j][k] = 0;
				for (int j2 = 0; j2 <= cnt[u]; j2++)
					for (int k2 = 0; k2 <= cnt[u]; k2++) if (dp[u][j2][k2]) {
						dp[v][j + j2][k] = (dp[v][j + j2][k] + ll(ways) * ll(k2) % mod * n % mod * dp[u][j2][k2]) % mod;
						dp[v][j + j2 + 1][k + k2] = (dp[v][j + j2 + 1][k + k2] + ll(ways) * dp[u][j2][k2]) % mod;
					}
			}
		my += cnt[u];
	}
}

int main()
{
	for (int i = 0; i < Maxn; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Count(1);
	root = getCentroid(1, 0, n);
	Solve(root);
	int mult = Inv(n);
	mult = ll(mult) * mult % mod;
	for (int i = 0; i <= cnt[root]; i++)
		for (int j = 0; j <= cnt[root]; j++) if (dp[root][i][j])
			res[i] = (res[i] + ll(j) * n % mod * dp[root][i][j]) % mod;
	for (int i = n - 1; i >= 0; i--) {
		res[i] = ll(res[i]) * mult % mod;
		for (int j = i + 1; j < n; j++)
			res[i] = (res[i] - ll(res[j]) * C[j][i] % mod + mod) % mod;
	}
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	return 0;
}