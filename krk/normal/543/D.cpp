#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 1000000007;

int n;
vector <int> neigh[Maxn];
int has[Maxn];
vector <int> L[Maxn], R[Maxn];
int res[Maxn];

void Traverse(int v)
{
	has[v] = 1;
	if (neigh[v].size()) {
		L[v].resize(neigh[v].size()); R[v].resize(neigh[v].size());
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			Traverse(u);
			int ways = (has[u] + 1) % mod;
			has[v] = ll(has[v]) * ways % mod;
			L[v][i] = has[v];
		}
		for (int i = int(neigh[v].size()) - 1; i >= 0; i--) {
			int u = neigh[v][i];
			R[v][i] = i + 1 == neigh[v].size()? (has[u] + 1) % mod: ll(has[u] + 1) * R[v][i + 1] % mod;
		}
	}
}

void Traverse2(int v, int hastop = 1)
{
	res[v] = ll(has[v]) * hastop % mod;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		int gv = hastop;
		if (i) gv = ll(gv) * L[v][i - 1] % mod;
		if (i + 1 < neigh[v].size()) gv = ll(gv) * R[v][i + 1] % mod;
		Traverse2(u, (gv + 1) % mod);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int p; scanf("%d", &p);
		neigh[p].push_back(i);
	}
	Traverse(1);
	Traverse2(1);
	for (int i = 1; i <= n; i++)
		printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
	return 0;
}