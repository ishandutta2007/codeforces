#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 10;
const int MaxN = 1 << Maxn;
const int Maxm = 100;

int n, m, k;
vector <int> neigh[Maxn];
ll dp[MaxN][MaxN];
ll res;

int Bits(int x)
{
	int res = 0;
	while (x) { res += x & 1; x >>= 1; }
	return res;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b); a--; b--;
		neigh[a].push_back(b); neigh[b].push_back(a);
		dp[1 << a | 1 << b][1 << a | 1 << b] = 1;
	}
	for (int i = 1; i < 1 << n; i++) if (Bits(i) > 2)
		for (int j = 1; j < 1 << n; j++) if ((i & j) == j) {
			int de = Bits(j);
			int l = 0;
			while (!(j & 1 << l)) l++;
			for (int z = 0; z < neigh[l].size(); z++) {
				int u = neigh[l][z];
				if (i & 1 << u && !(j & 1 << u)) dp[i][j] += dp[i ^ 1 << l][j ^ 1 << l] + dp[i ^ 1 << l][j ^ 1 << l ^ 1 << u];
			}
			if (i == (1 << n) - 1 && de == k) res += dp[i][j];
		}
	printf("%I64d\n", res);
	return 0;
}