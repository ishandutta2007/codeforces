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
 
#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif
 
template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
 
typedef long long LL;
 
const int Mod = 1e9 + 7;
 
const int oo = 0x3f3f3f3f;
const LL OO = 0x3f3f3f3f3f3f3f3fLL;

template<typename T> inline T &Read(T &x)
{
	static char c;
	while (1) 
	{ 
		c = getchar(); 
		if (c == '-' || (c >= '0' && c <= '9')) break; 
	}
	bool flag = c == '-';
	x = flag ? 0 : c - '0';
	while (1)
	{
		c = getchar();
		if (c < '0' || c > '9') break;
		(x *= 10) += c - '0';
	}
	if (flag) x = -x;
	return x;
}

const int maxn = 100000, maxm = 300000;

struct Edge
{
	int x, y, z;

	Edge() { }
	Edge(int _x, int _y, int _z): x(_x), y(_y), z(_z) { }

};

Edge ed[maxm + 5];

struct node
{
	node *c[2], *p;
	int e[2], E[2];
	int val;
	int sz_tree;
	int sz;
	bool rev;
	int Max;

	node(): p(NULL), val(0), sz_tree(0), sz(1), rev(0), Max(-1) { memset(c, 0, sizeof c), memset(e, -1, sizeof e), memset(E, -1, sizeof E); }

	void update()
	{
		Max = -1;
		sz_tree = val;
		sz = 1;
		REP(i, 0, 2)
			if (c[i]) 
			{
				sz_tree += c[i]->sz_tree;
				sz += c[i]->sz;
				if (Max == -1 || (c[i]->Max != -1 && ed[c[i]->Max].z > ed[Max].z)) Max = c[i]->Max;
				if (Max == -1 || (e[i] != -1 && ed[e[i]].z > ed[Max].z)) Max = e[i];
				E[i] = c[i]->E[i];
			}
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

	void setc(node *u, const int &nd)
	{
		if (this && nd < 2) c[nd] = u;
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
			u->splay(); 
			if (u->c[1]) u->val += u->c[1]->sz_tree + u->c[1]->sz;
			u->setc(v, 1); 
			if (v) u->e[1] = v->E[0], u->val -= v->sz_tree + v->sz;
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

node nd[maxn + 5];

int n, m;

int in[maxm + 5];

int cnt_odd;

inline void add(int x, int y)
{
	in[x] += y;
}

inline void del(const int &x)
{
	node *a = nd + ed[x].x, *b = nd + ed[x].y;
	if (a == b) return;
	a->be_root(), b->access();
	add(x, -1);
	cnt_odd += (!((b->sz_tree + b->sz) & 1) && ((b->val + 1) & 1)) << 1;
	b->setc(NULL, 0), a->p = NULL, b->update();
}

inline bool try_del(const int &x)
{
	node *a = nd + ed[x].x, *b = nd + ed[x].y;
	if (a == b) return 1;
	a->be_root(), b->access();
	if ((b->val + 1) & 1) return 0;
	add(x, -1);
	b->setc(NULL, 0), a->p = NULL, b->update();
	return 1;
}

inline void link(const int &x)
{
	node *a = nd + ed[x].x, *b = nd + ed[x].y;
	if (a == b) return;
	a->be_root(), b->access();
	if (a->p)
	{
		int t = b->Max;
		if (ed[t].z > ed[x].z)
		{
			del(t);
			link(x);
		}
	}
	else 
	{
		cnt_odd -= (((a->sz_tree + a->sz) & 1) && ((b->sz_tree + b->sz) & 1)) << 1;
		add(x, 1);
		a->p = b, a->e[0] = x, b->val += a->sz + a->sz_tree, a->access();
	}
}

int pos[maxm + 5], rk[maxm + 5];

inline bool cmp(int x, int y)
{
	return ed[x].z > ed[y].z;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Read(n), Read(m);
	REP(i, 0, m)
	{
		pos[i] = i;
		int x, y, z;
		Read(x), Read(y), Read(z), --x, --y;
		ed[i] = Edge(x, y, z);
	}
	sort(pos, pos + m, cmp);
	REP(i, 0, m) rk[pos[i]] = i;
	int j = 0;
	cnt_odd = n;
	REP(i, 0, m)
	{
		if (rk[i] >= j) 
		{
			link(i);
			if (!cnt_odd)
			{
				while (1)
				{
					if (in[pos[j]] && !try_del(pos[j])) break;
					++j;
				}
			}
		}
		if (cnt_odd) printf("-1\n");
		else printf("%d\n", ed[pos[j]].z);
	}
	return 0;
}