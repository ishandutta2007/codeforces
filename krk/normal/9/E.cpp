#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 52;

int n, m;
vector <ii> neigh[Maxn];
int taken[Maxn];
int p[Maxn], siz[Maxn];
vector <ii> res;

void Take(int v)
{
	if (taken[v]) return;
	taken[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++)
		Take(neigh[v][i].first);
}

bool Done()
{
	fill(taken, taken + n + 1, 0);
	int comp = 0;
	for (int i = 1; i <= n && comp <= 1; i++)
		if (!taken[i]) { Take(i); comp++; }
	if (comp > 1) return false;
	for (int i = 1; i <= n; i++)
		if (neigh[i].size() != 2) return false;
	return true;
}

bool inCycle(int v, int p)
{
	if (taken[v] == 1) return true;
	if (taken[v] == 2) return false;
	taken[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (p != u.second && inCycle(u.first, u.second)) return true;
	}
	taken[v] = 2;
	return false;
}

bool canEvolve()
{
	if (m >= n) return false;
	fill(taken, taken + n + 1, 0);
	for (int i = 1; i <= n; i++)
		if (!taken[i] && inCycle(i, -1)) return false;
	for (int i = 1; i <= n; i++)
		if (neigh[i].size() > 2) return false;
	return true;
}

int getPar(int x) { return p[x] == x? x: p[x] = getPar(p[x]); }

void unionSet(int a, int b)
{
	int para = getPar(a), parb = getPar(b);
	if (siz[para] >= siz[parb]) { siz[para] += siz[parb]; p[parb] = para; }
	else { siz[parb] += siz[para]; p[para] = parb; }
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) { p[i] = i; siz[i] = 1; }
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d %d", &x, &y);
		neigh[x].push_back(ii(y, i)); neigh[y].push_back(ii(x, i));
	}
	if (Done()) {
		printf("YES\n");
		printf("0\n");
	} else if (canEvolve()) {
		printf("YES\n");
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < neigh[i].size(); j++) {
				int u = neigh[i][j].first;
				if (getPar(i) != getPar(u)) unionSet(i, u);
			}
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (neigh[i].size() <= 1 && neigh[j].size() <= 1 && getPar(i) != getPar(j)) { 
					unionSet(i, j); 
					neigh[i].push_back(ii(j, m)); neigh[j].push_back(ii(i, m)); 
					res.push_back(ii(i, j)); 
				}
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) 
				if (neigh[i].size() <= 1 && neigh[j].size() <= 1) {
					neigh[i].push_back(ii(j, m)); neigh[j].push_back(ii(i, m)); 
					res.push_back(ii(i, j));
				}
		for (int i = 1; i <= n; i++) if (neigh[i].size() == 0)
			res.push_back(ii(i, i));
		sort(res.begin(), res.end());
		printf("%d\n", res.size());
		for (int i = 0; i < res.size(); i++)
			printf("%d %d\n", res[i].first, res[i].second);
	} else printf("NO\n");
	return 0;
}