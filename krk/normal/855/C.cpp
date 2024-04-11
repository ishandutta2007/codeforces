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
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxx = 12;
const int mod = 1000000007;

int n, m;
vector <int> neigh[Maxn];
int k, x;
int dp[Maxn][3][Maxx];

void Traverse(int v, int p = 0)
{
	dp[v][0][0] = k - 1; dp[v][1][1] = 1; dp[v][2][0] = m - k;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v);
		for (int j = x; j >= 0; j--) {
			int was1 = dp[v][0][j], was2 = dp[v][1][j], was3 = dp[v][2][j];
			dp[v][0][j] = dp[v][1][j] = dp[v][2][j] = 0;
			for (int k = 0; j + k <= x; k++) {
				int add1 = (ll(dp[u][0][k]) + ll(dp[u][1][k]) + ll(dp[u][2][k])) % mod;
				int add2 = dp[u][0][k];
				int add3 = (dp[u][0][k] + dp[u][2][k]) % mod;
				dp[v][0][j + k] = (dp[v][0][j + k] + ll(add1) * was1) % mod;
				dp[v][1][j + k] = (dp[v][1][j + k] + ll(add2) * was2) % mod;
				dp[v][2][j + k] = (dp[v][2][j + k] + ll(add3) * was3) % mod;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	scanf("%d %d", &k, &x);
	Traverse(1);
	int res = 0;
	for (int j = 0; j < 3; j++)
		for (int l = 0; l <= x; l++)
			res = (res + dp[1][j][l]) % mod;
	printf("%d\n", res);
	return 0;
}