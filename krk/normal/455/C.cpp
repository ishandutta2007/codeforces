#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")

using namespace std;

const int Maxn = 300005;

int n, m, q;
vector <int> neigh[Maxn];
int mx[Maxn][2], fromtop[Maxn];
int par[Maxn], siz[Maxn];
int l1[Maxn], l2[Maxn];
int best, head;

void Traverse(int v, int p, int col)
{
	par[v] = col; siz[col]++;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v, col);
		int cand = mx[u][0] + 1;
		if (cand > mx[v][0]) mx[v][1] = mx[v][0], mx[v][0] = cand;
		else if (cand > mx[v][1]) mx[v][1] = cand;
	}
}

void Traverse2(int v, int p, int ft)
{
	fromtop[v] = ft;
	int cand = mx[v][0] + max(ft, mx[v][1]);
	if (cand > best && abs(mx[v][0] - max(ft, mx[v][1])) <= 1) {
		best = cand; head = v;
	}
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		int candft = mx[v][0] == mx[u][0] + 1? mx[v][1]: mx[v][0];
		Traverse2(u, v, max(ft, candft) + 1);
	}
}

void makeElement(int col)
{
	Traverse(col, -1, col);
	best = -1;
	Traverse2(col, -1, 0);
	l1[col] = max(mx[head][0], fromtop[head]);
	l2[col] = l1[col] == mx[head][0]? max(fromtop[head], mx[head][1]): mx[head][0];
}

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

int getLen(int x) 
{
	x = getPar(x);
	return l1[x] + l2[x];
}

void unionSet(int x, int y)
{
	x = getPar(x), y = getPar(y);
	if (x == y) return;
	int nl1, nl2;
	if (l1[x] + l2[x] >= l1[x] + 1 + l1[y]) { nl1 = l1[x]; nl2 = l2[x]; }
	else if (l1[y] + l2[y] >= l1[y] + 1 + l1[x]) { nl1 = l1[y]; nl2 = l2[y]; }
	else {
		if (l1[x] < l1[y]) swap(x, y);
		nl1 = l1[y] + 1; nl2 = l1[x];
	}
	if (siz[x] >= siz[y]) { siz[x] += siz[y]; par[y] = x; l1[x] = nl1; l2[x] = nl2; }
	else { siz[y] += siz[x]; par[x] = y; l1[y] = nl1; l2[y] = nl2; }
}

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		if (!par[i]) makeElement(i);
	while (q--) {
		int typ, x, y; scanf("%d %d", &typ, &x);
		if (typ == 1) printf("%d\n", getLen(x));
		else {
			scanf("%d", &y);
			unionSet(x, y);
		}
	}
	return 0;
}