#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 400010;
const int MAXM = 26;

int n;
char s[MAXN];

int tot;
struct node
{
	int dis;
	node *pre, *next[MAXM];
}sa[MAXN], *root;

node *new_node()
{
	return &sa[++ tot];
}

// vertex[i] denotes the vertex corresponding to s[i..n] in the suffix tree
int vertex[MAXN];

// build suffix automaton of reversed(s),
// whose "pre" links form a suffix tree of s.
void build_sa()
{
	node *cur = root = new_node();
	for (int i = n; i >= 1; -- i)
	{
		int x = s[i]-'a';
		node *p = cur;
		cur = new_node();
		cur->dis = p->dis+1;
		vertex[i] = cur-sa;
		for (; p && !p->next[x]; p = p->pre)
			p->next[x] = cur;
		if (!p)
			cur->pre = root;
		else
		{
			node *q = p->next[x];
			if (q->dis == p->dis+1)
				cur->pre = q;
			else
			{
				node *r = new_node();
				*r = *q;
				r->dis = p->dis+1;
				cur->pre = q->pre = r;
				for (; p && p->next[x] == q; p = p->pre)
					p->next[x] = r;
			}
		}
	}
}

vector<int> v[MAXN];
int size[MAXN], son[MAXN], father[MAXN], pre[MAXN], dis[MAXN];

void dfs1(int x)
{
	size[x] = 1;
	if (v[x].empty()) return;
	for (auto y : v[x])
	{
		dfs1(y);
		size[x] += size[y];
	}
	son[x] = *max_element(v[x].begin(), v[x].end(), [&](int a, int b)
	{
		return size[a] < size[b];
	});
}

void dfs2(int x)
{
	if (!father[x]) father[x] = x;
	if (v[x].empty()) return;
	father[son[x]] = father[x];
	dfs2(son[x]);
	for (auto y : v[x])
		if (y != son[x]) dfs2(y);
}

// build suffix tree according to "sa",
// together with heavy-light decomposition.
void build_tree()
{
	for (int i = 1; i <= tot; ++ i)
	{
		pre[i] = sa[i].pre ? sa[i].pre-sa : 0;
		dis[i] = sa[i].dis;
		if (pre[i]) v[pre[i]].push_back(i);
	}
	dfs1(1);
	dfs2(1);
}

struct point
{
	int no, len, pos;
};
vector<point> p[MAXN];

void make_vertex(int v)
{
	int x = vertex[v];
	while (x > 1)
	{
		int y = father[x];
		p[y].push_back({v, dis[x]-dis[pre[y]], v+dis[pre[y]]+1});
		x = pre[y];
	}
}

int q;
struct query
{
	int id, len, bound;
	bool operator < (const query &A) const
	{
		return bound < A.bound;
	}
};
vector<query> q1[MAXN], q2[MAXN];

void make_query(int l, int len, int id)
{
	int x = vertex[l];
	while (x > 1)
	{
		int y = father[x];
		if (dis[pre[y]] < len)
		{
			q1[y].push_back({id, min(dis[x], len)-dis[pre[y]], l-1});
			q2[y].push_back({id, min(dis[x], len)-dis[pre[y]], l+len});
		}
		x = pre[y];
	}
}

int w[MAXN];
ll ww[MAXN];

void update(int p)
{
	for (int x = p; x < MAXN; x += x&-x)
	{
		w[x] += 1;
		ww[x] += p;
	}
}

void resume(int x)
{
	for (; x < MAXN; x += x&-x)
		ww[x] = w[x] = 0;
}

int getnum(int x)
{
	int p = 0;
	for (; x; x -= x&-x)
		p += w[x];
	return p;
}

ll getsum(int x)
{
	ll p = 0;
	for (; x; x -= x&-x)
		p += ww[x];
	return p;
}

ll ans[MAXN];

void solve(vector<point> &p, vector<query> &q1, vector<query> &q2)
{
	if (p.empty()) return;
	if (!q1.empty())
	{
		sort(p.begin(), p.end(), [](const point &a, const point &b)
		{
			return a.no < b.no;
		});
		sort(q1.begin(), q1.end());
		auto j = p.begin();
		int all = 0;
		for (auto i = q1.begin(); i != q1.end(); ++ i)
		{
			for (; j != p.end() && j->no <= i->bound; ++ j)
			{
				++ all;
				update(j->len);
			}
			int s = getnum(i->len); // resp. i->len-1
			ll t = getsum(i->len);  // resp. i->len-1
			ans[i->id] -= (ll)i->len*(all-s)+t;
		}
		for (auto j = p.begin(); j != p.end(); ++ j)
			resume(j->len);
	}
	if (!q2.empty())
	{
		sort(p.begin(), p.end(), [](const point &a, const point &b)
		{
			return a.pos+a.len < b.pos+b.len;
		});
		sort(q2.begin(), q2.end());
		auto j = p.begin();
		int all = 0;
		for (auto i = q2.begin(); i != q2.end(); ++ i)
		{
			for (; j != p.end() && j->pos+j->len <= i->bound+1; ++ j)
			{
				++ all;
				update(j->len);
			}
			int s = getnum(i->len); // resp. i->len-1
			ll t = getsum(i->len);  // resp. i->len-1
			ans[i->id] += (ll)i->len*(all-s)+t;
		}
		for (auto j = p.begin(); j != p.end(); ++ j)
			resume(j->len);

		reverse(p.begin(), p.end());
		reverse(q2.begin(), q2.end());
		j = p.begin();
		for (auto i = q2.begin(); i != q2.end(); ++ i)
		{
			for (; j != p.end() && j->pos+j->len > i->bound+1; ++ j)
				update(j->pos);
			int s = getnum(i->bound);
			ll t = getsum(i->bound);
			if (i->bound-i->len+1 <= 0)
				ans[i->id] += (ll)(i->bound+1)*s-t;
			else
			{
				int s1 = getnum(i->bound-i->len+1);
				ll t1 = getsum(i->bound-i->len+1);
				ans[i->id] += (ll)i->len*s1+(ll)(i->bound+1)*(s-s1)-(t-t1);
			}
		}
		for (auto j = p.begin(); j != p.end(); ++ j)
			resume(j->pos);
	}
}

void solve()
{
	for (int c = 1; c <= tot; ++ c)
		solve(p[c], q1[c], q2[c]);
}

int main()
{
	scanf("%s", s+1);
	n = strlen(s+1);
	build_sa();
	build_tree();
	for (int i = 1; i <= n; ++ i)
		make_vertex(i);
	scanf("%d", &q);
	for (int i = 1; i <= q; ++ i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		int len = y-x+1;
		make_query(x, len, i);
	}
	solve();
	for (int i = 1; i <= q; ++ i)
		printf("%lld\n", ans[i]);

	return 0;
}