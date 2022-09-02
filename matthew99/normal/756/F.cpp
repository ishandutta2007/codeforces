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

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int Mod = 1e9 + 7;

inline int fpm(LL b, int e, int m)
{
	b %= m;
	(e += m - 1) %= m - 1;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

const int maxn = 100100;

int pw0[maxn + 5];
int pw1[maxn + 5];

inline int sumpw(int x, int y, int z)
{
	if (!x) return z;
	return LL(fpm(10, (LL)x * y % (Mod - 1), Mod) - 1) * fpm(fpm(10, x, Mod) - 1, Mod - 2, Mod) % Mod;
}

inline int sumsumpw(int x, int y, int z)
{
	if (!x) return (LL)z * (z + 1) % Mod;
	return LL(sumpw(x, y, z) - z) * fpm(fpm(10, x, Mod) - 1, Mod - 2, Mod) % Mod;
}

struct num
{
	int val, len;

	num(): val(0), len(0) { }
	num(int _val, int _len): val(_val), len(_len) { }

	inline num &app(int x)
	{
		val = ((LL)val * 10 + x) % Mod;
		(++len) %= Mod - 1;
		return *this;
	}

	inline num &dup(int x, int y)
	{
		val = (LL)val * sumpw(len, x, y) % Mod;
		len = (LL)len * x % (Mod - 1);
		return *this;
	}
	
	inline num &sub(const num &x)
	{
		(len -= x.len) %= Mod - 1;
		val = (val - (LL)x.val * fpm(10, len, Mod)) % Mod;
		return *this;
	}

	inline num &add(const num &x)
	{
		val = ((LL)val * fpm(10, x.len, Mod) % Mod + x.val) % Mod;
		(len += x.len) %= Mod - 1;
		return *this;
	}

};

num pre[maxn + 5];

inline num sum(const num &x, int val)
{
	num ret = pre[x.len];
	int tmp = LL(val - pw1[x.len - 1]) * x.len % (Mod - 1);
	return ret.add(num((sumsumpw(x.len, val, x.val) - (LL)sumsumpw(x.len, pw1[x.len - 1], pw0[x.len - 1]) * fpm(10, tmp, Mod)) % Mod, tmp));
}

int now;

int n;
char s[maxn + 5];

inline num doit()
{
	num ret;
	int val = 0;
	while (now < n && isdigit(s[now]))
	{
		ret.app(s[now] - '0');
		val = ((LL)val * 10 + s[now] - '0') % (Mod - 1);
		++now;
	}
	if (s[now] == '(')
	{
		int tmp = ret.val;
		++now;
		ret = doit();
		ret.dup(val, tmp);
	}
	if (s[now] == '-')
	{
		++now;
		num rhs;
		int valr = 0;
		while (now < n && isdigit(s[now]))
		{
			rhs.app(s[now] - '0');
			valr = ((LL)valr * 10 + s[now] - '0') % (Mod - 1);
			++now;
		}
		num tmp = sum(rhs, valr);
		ret = tmp.sub(sum(ret, val)).add(rhs);
	}
	if (s[now] == ')') { ++now; return ret; }
	if (now == n) return ret;
	assert(s[now] == '+');
	++now, ret.add(doit());
	return ret;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	pw0[0] = 1;
	pw1[0] = 1;
	REP(i, 0, maxn) 
	{
		pw0[i + 1] = (LL)pw0[i] * 10 % Mod;
		pw1[i + 1] = (LL)pw1[i] * 10 % (Mod - 1);
	}
	REP(i, 1, maxn)
	{
		pre[i + 1] = pre[i];
		int tmp = LL(pw1[i] - pw1[i - 1]) * i % (Mod - 1);
		pre[i + 1].add(num((sumsumpw(i, pw1[i], pw0[i]) - (LL)sumsumpw(i, pw1[i - 1], pw0[i - 1]) * fpm(10, tmp, Mod)) % Mod, tmp));
	}
	scanf("%s", s);
	n = strlen(s);
	printf("%d\n", (now = 0, (doit().val + Mod) % Mod));
	return 0;
}