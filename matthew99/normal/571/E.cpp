#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int oo = 0x3f3f3f3f;

const int Mod = 1e9 + 7;

template<typename T> T &Read(T &x)
{
	static char c;
	while (!isdigit(c = getchar()));
	x = c - '0';
	while (isdigit(c = getchar())) (x *= 10) += c - '0';
	return x;
}

inline LL mul(LL b, LL e, const LL &m)
{
	LL t = 0;
	for ( ; e; e >>= 1, (b <<= 1) %= m)
		if (e & 1) (t += b) %= m;
	return t;
}

const int max0 = 3500, max1 = 1000000000;
const int maxn = 100;

int pr[max0 + 5];
int pn = 0;

inline void prepare()
{
	for (int i = 2; i * i <= max1; ++i)
	{
		bool flag = 1;
		for (int j = 2; j * j <= i; ++j)
			if (!(i % j)) 
			{
				flag = 0;
				break;
			}
		if (flag) pr[pn++] = i;
	}
}

int A[maxn + 5], B[maxn + 5];
int aa[max0 + 5], bb[max0 + 5];

template<typename T> T ex_gcd(T a, T b, T &x, T &y)
{
	if (!b)
	{
		x = 1, y = 0;
		return a;
	}
	T d = ex_gcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

struct data
{
	int a, b, c;

	data() { }
	data(const int &_a, const int &_b, const int &_c): a(_a), b(_b), c(_c) { }

};

data a[maxn + 5];
int an = 0;

inline int get(int x, const int &y)
{
	int ret = 0;
	while (!(x % pr[y])) x /= pr[y], ++ret;
	return ret;
}

template<typename T> inline T ceil(T a, T b)
{
	if (b < 0) a = -a, b = -b;
	if (a < 0) return a / b;
	return (a + b - 1) / b;
}

template<typename T> inline T floor(T a, T b)
{
	return -ceil(-a, -b);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	int n;
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d%d", B + i, A + i);
	REP(i, 0, pn) aa[i] = get(A[n - 1], i), bb[i] = get(B[n - 1], i);
	LL ans = -1;
	REP(i, 0, n - 1)
	{
		bool flag = 0;
		data pre;
		REP(j, 0, pn)
		{
			int a0 = aa[j], b0 = bb[j];
			int a1 = get(A[i], j), b1 = get(B[i], j);
			if (a0 || a1 || b0 != b1)
			{
				if (b0 != b1 && !a0 && !a1) EXIT("-1\n");
				if (a0 || a1)
				{
					if (!flag) pre = data(a0, -a1, b0 - b1);
					else
					{
						int newa = a0, newb = -a1, newc = b0 - b1;
						int D = -(pre.a * newb - pre.b * newa);
						int X = pre.c * newb - pre.b * newc;
						int Y = pre.a * newc - pre.c * newa;
						if (!D)
						{
							if (X || Y) EXIT("-1\n");
						}
						else
						{
							if (X % D || Y % D) EXIT("-1\n");
							else
							{
								if (X / D < 0 || Y / D < 0) EXIT("-1\n");
								if (ans != -1 && X / D != ans) EXIT("-1\n");
								ans = X / D;
							}
						}
					}
					flag = 1;
				}
			}
		}
		if (flag) a[an++] = pre;
	}
	REP(i, 0, an)
		if (!a[i].b)
		{
			if (a[i].c % a[i].a) EXIT("-1\n");
			if (a[i].c * a[i].a > 0) EXIT("-1\n");
			if (ans != -1 && (-a[i].c) / a[i].a != ans) EXIT("-1\n");
			ans = (-a[i].c) / a[i].a;
		}
	if (ans != -1)
	{
		REP(i, 0, an)
		{
			a[i].c += a[i].a * ans;
			if (a[i].b)
			{
				if (a[i].c % a[i].b) EXIT("-1\n");
				if (a[i].c * a[i].b > 0) EXIT("-1\n");
			}
			else if (a[i].c) EXIT("-1\n");
		}
	}
	else
	{
		static int val[maxn + 5];
		static int Mod[maxn + 5];
		int m = 0;
		LL Min = 0, Max = LLONG_MAX;
		REP(i, 0, an)
			if (!a[i].a)
			{
				if (a[i].c % a[i].b) EXIT("-1\n");
				if (a[i].c * a[i].b > 0) EXIT("-1\n");
			}
			else
			{
				static int x, y;
				int d = ex_gcd(a[i].a, a[i].b, x, y);
				if (a[i].c % d) EXIT("-1\n");
				x *= (-a[i].c) / d;
				Mod[m] = abs(a[i].b / d);
				val[m] = x % Mod[m];
				++m;
				if (a[i].b < 0) Min = max(Min, (LL)ceil(-a[i].c, a[i].a));
				else Max = min(Max, (LL)floor(-a[i].c, a[i].a));
			}
		if (Min > Max) EXIT("-1\n");
		LL a = 0, b = 1;
		REP(i, 0, m)
		{
			static LL x, y;
			LL d = ex_gcd(b, (LL)Mod[i], x, y);
			LL res = a % d;
			if ((val[i] - res) % d) EXIT("-1\n");
			b /= d, Mod[i] /= d;
			(a -= res) /= d;
			(val[i] -= res) /= d;
			LL newb = b * Mod[i];
			(a += b) %= b;
			(val[i] += Mod[i]) %= Mod[i];
			a = (mul(mul(x, b, newb), val[i], newb) + mul(mul(y, Mod[i], newb), a, newb)) % newb;
			b = newb * d;
			((a *= d) += res) %= b;
		}
		(a += b) %= b;
		ans = ceil(Min - a, b) * b + a;
		if (ans > Max) EXIT("-1\n");
	}
	LL t = 1;
	LL b = A[n - 1];
	assert(ans >= 0);
	for ( ; ans; ans >>= 1, (b *= b) %= Mod)
		if (ans & 1) (t *= b) %= Mod;
	(t *= B[n - 1]) %= Mod;
	printf("%I64d\n", t);
	return 0;
}