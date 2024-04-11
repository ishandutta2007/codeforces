#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 1000005;
const int Maxm = 4194304;

int n;
int seqa[Maxn], inb[Maxn];
int in[Maxn];
vector <int> st[Maxm];
int m;
int a, b, c, d;
int x;

void Create(int v, int l, int r)
{
	if (l == r) st[v].push_back(in[l]);
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		int i = 0, j = 0;
		while (i < st[2 * v].size() || j < st[2 * v + 1].size())
			if (i < st[2 * v].size() && (j == st[2 * v + 1].size() || st[2 * v][i] <= st[2 * v + 1][j]))
				st[v].push_back(st[2 * v][i++]);
			else st[v].push_back(st[2 * v + 1][j++]);
	}
}

int Get(int v, int l, int r, int a1, int a2, int b1, int b2)
{
	int res = 0;
	if (l == a1 && r == a2) res = upper_bound(st[v].begin(), st[v].end(), b2) - lower_bound(st[v].begin(), st[v].end(), b1);
	else {
		int m = l + r >> 1;
		if (a1 <= m) res += Get(2 * v, l, m, a1, min(m, a2), b1, b2);
		if (m + 1 <= a2) res += Get(2 * v + 1, m + 1, r, max(m + 1, a1), a2, b1, b2);
	}
	return res;
}

int f(int z) { return (z - 1 + x + n) % n + 1; }

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &seqa[i]);
	for (int i = 1; i <= n; i++) {
		int b; scanf("%d", &b); inb[b] = i;
	}
	for (int i = 1; i <= n; i++) in[i] = inb[seqa[i]];
	Create(1, 1, n);
	scanf("%d", &m);
	while (m--) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int l1 = min(f(a), f(b)), r1 = max(f(a), f(b)), l2 = min(f(c), f(d)), r2 = max(f(c), f(d));
		x = Get(1, 1, n, l1, r1, l2, r2);
		printf("%d\n", x); x++;
	}
	return 0;
}