#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const int Maxn = 35005;
const int Maxm = 131072;
const int Maxk = 105;
const ll Inf = 2000000000;

int n, k;
int lst[Maxn];
ll mn[Maxk][Maxm], fl[Maxk][Maxm];

void downOn(int t, int v, ll f)
{
	mn[t][v] += f;
	fl[t][v] += f;
}

void Down(int t, int v)
{
	if (fl[t][v]) {
		downOn(t, 2 * v, fl[t][v]);
		downOn(t, 2 * v + 1, fl[t][v]);
		fl[t][v] = 0;
	}
}

void Union(int t, int v)
{
	mn[t][v] = min(mn[t][2 * v], mn[t][2 * v + 1]);
}

void Create(int t, int v, int l, int r)
{
	mn[t][v] = Inf;
	if (l < r) {
		int m = l + r >> 1;
		Create(t, 2 * v, l, m);
		Create(t, 2 * v + 1, m + 1, r);
	}
}

void updateOne(int t, int v, int l, int r, int x, ll val)
{
	if (l == r) mn[t][v] = val;
	else {
		int m = l + r >> 1;
		Down(t, v);
		if (x <= m) updateOne(t, 2 * v, l, m, x, val);
		else updateOne(t, 2 * v + 1, m + 1, r, x, val);
		Union(t, v);
	}
}

void updateMany(int t, int v, int l, int r, int a, int b, ll val)
{
	if (l == a && r == b) downOn(t, v, val);
	else {
		int m = l + r >> 1;
		Down(t, v);
		if (a <= m) updateMany(t, 2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) updateMany(t, 2 * v + 1, m + 1, r, max(m + 1, a), b, val);
		Union(t, v);
	}
}

ll Get(int t, int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return mn[t][v];
	else {
		int m = l + r >> 1;
		Down(t, v);
		if (b <= m) return Get(t, 2 * v, l, m, a, b);
		if (m + 1 <= a) return Get(t, 2 * v + 1, m + 1, r, a, b);
		return min(Get(t, 2 * v, l, m, a, m), Get(t, 2 * v + 1, m + 1, r, m + 1, b));
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	fill(lst, lst + Maxn, -1);
	for (int i = 1; i <= k; i++)
		Create(i, 1, 0, n);
	int a; scanf("%d", &a);
	lst[a] = 0;
	updateOne(1, 1, 0, n, 0, 0);
	for (int i = 1; i < n; i++) {
		scanf("%d", &a);
		for (int j = k; j >= 1; j--) {
			if (lst[a] != -1)
				updateMany(j, 1, 0, n, 0, lst[a], i - lst[a]);
			if (j > 1)
				updateOne(j, 1, 0, n, i, Get(j - 1, 1, 0, n, 0, i - 1));
		}
		lst[a] = i;
	}
	printf("%d\n", Get(k, 1, 0, n, 0, n));
    return 0;
}