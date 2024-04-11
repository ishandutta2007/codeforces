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

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 400100;

struct node
{
	node *c[2], *p;
	int Max;
	int val;

	node(): p(NULL), Max(0) { memset(c, 0, sizeof c); }

	void update()
	{
		Max = val;
		REP(i, 0, 2) if (c[i]) chkmax(Max, c[i]->Max);
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

	void splay()
	{
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

	node *find(int x)
	{
		if (!this || Max < x) return NULL;
		if (c[1] && c[1]->Max >= x) return c[1]->find(x);
		if (val >= x) return this;
		if (c[0]) return c[0]->find(x);
		return NULL;
	}

};


const int maxq = 400100, max0 = 19;

node nd[maxn + 5];

int fa[max0][maxq + 5];
LL sum[max0][maxq + 5];

int n;

int qn;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &qn);
	n = 1;
	nd[0].val = 0, nd[0].update();
	int last = 0;
	REP(i, 0, max0) fa[i][qn] = -1, sum[i][qn] = 0;
	fa[0][0] = qn, sum[0][0] = 0;
	REP(i, 1, max0) fa[i][0] = -1, sum[i][0] = 0;
	REP(i, 0, qn)
	{
		int ty;
		scanf("%d", &ty);
		LL p, q;
		scanf("%" LLFORMAT "d%" LLFORMAT "d", &p, &q);
		p ^= last, q ^= last;
		--p;
		if (ty == 1)
		{
			nd[n].p = nd + p;
			nd[n].val = q;
			nd[n].update();

			nd[p].access();
			node *tmp = nd[p].find(nd[n].val);
			if (tmp) tmp->splay();
			if (!tmp) fa[0][n] = qn;
			else fa[0][n] = tmp - nd;
			sum[0][n] = nd[n].val;

			REP(j, 1, max0)
				if (~fa[j - 1][n])
				{
					fa[j][n] = fa[j - 1][fa[j - 1][n]];
					sum[j][n] = sum[j - 1][n] + sum[j - 1][fa[j - 1][n]];
				}
				else fa[j][n] = -1, sum[j][n] = sum[j - 1][n];
			++n;
		}
		else
		{
			int cnt = 0;
			int cur = p;
			LL res = q;
			for (int j = max0 - 1; j >= 0; --j)
			{
				if (~fa[j][cur] && sum[j][cur] <= res) 
				{
					cnt += 1 << j;
					res -= sum[j][cur];
					cur = fa[j][cur];
				}
			}
			printf("%d\n", cnt);
			last = cnt;
		}
	}
	return 0;
}