#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 100;

struct Node
{
	bool a0, a1, rev;
	int lc, rc;
	Node() : a0(1), a1(0), rev(0), lc(0), rc(0) {}
};

int tot = 1, st = 0;
Node t[N * 200];
#define lch t[u].lc
#define rch t[u].rc

void pushup(int &u)
{
	if (lch && rch && t[lch].a0 && t[rch].a0) t[u].a0 = 1;
	else t[u].a0 = 0;
	if (lch && rch && t[lch].a1 && t[rch].a1) t[u].a1 = 1;
	else t[u].a1 = 0;
	assert(!t[u].rev);
}
inline void set0(int &u)
{
	if (!u) u = tot ++;
	t[u].a0 = 1, t[u].a1 = 0, t[u].rev = 0;
}
inline void set1(int &u)
{
	if (!u) u = tot ++;
	t[u].a1 = 1, t[u].a0 = 0, t[u].rev = 0;
}
inline void rev(int &u)
{
	if (!u) u = tot ++;
	if (t[u].rev)
	{
		t[u].rev = 0;
		return;
	}
	if (t[u].a0) return set1(u);
	if (t[u].a1) return set0(u);
	t[u].rev = 1;
}
void pushdown(int &u)
{
	if (t[u].a0) set0(lch), set0(rch);
	if (t[u].a1) set1(lch), set1(rch);
	if (t[u].rev)
	{
		rev(lch), rev(rch);
		t[u].rev = 0;
	}
}
void ins0(int &u, ll l, ll r, ll ql, ll qr)
{
	if (qr <= l || r <= ql) return;
	if (!u) u = tot++;
	if (ql <= l && r <= qr) return set0(u);
	pushdown(u);
	ll mid = (l + r) >> 1;
	ins0(lch, l, mid, ql, qr);
	ins0(rch, mid, r, ql, qr);
	pushup(u);
}
void ins1(int &u, ll l, ll r, ll ql, ll qr)
{
	if (qr <= l || r <= ql) return;
	if (!u) u = tot++;
	if (ql <= l && r <= qr) return set1(u);
	pushdown(u);
	ll mid = (l + r) >> 1;
	ins1(lch, l, mid, ql, qr);
	ins1(rch, mid, r, ql, qr);
	pushup(u);
}
void makerev(int &u, ll l, ll r, ll ql, ll qr)
{
	if (qr <= l || r <= ql) return;
	if (!u) u = tot ++;
	if (ql <= l && r <= qr) return rev(u);
	pushdown(u);
	ll mid = (l + r) >> 1;
	makerev(lch, l, mid, ql, qr);
	makerev(rch, mid, r, ql, qr);
	pushup(u);
}

ll ask(int &u, ll l, ll r)
{
	if (!u) return l;
	if (r - l == 1) return l;
	ll mid = (l + r) >> 1;
	pushdown(u);
	if (lch && t[lch].a1) return ask(rch, mid, r);
	ll ans = ask(lch, l, mid);
	pushup(u);
	return ans;
}

int q;
ll op, l, r;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int main()
{
	cin >> q;
	ll n = 1e18;
	n += 2;
	while (q --)
	{
		op = read();
		l = read1();
		r = read1();
		if (op == 1) ins1(st, 1, n, l, r + 1);
		if (op == 2) ins0(st, 1, n, l, r + 1);
		if (op == 3) makerev(st, 1, n, l, r + 1);
		cout << ask(st, 1, n) << endl;
	}
	return 0;
}