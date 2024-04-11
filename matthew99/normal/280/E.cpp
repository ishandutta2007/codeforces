#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long LL;
const double eps = 1e-8;
const int maxn = 300000;
const int max0 = 1e6;
int n, q, a, b;
int x[maxn + 5];
struct node
{
	int k;
	LL b;
	double l, r;
	double delta;
	int deltak;
	LL deltab;
	node *p, *c[2];
	node(const int &_k = 0, const LL &_b = 0, const double &_l = 0, const double &_r = 0): k(_k), b(_b), l(_l), r(_r), delta(0), deltak(0), deltab(0), p(NULL) { memset(c, 0, sizeof c); }
	void flag_delta(const double &_delta)
	{
		delta += _delta;
		b -= (LL)k * _delta;
		deltab -= (LL)deltak * _delta;
		l += _delta, r += _delta;
	}
	void flag_add(const int &_deltak, const LL &_deltab)
	{
		deltak += _deltak, deltab += _deltab;
		k += _deltak, b += _deltab;
	}
	void push_down()
	{
		REP(i, 0, 2)
			if (c[i]) c[i]->flag_delta(delta), c[i]->flag_add(deltak, deltab);
		delta = 0, deltak = deltab = 0;
	}
	int get_pos()
	{
		if (!this || !p) return 2;
		REP(i, 0, 2) if (p->c[i] == this) return i;
		return 2;
	}
	void setc(node *u, const int &kind)
	{
		if (this && kind < 2) c[kind] = u;
		if (u) u->p = this;
	}
	void rotate()
	{
		node *p = this->p;
		bool mark = get_pos();
		p->p->setc(this, p->get_pos());
		p->setc(c[mark ^ 1], mark);
		setc(p, mark ^ 1);
	}
	bool is_root()
	{
		return get_pos() >= 2;
	}
	void relax()
	{
		static node *tmp[maxn + 5];
		int top = 0;
		node *u = this;
		while (!u->is_root()) tmp[top++] = u, u = u->p;
		u->push_down();
		while (top) tmp[--top]->push_down();
	}
	void splay()
	{
		for ( ; !is_root(); rotate())
			if (!p->is_root()) (p->get_pos() == get_pos() ? p : this)->rotate();
	}
	void print()
	{
		if (!this) return;
		push_down();
		c[0]->print();
		debug("%lf %lf: %d %I64d\n", l, r, k, b);
		c[1]->print();
	}
};
const double oo = 1e100;
double best[maxn + 5];
node mem[max0 + 5];
int mem_calc = 0;
node *rt;
node *new_node(const int &_k = 0, const LL &_b = 0, const double &_l = 0, const double &_r = 0) { mem[mem_calc] = node(_k, _b, _l, _r); return mem + (mem_calc++); }
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d%d", &n, &q, &a, &b);
	REP(i, 0, n) scanf("%d", x + i);
	rt = new_node(2, -x[0] << 1, 1, oo);
	FOR(i, 1, n)
	{
		node *u = rt;
		while (1)
		{
			u->push_down();
			double left = u->k * u->l + u->b, right = u->k * u->r + u->b;
			if (left > eps && u->c[0]) u = u->c[0];
			else if (right < -eps && u->c[1]) u = u->c[1];
			else break;
		}
		u->splay();
		rt = u;
		double t = min(u->r, max(u->l, (double)-u->b / u->k));
		LL val = 0;
		bool flag0 = 0, flag1 = 0;
		if (abs(t - u->r) < eps) val = u->r * u->k + u->b, flag0 = 1;
		if (abs(t - u->l) < eps) val = u->l * u->k + u->b, flag1 = 1;
		best[i - 1] = t;
		if (i >= n) break;
		double tmp0 = u->r;
		u->r = t;
		node *tmp = u->c[1];
		u->setc(new_node(u->k, u->b - flag0 * val, t, tmp0), 1);
		if (flag1) u->b -= val;
		u->c[1]->setc(tmp, 1);
		tmp = u->c[1];
		u->setc(new_node(0, 0, t, t + b - a), 1);
		u->c[1]->setc(tmp, 1);
		tmp->flag_delta(b - a);
		u->flag_delta(a);
		u->flag_add(2, -x[i] << 1);
	}
	double cur = min((double)q, best[n - 1]);
	static double ans[maxn + 5];
	double tot = 0;
	ans[n - 1] = cur;
	for (int i = n - 2; i >= 0; --i)
	{
		double t = best[i];
		if (t + a > cur) cur -= a;
		else if (t + b < cur) cur -= b;
		else cur = t;
		ans[i] = cur;
	}
	REP(i, 0, n) printf("%.15lf ", ans[i]), (tot += (ans[i] - x[i]) * (ans[i] - x[i]));
	printf("\n");
	printf("%.15lf\n", tot);
	return 0;
}