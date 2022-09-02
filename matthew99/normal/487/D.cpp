#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cctype>
#include <climits>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef long long LL;

const int maxn = 1e5;

const int max0 = 1e6;

int n, m;

struct data
{
	pair<int, int> a[10];

	data() { }
	data(char *s, const int &x)
	{
		REP(i, 0, m)
		{
			int u = i;
			static bool vis[10];
			memset(vis, 0, sizeof vis);
			while (u >= 0 && u < m && s[u] != '^') 
			{
				if (s[u] == '^') break;
				vis[u] = 1;
				u += s[u] == '>' ? 1 : -1;
				if (vis[u]) 
				{
					a[i] = mp(-2, -2);
					goto lyc;
				}
			}
			a[i] = mp(x, u);
lyc:;
		}
	}
};

struct node
{
	data val;

	node *c[2];

};

char a[maxn + 5][10];

data combine(const data &a, const data &b, const int &p)
{
	data ans;
	REP(i, 0, m)
	{
		pair<int, int> tmp = b.a[i];
		if (tmp.x == p && tmp.y >= 0 && tmp.y < m) ans.a[i] = a.a[tmp.y];
		else ans.a[i] = tmp;
	}
	return ans;
}

node nd[max0 + 5];

int cur = 0;

node *rt = NULL;

void insert(node *&rt, const int &x, const int &l = 0, const int &r = maxn)
{
	if (!rt) rt = nd + (cur++);
	if (r - l <= 1)
	{
		rt->val = data(a[x], x);
		return;
	}
	int mid = (l + r) >> 1;
	if (x < mid) insert(rt->c[0], x, l, mid);
	else insert(rt->c[1], x, mid, r);
	if (!rt->c[1]) rt->val = rt->c[0]->val;
	else rt->val = combine(rt->c[0]->val, rt->c[1]->val, mid);
}

data query(node *rt, const int &x, const int &l = 0, const int &r = maxn)
{
	if (r <= x) return rt->val;
	int mid = (l + r) >> 1;
	data ret = query(rt->c[0], x, l, mid);
	if (x > mid && rt->c[1]) ret = combine(ret, query(rt->c[1], x, mid, r), mid);
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	srand(time(NULL));
	int q;
	scanf("%d%d%d", &n, &m, &q);
	REP(i, 0, n)
	{
		scanf("%s", a[i]);
		insert(rt, i);
	}
	REP(i, 0, q)
	{
		char c[3];
		scanf("%s", c);
		if (c[0] == 'A')
		{
			static int x, y;
			scanf("%d%d", &x, &y);
			--x, --y;
			data t = query(rt, x + 1);
			pair<int, int> ans = t.a[y];
			if (!ans.x && ans.y >= 0 && ans.y < m) --ans.x;
			++ans.x, ++ans.y;
			printf("%d %d\n", ans.x, ans.y);
		}
		else
		{
			static int x, y;
			scanf("%d%d%s", &x, &y, c);
			--x, --y;
			a[x][y] = c[0];
			insert(rt, x);
		}
	}
	return 0;
}