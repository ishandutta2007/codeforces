#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 200005;
const int Maxm = 1048576;

int n, m;
int a[Maxn];
vector <int> neigh[Maxn];
int lvl[Maxn], ind[Maxn];
int cnt[2];
int l[Maxn][2], r[Maxn][2];
int st[2][Maxm];

void Traverse(int v, int p, int my)
{
	lvl[v] = my;
	l[v][0] = cnt[0]; l[v][1] = cnt[1];
	ind[v] = cnt[my]++;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v, 1 - my);
	}
	r[v][0] = cnt[0] - 1; r[v][1] = cnt[1] - 1;
}

void Update(int t, int v, int l, int r, int a, int b, int val)
{
	if (l == a && r == b) st[t][v] += val;
	else {
		int m = l + r >> 1;
		if (a <= m) Update(t, 2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) Update(t, 2 * v + 1, m + 1, r, max(m + 1, a), b, val);
	}
}

int Get(int t, int v, int l, int r, int x)
{
	int res = st[t][v];
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) res += Get(t, 2 * v, l, m, x);
		else res += Get(t, 2 * v + 1, m + 1, r, x);
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	Traverse(1, 0, 0);
	while (m--) {
		int op, x, val; scanf("%d %d", &op, &x);
		if (op == 1) {
			scanf("%d", &val);
			int my = lvl[x];
			if (l[x][my] <= r[x][my]) Update(my, 1, 0, cnt[my] - 1, l[x][my], r[x][my], val);
			my = 1 - my;
			if (l[x][my] <= r[x][my]) Update(my, 1, 0, cnt[my] - 1, l[x][my], r[x][my], -val);
		} else printf("%d\n", a[x] + Get(lvl[x], 1, 0, cnt[lvl[x]] - 1, ind[x]));
	}
	return 0;
}