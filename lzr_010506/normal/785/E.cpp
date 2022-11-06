#include <bits/stdc++.h>
#define ll long long
#define N 200010
using namespace std;
int cl[N * 100], cr[N * 100], sum[N * 100], tot;
int root[N], a[N], n, q;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

inline int lowbit(int i)
{
	return i & (-i);
}

void segadd(int &m, int l, int r, int x, int v)
{
	if(!m) m = ++ tot;
	sum[m] += v;
	if(l == r) return;
	int mid = (l + r) >> 1;
	if(x <= mid) segadd(cl[m], l, mid, x, v);
	else segadd(cr[m], mid + 1, r, x, v);
}

int segask(int m, int l, int r, int vl, int vr)
{
	if(!m) return 0;
	if(vl <= l && r <= vr) return sum[m];
	int res = 0, mid = (l + r) >> 1;
	if(vl <= mid) res += segask(cl[m], l, mid, vl, vr);
	if(vr > mid) res += segask(cr[m], mid + 1, r, vl, vr);
	return res;
}

void add(int x, int w, int v)
{
	while(x <= n)
	{
		segadd(root[x], 1, n, w, v);
		x += lowbit(x);
	}
}

int preask(int x, int vl, int vr)
{
	int ans = 0;
	if(vl <= x) ans += min(vr - vl + 1, x - vl + 1);
	while(x)
	{
		ans += segask(root[x], 1, n, vl, vr);
		x -= lowbit(x);
	}
	return ans;
}

int ask(int l, int r, int vl, int vr)
{
	if(l > r) return 0;
	if(vl > vr) return 0;
	return preask(r, vl, vr) - preask(l - 1, vl, vr);
}

int main()
{
	n = read();
	q = read();
	for(int i = 1; i <= n; i ++)
		a[i] = i;
	ll ans = 0;
	while(q --)
	{
		int x, y;
		x = read();
		y = read();
		if(x > y) swap(x, y);
		add(x, a[x], -1);
		add(y, a[y], -1);
		ans -= ask(x + 1, y - 1, 1, a[x] - 1);
		ans -= ask(x + 1, y - 1, a[y] + 1, n);
		swap(a[x], a[y]);
		add(x, a[x], 1);
		add(y, a[y], 1);
		ans += ask(x + 1, y - 1, 1, a[x] - 1);
		ans += ask(x + 1, y - 1, a[y] + 1, n);
		if(a[x] > a[y]) ans ++;
		else if(a[x] < a[y]) ans --;
		cout << ans << endl;
	}

	return 0;
}