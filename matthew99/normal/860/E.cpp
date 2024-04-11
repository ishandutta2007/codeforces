#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) | rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 500100;

int n;
vector<int> chd[maxn + 5];
int fa[maxn + 5];

int dep[maxn + 5];

void dfs(int x)
{
	for (auto y : chd[x]) dep[y] = dep[x] + 1, dfs(y);
}

struct node
{
	node *c[2], *p;
	int label;
	LL sum;
	int val;
	int sz;

	node(): p(NULL), label(0), sum(0), val(0), sz(1) { memset(c, 0, sizeof c); }

	void update()
	{
		sum = val;
		sz = 1;
		REP(i, 0, 2) if (c[i]) sum += c[i]->sum, sz += c[i]->sz;
	}

	void flag_label(int _label)
	{
		label += _label;
		val += _label;
		sum += (LL)sz * _label;
	}

	void push_down()
	{
		if (label)
		{
			REP(i, 0, 2) if (c[i]) c[i]->flag_label(label);
			label = 0;
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
		node *_p = this->p;
		bool mark = get_pos();
		_p->p->setc(this, _p->get_pos());
		_p->setc(c[mark ^ 1], mark);
		setc(_p, mark ^ 1);
		_p->update();
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
		for ( ; u; v = u, u = u->p) u->splay(), u->setc(v, 1), u->update();
		splay();
		return v;
	}

};

node nd[maxn + 5];

vector<int> all[maxn + 5];

LL ans[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", fa + i), --fa[i];
	int rt = -1;
	REP(i, 0, n) 
		if (!~fa[i]) rt = i;
		else chd[fa[i]].pb(i);
	dep[rt] = 0;
	dfs(rt);
	REP(i, 0, n)
	{
		nd[i].val = 0;
		if (~fa[i]) nd[i].p = nd + fa[i]; else nd[i].p = NULL;
	}
	REP(i, 0, n) all[dep[i]].pb(i);
	REP(i, 0, n)
	{
		for (auto x : all[i])
		{
			node *u = nd + x;
			u->access();
			u->flag_label(1);
		}
		for (auto x : all[i])
		{
			node *u = nd + x;
			u->access();
			ans[x] = u->sum - dep[x] - 1;
		}
	}
	REP(i, 0, n) printf("%" LLFORMAT "d ", ans[i]);
	return 0;
}