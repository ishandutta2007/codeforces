#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 123;

int n, m;
struct Tree
{
	int l, r, val;
} a[N];
int sum[N][50], pref[N][50], ans[N][50];
int f[N], T[4 * N];

void build (int v = 1, int l = 1, int r = n)
{
	if (l == r)
	{
		T[v] = f[l];
		return;
	}
	int mid = (l + r) / 2;
	build (v << 1, l, mid);
	build (v << 1 | 1, mid + 1, r);
	T[v] = (T[v << 1] & T[v << 1 | 1]);
}
int get(int x, int y, int v = 1, int l = 1, int r = n)
{
	if (l > y || r < x) return (1 << 30) - 1;
	if (x <= l && r <= y) return T[v];
	int mid = (l + r) / 2;
	int ans = (1 << 30) - 1;
	ans &= get (x, y, v << 1, l, mid);
	ans &= get (x, y, v << 1 | 1, mid + 1, r);
	return ans;
}

int main ()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i ++)
	{
		cin >> a[i].l >> a[i].r >> a[i].val;
		for (int j = 0; j < 30; j ++)
			if ((a[i].val & (1 << j)))
			{
				sum[a[i].l][j] ++;
				sum[a[i].r + 1][j] --;
			}

	}
	for (int j = 0; j < 30; j ++)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i ++)
		{
			cnt += sum[i][j];
			if (cnt >= 1) ans[i][j] = 1;
			pref[i + 1][j] = pref[i][j] + ans[i][j];
		}
	}
	for (int i = 1; i <= n; i ++)
	{
		int cnt = 0;
		for (int j = 0; j < 30; j ++)
			if (ans[i][j])
				cnt += (1 << j);
		f[i] = cnt;
	}
	build ();
	for (int i = 1;  i <= m;  i ++)
		if (get (a[i].l, a[i].r) != a[i].val)
		{
			cout << "NO";
			return 0;
		}

	cout << "YES\n";
	for (int i = 1;  i <= n;  i ++) cout << f[i] << ' ';
	return 0;
}