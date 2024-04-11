#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int mod = 1000000007;

int n;
vector <int> neigh[Maxn];
int x[Maxn];
int dp[Maxn][3];

void Calc(int v, int p)
{
	if (x[v] == 1) {
		dp[v][0] = 0;
		dp[v][1] = 1;
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (u == p) continue;
			Calc(u, v);
			dp[v][1] = ll(dp[v][1]) * dp[u][2] % mod;
		}
	} else {
		dp[v][0] = 1;
		dp[v][1] = 0;
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (u == p) continue;
			Calc(u, v);
			dp[v][1] = (ll(dp[v][1]) * dp[u][2] % mod + ll(dp[v][0]) * dp[u][1] % mod) % mod;
			dp[v][0] = ll(dp[v][0]) * dp[u][2] % mod;
		}
	}
	dp[v][2] = (dp[v][0] + dp[v][1]) % mod;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int p; scanf("%d", &p);
		neigh[i + 1].push_back(p);
		neigh[p].push_back(i + 1);
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	Calc(0, -1);
	printf("%d\n", dp[0][1]);
	return 0;
}