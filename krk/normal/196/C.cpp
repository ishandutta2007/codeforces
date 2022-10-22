#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long double ld;
typedef pair <ld, int> di;

const int Maxn = 1505;

int n;
vector <int> neigh[Maxn];
int x[Maxn], y[Maxn];
int sum[Maxn];
vector <int> V;
int res[Maxn];

void getSums(int v, int p)
{
	sum[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		getSums(u, v);
		sum[v] += sum[u];
	}
}

void getRes(int v, int p, vector <int> &V)
{
	for (int i = 1; i < V.size(); i++)
		if (ii(x[V[i]], y[V[i]]) < ii(x[V[0]], y[V[0]])) swap(V[0], V[i]);
	res[V[0]] = v;
	vector <di> tosort;
	for (int i = 1; i < V.size(); i++)
		tosort.push_back(di(atan2(ld(y[V[i]] - y[V[0]]), ld(x[V[i]] - x[V[0]])), V[i]));
	sort(tosort.begin(), tosort.end());
	int pnt = 0;
	vector <int> tmp;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		tmp.clear();
		for (int j = 0; j < sum[u]; j++)
			tmp.push_back(tosort[pnt++].second);
		getRes(u, v, tmp);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; scanf("%d %d", &u, &v);
		neigh[u].push_back(v); neigh[v].push_back(u);
	}
	for (int i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);
	getSums(1, 0);
	for (int i = 0; i < n; i++) V.push_back(i);
	getRes(1, 0, V);
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	return 0;
}