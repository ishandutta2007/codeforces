#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxm = 10;

int n, k;
int add;
int res;
int from[Maxm][Maxm], len[Maxm];
bool vis[Maxm];
int cnt;

int getPow(int a, int p)
{
	if (p == 0) return 1;
	int tmp = getPow(a, p / 2);
	tmp = ll(tmp) * ll(tmp) % ll(mod);
	if (p % 2) tmp = ll(tmp) * ll(a) % ll(mod);
	return tmp;
}

void Visit(int v)
{
	vis[v] = true; cnt++;
	for (int i = 0; i < len[v]; i++) {
		int u = from[v][i];
		if (!vis[u]) Visit(u);
	}
}

void Go(int v)
{
	if (v > k) {
		if (len[1] == 0) return;
		fill(vis + 1, vis + k + 1, false); cnt = 0;
		for (int i = 0; i < len[1]; i++)
			if (!vis[from[1][i]]) Visit(from[1][i]);
		if (cnt == k) res = (res + add) % mod;
	} else for (int i = 1; i <= k; i++) {
		from[i][len[i]++] = v;
		Go(v + 1);
		len[i]--;
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	add = getPow(n - k, n - k);
	Go(1);
	printf("%d\n", res);
	return 0;
}