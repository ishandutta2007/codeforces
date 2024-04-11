#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 500000, maxm = 1000000;

struct edge
{
	int x, y, b;

	edge() { }
	edge(const int &_x, const int &_y, const int &_b): x(_x), y(_y), b(_b) { }

};

edge e[maxm + 5];
int n, m;

struct node
{
	node *c[2], *p;
	int e[2], E[2];
	bool rev;
	pair<int, int> Max;

	node(): p(NULL), rev(0), Max(mp(-1, -1)) { memset(c, 0, sizeof c), memset(e, -1, sizeof e), memset(E, -1, sizeof E); }

	void update()
	{
		Max = mp(-1, -1);
		REP(i, 0, 2)
			if (c[i]) Max = max(Max, max(c[i]->Max, mp(::e[e[i]].b, e[i]))), E[i] = c[i]->E[i];
			else E[i] = e[i];
	}

	void flag_rev()
	{
		rev ^= 1;
		swap(c[0], c[1]);
		swap(e[0], e[1]);
		swap(E[0], E[1]);
	}

	void push_down()
	{
		if (rev)
		{
			REP(i, 0, 2) if (c[i]) c[i]->flag_rev();
			rev = 0;
		}
	}

	int get_pos()
	{
		if (!this || !p) return 2;
		REP(i, 0, 2) if (p->c[i] == this) return i;
		return 2;
	}

	bool is_root()
	{
		return get_pos() >= 2;
	}

	void setc(node *u, const int &v)
	{
		if (this && v < 2) c[v] = u;
		if (u) u->p = this;
	}

	void rotate()
	{
		node *p = this->p;
		bool mark = get_pos();
		p->p->setc(this, p->get_pos());
		p->setc(c[mark ^ 1], mark);
		setc(p, mark ^ 1);
		p->update();
	}

	void relax()
	{
		static node *tmp[maxn + 5];
		int top = 0;
		node *u = this;
		while (!u->is_root()) tmp[top++] = u, u = u->p;
		u->push_down(); while (top) tmp[--top]->push_down();
	}

	void splay()
	{
		relax();
		for ( ; !is_root(); rotate())
			if (!p->is_root()) ((p->p->c[0] == p) == (p->c[0] == this) ? p : this)->rotate();
		update();
	}

	node *access()
	{
		node *u = this, *v = NULL;
		for ( ; u; v = u, u = u->p)
		{
			u->splay(), u->setc(v, 1); 
			if (v) u->e[1] = v->E[0];
			u->update();
		}
		splay();
		return v;
	}

	void be_root()
	{
		access();
		flag_rev();
	}

};

node v[maxn + 5];

vector<pair<int, int> > ans;

int to_del = -1;

void del(const int &x)
{
	node *a = v + e[x].x, *b = v + e[x].y;
	if (a == b) return;
	to_del = x;
	a->be_root(), b->access();
	b->setc(NULL, 0), a->p = NULL, b->update();
}

void link(const int &x)
{
	node *a = v + e[x].x, *b = v + e[x].y;
	if (a == b) return;
	a->be_root(), b->access();
	if (a->p)
	{
		int t = b->Max.y;
		if (e[t].b > e[x].b)
		{
			del(t);
			link(x);
		}
	}
	else a->p = b, a->e[0] = x, a->access();
}

set<pair<int, int> > all, all0;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	m = 0;
	REP(i, 0, n - 1)
	{
		scanf("%d%d", &e[m].x, &e[m].y), --e[m].x, --e[m].y, e[m].b = 1;
		if (e[m].x > e[m].y) swap(e[m].x, e[m].y);
		all.insert(mp(e[m].x, e[m].y));
		++m;
	}
	REP(i, 0, n - 1)
	{
		scanf("%d%d", &e[m].x, &e[m].y), --e[m].x, --e[m].y, e[m].b = 0;
		if (e[m].x > e[m].y) swap(e[m].x, e[m].y);
		all0.insert(mp(e[m].x, e[m].y));
		++m;
	}
	REP(i, 0, n - 1) if (all0.count(mp(e[i].x, e[i].y))) e[i].b = 0;
	REP(i, 0, n - 1) link(i);
	REP(i, n - 1, m) 
		if (!all.count(mp(e[i].x, e[i].y)))
		{
			link(i);
			ans.pb(mp(to_del, i));
		}
	printf("%d\n", SZ(ans));
	for (auto x : ans)
		printf("%d %d %d %d\n", e[x.x].x + 1, e[x.x].y + 1, e[x.y].x + 1, e[x.y].y + 1);
	return 0;
}