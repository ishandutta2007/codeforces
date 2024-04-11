#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100010];
vector <int> I[100010], st[500010];
int q, res;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void Insert(int v, int l, int r, int a, int b, int val)
{
	if (l == a && r == b) st[v].push_back(val);
	else
	{
		int mid = l + r >> 1;
		if (a <= mid) Insert(2 * v, l, mid, a, min(mid, b), val);
		if (mid + 1 <= b) Insert(2 * v + 1, mid + 1, r, max(mid + 1, a), b, val);
	}
}

int Get(int v, int l, int r, int x, int R)
{
	int res = upper_bound(st[v].begin(), st[v].end(), R) - st[v].begin();
	if (l < r)
	{
		int mid = l + r >> 1;
		if (x <= mid) res += Get(2 * v, l, mid, x, R);
		else res += Get(2 * v + 1, mid + 1, r, x, R);
	}
	return res;
}

int main()
{
	n = read();
	k = read();
	for (int i = 1; i <= n; i ++)
	{
		a[i] = read();
		I[a[i]].push_back(i);
		if (I[a[i]].size() > k) Insert(1, 1, n, 1, I[a[i]][I[a[i]].size() - k - 1], i);
	}
	q = read();
	while (q--)
	{
		int x, y;
		x = read();
		y = read();
		x = (x + res) % n + 1;
		y = (y + res) % n + 1;
		if (x > y) swap(x, y);
		res = (y - x + 1) - Get(1, 1, n, x, y);
		printf("%d\n", res);
	}
	return 0;
}