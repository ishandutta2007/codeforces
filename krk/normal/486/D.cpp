#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 2005;
const int mod = 1000000007;

int d, n;
int a[Maxn];
vector <int> neigh[Maxn];
int res;

int getAns(int v, int p, int r)
{
	if (a[v] > a[r] || a[v] < a[r] - d || a[v] == a[r] && v < r) return 0;
	int res = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		res = ll(res) * (1 + getAns(u, v, r)) % mod;
	}
	return res;
}

int main()
{
	scanf("%d %d", &d, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		res = (res + getAns(i, 0, i)) % mod;
	printf("%d\n", res);
	return 0;
}