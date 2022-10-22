#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;
const int Maxm = 1048576;
const int Maxb = 20;

int n;
int N;
int a[Maxn];
ii my[Maxb][Maxn];
ii st[Maxb][Maxm];

ii Union(const ii &a, const ii &b)
{
	return ii(min(a.first, b.first), max(a.second, b.second));
}

void Create(int t, int v, int l, int r)
{
	if (l == r) st[t][v] = ii(my[t][l].first, my[t][l].second);
	else {
		int m = l + r >> 1;
		Create(t, 2 * v, l, m);
		Create(t, 2 * v + 1, m + 1, r);
		st[t][v] = Union(st[t][2 * v], st[t][2 * v + 1]);
	}
}

ii Get(int t, int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[t][v];
	else {
		int m = l + r >> 1;
		if (b <= m) return Get(t, 2 * v, l, m, a, b);
		if (m + 1 <= a) return Get(t, 2 * v + 1, m + 1, r, a, b);
		return Union(Get(t, 2 * v, l, m, a, m), Get(t, 2 * v + 1, m + 1, r, m + 1, b));
	}
}

int main()
{
	scanf("%d", &n); N = 3 * n;
	if (n == 1) { printf("0\n"); return 0; }
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[n + i] = a[2 * n + i] = a[i];
	}
	for (int i = 0; i < N; i++)
		my[0][i] = ii(max(i - a[i], 0), min(i + a[i], N - 1));
	for (int b = 0; b + 1 < Maxb; b++) {
		Create(b, 1, 0, N - 1);
		for (int i = 0; i < N; i++)
			my[b + 1][i] = Get(b, 1, 0, N - 1, my[b][i].first, my[b][i].second);
	}
	for (int i = n; i < n + n; i++) {
		ii cur = ii(i, i);
		int res = 1;
		for (int j = Maxb - 2; j >= 0; j--) {
			ii nw = Get(j, 1, 0, N - 1, cur.first, cur.second);
			if (nw.second - nw.first + 1 < n) {
				res += 1 << j;
				cur = nw;
			}
		}
		printf("%d%c", res, i + 1 < n + n? ' ': '\n');
	}
    return 0;
}