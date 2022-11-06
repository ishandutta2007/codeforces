#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
#define eps 1e-9
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

namespace treap
{
	int root, sz;
	struct Node
	{
		ll sum[5];
		int rd, val, l, r, sz;
	}a[100010];

	void update(int now)
	{
		if(now == 0) return;
		a[now].sz = a[a[now].l].sz + a[a[now].r].sz + 1;
		int j = a[a[now].l].sz;
		j %= 5;
		rep(i, 0, 4) a[now].sum[i] = a[a[now].l].sum[i];
		rep(i, 0, 4)
		{
			j ++;
			if(j == 5) j = 0;
			a[now].sum[j] += a[a[now].r].sum[i];
		}
		a[now].sum[j] += (ll)a[now].val;
	}

	void lturn(int &now)
	{
		int p = a[now].r;
		a[now].r = a[p].l;
		a[p].l = now;
		a[p].sz = a[now].sz;
		now = p;
	}

	void rturn(int &now)
	{
		int p = a[now].l;
		a[now].l = a[p].r;
		a[p].r = now;
		a[p].sz = a[now].sz;
		now = p;
	}

	void insert(int &now, int x)
	{
		if(a[now].val == x) return;
		if(now == 0)
		{
			a[++ sz].val = x;
			a[sz].l = a[sz].r = 0;
			a[sz].rd = rand();
			rep(i, 1, 4) a[sz].sum[i] = 0;
			a[sz].sum[0] = x;
			a[sz].sz = 1;
			now = sz;
			return;
		}
		if(x < a[now].val)
		{
			insert(a[now].l, x);
			if(a[a[now].l].rd > a[now].rd) rturn(now), update(a[now].r);
		}
		else
		{
			insert(a[now].r, x);
			if(a[a[now].r].rd > a[now].rd) lturn(now), update(a[now].l);
		}
		update(now);
	}

	void del(int &now, int x)
	{
		if(now == 0) return;
		if(a[now].val == x)
		{
			if(a[now].l * a[now].r == 0) now = a[now].l + a[now].r;
			else if(a[a[now].l].rd < a[a[now].r].rd) rturn(now), del(now, x);
			else lturn(now), del(now, x);
		}
		else if(a[now].val < x) del(a[now].r, x);
		else del(a[now].l, x);
		update(now);
	}
};
using namespace treap;

int Q;
int main()
{
	srand(20010223);
	Q = read();
	while(Q --)
	{
		char s[5];
		int x;
		scanf("%s", s);
		if(s[0] == 'a') x = read(), insert(root, x);
		else if(s[0] == 'd') x = read(), del(root, x);
		else printf("%I64d\n", a[root].sum[2]);
	}

	return 0;
}