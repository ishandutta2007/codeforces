#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxk = 1005;
const int Maxn = 12;

int n, m, k, w;
char B[Maxk][Maxn][Maxn];
vector <ii> W[Maxn * Maxn];
int comp, siz[Maxk], par[Maxk];
vector <int> neigh[Maxk];
bool taken[Maxk];
int res;

int Weight(int a, int b)
{
	int res = 0;
	for (int i = 0; i < n && res < n * m; i++)
		for (int j = 0; j < m && res < n * m; j++)
			res += B[a][i][j] != B[b][i][j]? w: 0;
	return res;
}

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (siz[a] >= siz[b]) { siz[a] += siz[b]; par[b] = a; }
	else { siz[b] += siz[a]; par[a] = b; }
	comp--;
}

void Print(int v, int p)
{
	taken[v] = true;
	printf("%d %d\n", v, p);
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (!taken[u]) Print(u, v);
	}
}

int main()
{
	scanf("%d %d %d %d", &n, &m, &k, &w);
	for (int i = 1; i <= k; i++)
		for (int j = 0; j < n; j++)
			scanf("%s", B[i][j]);
	for (int i = 1; i <= k; i++) {
		siz[i] = 1; par[i] = i;
		for (int j = i + 1; j <= k; j++) {
			int got = Weight(i, j);
			if (got < n * m) W[got].push_back(ii(i, j));
		}
	}
	comp = k;
	for (int i = 0; i < n * m; i++)
		for (int j = 0; j < W[i].size(); j++) {
			int a = W[i][j].first, b = W[i][j].second;
			if (getPar(a) != getPar(b)) {
				unionSet(a, b); 
				res += i;
				neigh[a].push_back(b); neigh[b].push_back(a);
			}
		}
	res += comp * n * m;
	printf("%d\n", res);
	for (int i = 1; i <= k; i++)
		if (!taken[i]) Print(i, 0);
	return 0;
}