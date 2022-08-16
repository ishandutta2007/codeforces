#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;
using ull = uint64_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using ld = double;

#define X first
#define Y second

#define FWRITE

namespace io
{

#ifndef FWRITE
#include <unistd.h>
#endif
	const int BUFSIZE = 1 << 20;

	int isize, osize;
	char ibuf[BUFSIZE + 10], obuf[BUFSIZE + 10];
	char* is, * it, * os = obuf, * ot = obuf + BUFSIZE;

	char getchar()
	{
		if (is == it)
		{
			is = ibuf;
#ifdef FWRITE
			it = ibuf + fread(ibuf, 1, BUFSIZE, stdin);
#else
			it = ibuf + read(STDIN_FILENO, ibuf, BUFSIZE);
#endif
			if (is == it) return EOF;
		}
		return *is++;
	}

	char getalpha()
	{
		char c = getchar();
		while (!isalpha(c)) c = getchar();
		return c;
	}

	void putchar(char c)
	{
		*os++ = c;
		if (os == ot)
		{
#ifdef FWRITE
			fwrite(obuf, 1, BUFSIZE, stdout);
#else
			write(STDOUT_FILENO, obuf, BUFSIZE);
#endif
			os = obuf;
		}
	}

	int inp() {
		int x = 0, f = 0; char ch;
		for (ch = getchar(); !isdigit(ch); ch = getchar())
		{
			//if (ch == EOF) return -1;
			if (ch == '-') f = 1;
		}
		for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
		return f ? -x : x;
	}

	ll inp_ll() {
		ll x = 0; int f = 0; char ch;
		for (ch = getchar(); !isdigit(ch); ch = getchar())
			if (ch == '-') f = 1;
		for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
		return f ? -x : x;
	}

	template<class T>
	bool read(T& x)
	{
		x = 0;
		char ch = getchar();
		if (ch == EOF) return 0;
		for (; !isdigit(ch); )
		{
			ch = getchar();
			if (ch == EOF) return 0;
		}
		for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
		return 1;
	}

	template<class T>
	void write(T x)
	{
		static char s[22];
		static char* it = s + 20;
		static char* end = s + 20;

		if (x < 0)
		{
			putchar('-');
			x = -x;
		}

		do
		{
			*--it = x % 10 + '0';
			x /= 10;
		} while (x);
		/*
		if (!x)
			*-- it = '0';
		while (x)
		{
			*-- it = x%10+'0';
			x /= 10;
		}
		*/
		for (; it < end; ++it)
			putchar(*it);
	}

	template<>
	void write(const char* s)
	{
		for (; *s; ++s) putchar(*s);
	}

	template<>
	void write(char c)
	{
		putchar(c);
	}

	template<class T, class V>
	void write(T x, V y)
	{
		write(x);
		write(y);
	}

	template<class T>
	void writeln(T x)
	{
		write(x);
		putchar('\n');
	}

	struct ender
	{
		~ender()
		{
			if (os != obuf)
#ifdef FWRITE
				fwrite(obuf, 1, os - obuf, stdout);
#else
				write(STDOUT_FILENO, obuf, os - obuf);
#endif
		}
	}__ender;

}

template<class T>
void print(const T& a)
{
	for (auto x : a) printf("%d ", x); puts("");
}

int64_t power(int64_t a, int64_t b, int64_t p)
{
	if (!b) return 1;
	int64_t t = power(a, b>>1, p);
	t = t * t % p;
	if (b & 1) t = t * a % p;
	return t;
}

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

using namespace io;

template<class T>
inline void freshmin(T& a, const T& b)
{
	if (a > b) a = b;
}

template<class T>
inline void freshmax(T& a, const T& b)
{
	if (a < b) a = b;
}

const ll B = 31;
const ll MOD = 1000000007;
const int INF = 1000000000;
const int MAXN = 66;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

ld det(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3)
{
	return x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3;
}

using pll = pair<ll, ll>;

ll dis(ll a, ll b, ll c, ll d)
{
	return abs(a - c) + abs(b - d);
}

ll d[MAXN][MAXN];

void solve()
{
	ll x0, y0, ax, ay, bx, by, xs, ys, t;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
	vector<pll> v;
	for (ll i = 0, x = x0, y = y0; ;)
	{
		v.push_back({ x, y });
		x = ax * x + bx;
		y = ay * y + by;
		if (x > 3e16 || y > 3e16) break;
	}

	int ans = 0;
	int n = v.size();

	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j)
		{
			ll tmp = 0;
			for (int k = i + 1; k <= j; ++k)
				tmp += dis(v[k-1].X, v[k-1].Y, v[k].X, v[k].Y);
			d[i][j] = tmp;
		}

	for (int i = 0; i < n; ++ i)
		for (int j = i; j < n; ++j)
		{
			for (int k = i; k <= j; ++k)
			{
				ll cost = dis(xs, ys, v[k].X, v[k].Y);
				ll go1 = cost + d[i][k] + (k + 1 <= j ? (dis(v[i].X, v[i].Y, v[k + 1].X, v[k + 1].Y) + d[k + 1][j]) : 0);
				ll go2 = cost + d[k][j] + (i <= k - 1 ? (dis(v[j].X, v[j].Y, v[k - 1].X, v[k - 1].Y) + d[i][k - 1]) : 0);
				if (min(go1, go2) <= t) freshmax(ans, j-i+1);
			}
		}

	writeln(ans);
}

int main()
{
	
	//for (int T = inp(); T --; )
	solve();

	return 0;
}