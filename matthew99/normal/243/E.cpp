#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cassert>
#include <vector>
#include <functional>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define BACK(x) ((x)[SZ(x) - 1])

using namespace std;

using LL=long long;

const int oo = 0x3f3f3f3f;

const int maxn = 500;
const int max0 = 1000000;

struct node
{
	bool ty = 0;//0 indicates P node. 1 indicates Q node.
	bool empty = 0, full = 0;
	vector<node*> child;

	node()=default;
	node(const bool &_ty): ty(_ty) { }
};

node nd[max0 + 5];
node *rt;

int cur = 0;

int n, m;

void work(node *x);

template<typename T> inline void clr(T &x)
{
	T all;
	all.clear();
	for (auto e : x) if (e - nd < m || !e->child.empty()) all.pb(e);
	x = all;
}

vector<node*> split(node *x)
{
	vector<node*> t;
	if (x->full || x->empty) { t.pb(x); return t; }
	if (x->ty)
	{
		int l = oo, r = -1;
		if (x->child[0]->empty || BACK(x->child)->full) reverse(ALL(x->child));
		REP(i, 0, SZ(x->child)) if (!x->child[i]->empty) l = min(l, i), r = max(r, i);
		vector<node*> new_child;
		REP(i, 0, SZ(x->child)) 
		{
			if (!x->child[i]->full && i > l && i < r) EXIT("NO");
			if (i < l || i > r) t.pb(x->child[i]);
			if (x->child[i]->full) t.pb(x->child[i]);
			else if (i == r)
			{
				auto tmp = split(x->child[i]);
				copy(ALL(tmp), back_inserter(t));
			}
			else if (i <= l) EXIT("NO");
		}
		return t;
	}
	else
	{
		vector<int> yyt, lyc;
		node *owaski = nd + (cur++), *zzj = nd + (cur++);
		owaski->ty = 0;
		zzj->ty = 0;
		t.pb(zzj);
		bool flag = 0;
		REP(i, 0, SZ(x->child))
			if (!x->child[i]->empty)
			{
				if (!x->child[i]->full)
				{
					if (flag) EXIT("NO");
					auto tmp = split(x->child[i]);	
					copy(ALL(tmp), back_inserter(t));
				}
				else zzj->child.pb(x->child[i]);
			}
			else owaski->child.pb(x->child[i]);
		t.pb(owaski);
		return t;
	}
}

void work(node *x)
{
	if (x->empty || x->full) return;
	if (x->ty)
	{
		int l = oo, r = -1;
		REP(i, 0, SZ(x->child)) if (!x->child[i]->empty) l = min(l, i), r = max(r, i);
		if (l == r)
		{
			work(x->child[l]);
			return;
		}
		vector<node*> new_child;
		REP(i, 0, SZ(x->child)) 
		{
			if (!x->child[i]->full && i > l && i < r) EXIT("NO");
			if (i < l || i > r) new_child.pb(x->child[i]);
			if (x->child[i]->full) new_child.pb(x->child[i]);
			else if (i == l)
			{
				auto tmp = split(x->child[i]);
				copy(tmp.rbegin(), tmp.rend(), back_inserter(new_child)); 
			}
			else if (i == r)
			{
				auto tmp = split(x->child[i]);
				copy(ALL(tmp), back_inserter(new_child)); 
			}
		}
		x->child = new_child;
	}
	else
	{
		vector<int> yyt;
		node *zzj = nd + (cur++), *lyc = nd + (cur++);
		zzj->ty = 0, lyc->ty = 1;
		int cnt = 0;
		vector<node*> new_child;
		new_child.pb(lyc);
		int tot = 0;
		REP(i, 0, SZ(x->child)) if (!x->child[i]->empty) ++tot;
		REP(i, 0, SZ(x->child))
			if (!x->child[i]->empty)
			{
				if (tot == 1)
				{
					work(x->child[i]);
					return;
				}
				if (!x->child[i]->full)
				{
					auto tmp = split(x->child[i]);
					if (!cnt) copy(tmp.rbegin(), tmp.rend(), back_inserter(lyc->child)), lyc->child.pb(zzj);
					else copy(ALL(tmp), back_inserter(lyc->child));
					++cnt;
					if (cnt > 2) EXIT("NO");
				}
				else zzj->child.pb(x->child[i]);
			}
			else new_child.pb(x->child[i]);
		if (!cnt) lyc->child.pb(zzj);
		x->child = new_child;
	}
}

void dfs(node *rt, char *s)
{
	if (rt - nd < m) 
	{
		rt->full = s[rt - nd] == '1', rt->empty = !rt->full;
		return;
	}
	if (rt->child.empty())
	{
		rt->full = 0, rt->empty = 1;
		return;
	}
	rt->full = 1, rt->empty = 1;
	REP(i, 0, SZ(rt->child))
	{
		dfs(rt->child[i], s);
		rt->empty &= rt->child[i]->empty;
		rt->full &= rt->child[i]->full;
	}
}

void deal(node *rt)
{
	if (rt - nd < m) return;
	for (auto &e : rt->child) 
	{
		deal(e);
		if (SZ(e->child) == 1) e = e->child[0];
	}
	clr(rt->child);
}

inline void add(char *s)
{
	dfs(rt, s);
	work(rt);
	while (SZ(rt->child) == 1 && rt->child[0] - nd >= m) rt = rt->child[0];
	deal(rt);
}

int pos[maxn + 5];
int cnt = 0;

void get(node *rt)
{
	if (rt - nd < m)
	{
		pos[cnt++] = rt - nd;
		return;
	}
	for (auto e : rt->child) get(e);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	static char s[maxn + 5][maxn + 5];
	scanf("%d", &n), m = n;
	rt = nd + m;
	rt->ty = 0;
	cur = m + 1;
	REP(i, 0, m) rt->child.pb(nd + i);
	REP(i, 0, n)
	{
		scanf("%s", s[i]);
		add(s[i]);
	}
	printf("YES\n");
	get(rt);
	REP(i, 0, n)
	{
		REP(j, 0, m) printf("%c", s[i][pos[j]]);
		printf("\n");
	}
	return 0;
}