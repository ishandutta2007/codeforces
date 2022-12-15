#include <bits/stdc++.h>

using namespace std;

#define N 222222

int n, m, acnt, bcnt, pa, pb, tot;
struct hp {
	int x, y, z, cnt, id;
} f[N], a[N], b[N];
int C[N], cnt[N], ch[N], p1[N], p2[N], p3[N];

int p[N], s[N], d[N], inc[N], pref[N];

int cmp1(hp a, hp b)
{
	return a.x < b.x || (a.x == b.x && a.y < b.y)
	       || (a.x == b.x && a.y == b.y && a.z < b.z)
	       || (a.x == b.x && a.y == b.y && a.z == b.z && a.cnt > b.cnt);
}
int cmp2(hp a, hp b)
{
	return a.y < b.y;
}
void add(int loc, int val)
{
	if (!loc) return;
	for (int i = loc; i <= n + m; i += i & (-i))
		C[i] += val;
}
int query(int loc)
{
	int ans = 0;
	for (int i = loc; i >= 1; i -= i & (-i))
		ans += C[i];
	return ans;
}
void cdq(int l, int r)
{
	if (l >= r) return;
	int mid = (l + r) >> 1;
	cdq(l, mid);

	acnt = 0;
	for (int i = l; i <= mid; ++i) a[++acnt] = f[i];
	sort(a + 1, a + acnt + 1, cmp2);
	bcnt = 0;
	for (int i = mid + 1; i <= r; ++i) b[++bcnt] = f[i];
	sort(b + 1, b + bcnt + 1, cmp2);
	pa = pb = 1; tot = 0;
	while (pb <= bcnt)
	{
		while (pa <= acnt && a[pa].y <= b[pb].y)
		{
			if (a[pa].cnt)
			{
				add(a[pa].z, a[pa].cnt);
				ch[++tot] = a[pa].z;
			}
			++pa;
		}
		if (b[pb].cnt == 0)
			cnt[b[pb].id] += query(b[pb].z);
		++pb;
	}
	for (int i = 1; i <= tot; ++i)
		add(ch[i], -1);

	cdq(mid + 1, r);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &s[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &d[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &inc[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &pref[i]);
	auto discretize = [&](int *p, int *q, int *x) {
		vector<int> number;
		for (int i = 1; i <= n; i++)
			number.push_back(p[i]);
		for (int i = 1; i <= m; i++)
			number.push_back(q[i]);
		sort(number.begin(), number.end());
		number.erase(unique(number.begin(), number.end()), number.end());
		for (int i = 1; i <= n; i++)
			x[i] = lower_bound(number.begin(), number.end(), p[i]) -
			       number.begin() + 1;
		for (int i = 1; i <= m; i++)
			x[i + n] = lower_bound(number.begin(), number.end(), q[i]) -
			           number.begin() + 1;

	};
	for (int i = 1; i <= n; i++)
		p1[i] = p[i] + d[i];
	for (int i = 1; i <= m; i++)
		p2[i] = inc[i] + pref[i];
	discretize(p1, p2, p3);
	for (int i = 1; i <= n + m; i++)
		f[i].x = p3[i];
	for (int i = 1; i <= n; i++)
		p1[i] = p[i] - d[i];
	for (int i = 1; i <= m; i++)
		p2[i] = inc[i] - pref[i];
	discretize(p1, p2, p3);
	for (int i = 1; i <= n + m; i++)
		f[i].y = p3[i];
	for (int i = 1; i <= n; i++)
		p1[i] = -s[i];
	for (int i = 1; i <= m; i++)
		p2[i] = -inc[i];
	discretize(p1, p2, p3);
	for (int i = 1; i <= n + m; i++)
		f[i].z = p3[i];
	for (int i = 1; i <= n; ++i)
	{
		f[i].id = i;
		f[i].cnt = 1;
	}
	for (int i = 1; i <= m; ++i)
		f[i + n].id = i;
	sort(f + 1, f + n + m + 1, cmp1);
	cdq(1, n + m);
	for (int i = 1; i <= m; i++)
		printf("%d ", cnt[i]);

}