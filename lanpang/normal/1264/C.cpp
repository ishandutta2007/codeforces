#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 998244353;
const int N = 2e5 + 5;

ll p[N], invp[N];

int n, q;

ll qpow(ll a, ll b)
{
	ll ret = 1;	
	for (; b; (a *= a) %= MOD, b >>= 1)
		if (b & 1)
			(ret *= a) %= MOD;
	return ret;
}

ll inv(ll x) { return qpow(x, MOD - 2); }

#define lc(o) (o << 1)
#define rc(o) (o << 1 | 1)

struct Mat
{
	ll w[2][2];
}tr[N << 2];

Mat operator *(const Mat &a, const Mat &b)
{
	Mat ret; ret.w[0][0] = ret.w[0][1] = ret.w[1][0] = ret.w[1][1] = 0;
	for (int k = 0; k < 2; k++)
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				(ret.w[i][j] += a.w[i][k] * b.w[k][j] % MOD) %= MOD;
	return ret;
}

void build(int o, int l, int r)
{
	if (l == r)
	{
		tr[o].w[0][0] = tr[o].w[0][1] = invp[l];
		tr[o].w[1][0] = 0;
		tr[o].w[1][1] = 1;
		return;
	}
	int m = (l + r) >> 1;
	build(lc(o), l, m);
	build(rc(o), m + 1, r);
	tr[o] = tr[rc(o)] * tr[lc(o)];
}

Mat qry(int o, int ql, int qr, int l, int r)
{
	if (l >= ql && r <= qr)
		return tr[o];
	int m = (l + r) >> 1;
	if (qr <= m)
		return qry(lc(o), ql, qr, l, m);
	else if (ql > m)
		return qry(rc(o), ql, qr, m + 1, r);
	else
		return qry(rc(o), ql, qr, m + 1, r) * qry(lc(o), ql, qr, l, m);
}

inline void add(ll &a, ll b)
{
	(a += b) %= MOD;	
}

inline void sub(ll &a, ll b)
{
	(a += MOD - b) %= MOD;
}

int main()
{
	scanf("%d%d", &n, &q);
	ll inv100 = inv(100);
	for (int i = 1; i <= n; i++)
	{
		scanf("%I64d", &p[i]);
		p[i] = p[i] * inv100 % MOD;
		invp[i] = inv(p[i]);
	}
	build(1, 1, n);
	Mat mat, ret; mat.w[0][0] = mat.w[0][1] = mat.w[1][1] = 0, mat.w[1][0] = 1;
	ret = tr[1] * mat;
	ll res = ret.w[0][0];
	set<int> s;
	s.insert(1); s.insert(n + 1);
	for (int i = 1; i <= q; i++)
	{
		int u, x, y; scanf("%d", &u);
		if (s.count(u))
		{
			s.erase(u);
			auto it = s.upper_bound(u); y = *it; --it; x = *it;
			ret = qry(1, u, y - 1, 1, n) * mat; sub(res, ret.w[0][0]);
			ret = qry(1, x, u - 1, 1, n) * mat; sub(res, ret.w[0][0]);
			ret = qry(1, x, y - 1, 1, n) * mat; add(res, ret.w[0][0]);
		}
		else
		{
			auto it = s.upper_bound(u); y = *it; --it; x = *it;
			s.insert(u);
			ret = qry(1, x, y - 1, 1, n) * mat; sub(res, ret.w[0][0]);
			ret = qry(1, u, y - 1, 1, n) * mat; add(res, ret.w[0][0]);
			ret = qry(1, x, u - 1, 1, n) * mat; add(res, ret.w[0][0]);
		}
		printf("%I64d\n", res);
	}
	return 0;
}