#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;
const int Maxm = 20;
const int Maxt = 524288;

int n;
int p[Maxn];
vector <int> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
int L[Maxn], P[Maxn][Maxm];
map <int, int> lvl[Maxt];
int m;

void Insert(int v, int l, int r, int pos, int val)
{
	lvl[v][val]++;
	if (l < r) {
		int m = l + r >> 1;
		if (pos <= m) Insert(2 * v, l, m, pos, val);
		else Insert(2 * v + 1, m + 1, r, pos, val);
	}
}

int Get(int v, int l, int r, int a, int b, int val)
{
	if (l == a && r == b) return lvl[v].count(val)? lvl[v][val]: 0;
	else {
		int res = 0;
		int m = l + r >> 1;
		if (a <= m) res += Get(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) res += Get(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
		return res;
	}
}

void Traverse(int v, int lvl)
{
	lef[v] = cur++;
	P[v][0] = p[v]; L[v] = lvl;
	Insert(1, 0, n - 1, lef[v], L[v]);
	for (int i = 0; i < neigh[v].size(); i++)
		Traverse(neigh[v][i], lvl + 1);
	rig[v] = cur - 1;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		if (p[i]) neigh[p[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		if (!p[i]) Traverse(i, 0);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	scanf("%d", &m);
	bool was = false;
	while (m--) {
		int v, p; scanf("%d %d", &v, &p);
		int ans;
		if (p > L[v]) ans = 0;
		else {
			int x = v;
			for (int i = Maxm - 1; i >= 0; i--)
				if (1 << i <= p) { x = P[x][i]; p -= 1 << i; }
			ans = Get(1, 0, n - 1, lef[x], rig[x], L[v]) - 1;
		}
		if (was) printf(" ");
		else was = true;
		printf("%d", ans);
	}
	printf("\n");
	return 0;
}