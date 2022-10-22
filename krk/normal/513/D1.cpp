#include <cstdio>
#include <cstring>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000005;
const int Maxm = 4194304;
const int Inf = 1000000000;

int n, c;
ii lef[Maxn], rig[Maxn];
int me[Maxn];
int res[Maxn], rlen;
int st[Maxm];

void Insert(int v, int l, int r, int x, int val)
{
	if (l == r) st[v] = val;
	else {
		int m = l + r >> 1;
		if (x <= m) Insert(2 * v, l, m, x, val);
		else Insert(2 * v + 1, m + 1, r, x, val);
		st[v] = max(st[2 * v], st[2 * v + 1]);
	}
}

int Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v];
	else {
		int res = -Inf;
		int m = l + r >> 1;
		if (a <= m) res = max(res, Get(2 * v, l, m, a, min(m, b)));
		if (m + 1 <= b) res = max(res, Get(2 * v + 1, m + 1, r, max(m + 1, a), b));
		return res;
	}
}

bool isNull(const ii &p) { return p == ii(Inf, -Inf); }

void Print(int l, int r)
{
	if (l > r) return;
	if (l == r) res[rlen++] = l;
	else {
		int from = l + 1;
		if (!isNull(lef[l])) { Print(l + 1, lef[l].second); from = lef[l].second + 1; }
		res[rlen++] = l;
		Print(from, r);
	}
}

int main()
{
	scanf("%d %d", &n, &c);
	for (int i = 1; i <= n; i++) {
		lef[i] = ii(Inf, -Inf);
		rig[i] = ii(Inf, -Inf);
	}
	int a, b;
	char s[10];
	while (c--) {
		scanf("%d %d %s", &a, &b, s);
		if (s[0] == 'L') { lef[a].first = min(lef[a].first, b); lef[a].second = max(lef[a].second, b); }
		else { rig[a].first = min(rig[a].first, b); rig[a].second = max(rig[a].second, b); }
	}
	for (int i = n; i >= 1; i--) {
		if (isNull(lef[i]) && isNull(rig[i])) me[i] = i;
		else if (isNull(lef[i]))
				if (rig[i].first <= i) { printf("IMPOSSIBLE\n"); return 0; }
				else me[i] = Get(1, 1, n, i + 1, rig[i].second);
		else if (isNull(rig[i]))
				if (lef[i].first <= i) { printf("IMPOSSIBLE\n"); return 0; }
				else {
					lef[i].second = Get(1, 1, n, i + 1, lef[i].second);
					me[i] = lef[i].second;
				}
		else if (lef[i].first <= i) { printf("IMPOSSIBLE\n"); return 0; }
			 else {
			 	lef[i].second = Get(1, 1, n, i + 1, lef[i].second);
			 	if (lef[i].second >= rig[i].first) { printf("IMPOSSIBLE\n"); return 0; }
			 	else me[i] = Get(1, 1, n, lef[i].second + 1, rig[i].second);
			 }
		Insert(1, 1, n, i, me[i]);
	}
	Print(1, n);
	for (int i = 0; i < rlen; i++)
		printf("%d%c", res[i], i + 1 < rlen? ' ': '\n');
	return 0;
}