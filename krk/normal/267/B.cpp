#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxm = 7;
const int Maxn = 105;

int n;
bool was[Maxm];
bool taken[Maxn];
vector <ii> neigh[Maxm];
vector <int> res;

void DFS(int v)
{
	was[v] = true;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (!was[u.first]) DFS(u.first);
	}
}

void Traverse(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (!taken[abs(u.second)]) { taken[abs(u.second)] = true; Traverse(u.first); res.push_back(u.second); }
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(ii(b, i)); neigh[b].push_back(ii(a, -i));
	}
	int comp = 0;
	for (int i = 0; i < Maxm; i++) if (!neigh[i].empty() && !was[i]) {
		comp++; DFS(i);
	}
	if (comp > 1) { printf("No solution\n"); return 0; }
	int v = -1, odd = 0;
	for (int i = 0; i < Maxm; i++)
		if (neigh[i].size() % 2) { odd++; v = i; }
		else if (v == -1 && !neigh[i].empty()) v = i;
	if (odd > 2) printf("No solution\n");
	else Traverse(v);
	for (int i = res.size() - 1; i >= 0; i--)
		printf("%d %c\n", abs(res[i]), res[i] < 0? '-': '+');
	return 0;
}