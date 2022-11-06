#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define LD long double
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
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


const int maxn = 200010;
const ll mod = 998244353;
int qpow(int x)
{
	int ret = 1;
	int times = 998244351;
	while (times)
	{
		if (times & 1) ret = 1LL * ret * x % mod;
		x = 1LL * x * x % mod;
		times >>= 1;
	}
	return ret;
}

struct matrix
{
	int a[2][2];
	matrix() {a[0][0] = a[1][1] = a[0][1] = a[1][0] = 0;}
	void set(int x) {a[0][1] = a[1][0] = 0; a[0][0] = a[1][1] = x;}
	matrix operator *(const matrix &b) const
	{
		matrix ret;
		rep0(i, 2)
			rep0(j, 2)
				rep0(k, 2)
					ret.a[i][j] = (ret.a[i][j] + 1LL * a[i][k] * b.a[k][j]) % mod;
		return ret;
	}

	bool operator ==(const matrix&b)
	{
		rep0(i, 2)
			rep0(j, 2)
				if (a[i][j] != b.a[i][j]) 
					return 0;
		return 1;
	}
};


matrix T[500010];
void modify(int p, const matrix&v, int l, int r, int rt)
{
	if (l == r)
	{
		T[rt] = v;
		return;
	}
	int mid = l + r >> 1;
	if (p <= mid) modify(p, v, l, mid, ls);
	else modify(p, v, mid + 1, r, rs);
	T[rt] = T[ls] * T[rs];
}

bool cmp(const pii&a, const pii&b) {return 1LL * a.X * b.Y < 1LL * a.Y * b.X;}
bool cmp2(const pair<pii, int>&a, const pair<pii, int>&b) {return cmp(a.X, b.X);}
bool eq(const pii&a, const pii&b) {return 1LL * a.X * b.Y == 1LL * a.Y * b.X;}

vi x, v;
vector<ll> p;
int n;

void Modify(int pos, pii t)
{
	matrix cur;
	cur.a[0][1] = 1;
	if (cmp(t, mp(x[pos + 1] - x[pos], abs(v[pos + 1] - v[pos]))))cur.a[0][0] = cur.a[1][1] = 1;
	else
	{
		cur.a[0][0] = (v[pos + 1] <= v[pos]);
		cur.a[1][1] = (v[pos + 1] >= v[pos]);
	}
	if (cmp(t, mp(x[pos + 1] - x[pos], v[pos + 1] + v[pos])))cur.a[1][0] = 1;

	rep0(i, 2)
		rep0(j, 2)
		{
			if (j == 0)cur.a[i][j] = 1LL * cur.a[i][j] * (mod + 1 - p[pos + 1]) % mod;
			else cur.a[i][j] = 1LL * cur.a[i][j] * p[pos + 1] % mod;
		}
	modify(pos, cur, 1, n - 1, 1);
}


int main()
{
	n = read();
	x.pb(0);
	v.pb(0);
	p.pb(0);
	rep(i, 1, n)
	{
		x.pb(read());
		v.pb(read());
		p.pb(read());
		p[i] = p[i] * qpow(100) % mod;
	}

	vector< pair<pair<ll, ll> , int> >V;
	rep(pos, 1, n - 1)
	{
		if (v[pos] != v[pos + 1]) V.pb(mp(mp(x[pos + 1] - x[pos], abs(v[pos + 1] - v[pos])), pos));
		V.pb(mp(mp(x[pos + 1] - x[pos], v[pos + 1] + v[pos]), pos));
		V.pb(mp(mp(0x7f7f7f7f, 1), pos));
	}
	sort(ALL(V), cmp2);

	pii cur = mp(0, 1);
	rep(i, 1, n - 1) if(i == 0) continue; else Modify(i, cur);
	ll ans = 0, last = 0;
	matrix now = T[1];
	rep0(j, 2)
		rep0(k, 2)
		{
			int esa = now.a[j][k];
			if (j == 0) esa = 1LL * esa * (mod + 1 - p[1]) % mod;
			else esa = 1LL * esa * p[1] % mod;
			last += esa;
			if (last >= mod)last -= mod;
		}
	for (int i = 0, nxt = 0; i < sz(V); i = nxt)
	{
		for (; nxt < sz(V) && eq(V[i].X, V[nxt].X); nxt ++);
		rep(j, i, nxt - 1) Modify(V[j].Y, V[j].X);
		int Pr = 0;
		now = T[1];
		rep0(j, 2)
			rep0(k, 2)
			{
				int esa = now.a[j][k];
				if (j == 0)esa = 1LL * esa * (mod + 1 - p[1]) % mod;
				else esa = 1LL * esa * p[1] % mod;
				Pr += esa;
				if (Pr >= mod)Pr -= mod;
			}
		ans = (ans + 1LL * (last - Pr + mod) * V[i].X.X % mod * qpow(V[i].X.Y)) % mod;
		cur = V[i].X;
		last = Pr;
	}
	printf("%lld\n", ans);
	return 0;
}