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

const int MAXN = 111;

int a[MAXN], u[MAXN];
int F[MAXN][2][MAXN];

void solve()
{
	int n = inp();
	for (int i = 1; i <= n; ++i)
	{
		a[i] = inp();
		if (a[i] == 0)
			a[i] = -1;
		else
		{
			u[a[i]] = 1;
			a[i] %= 2;
		}
	}
	int c[2] = { 0, 0 };
	for (int i = 1; i <= n; ++i)
		if (!u[i]) c[i % 2] ++;

	memset(F, 0x3f, sizeof(F));
	F[0][0][0] = F[0][1][0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] == -1)
		{
			for (int x = 0; x < 2; ++x)
				for (int y = 0; y < 2; ++y)
				{
					for (int k = n; k >= (x == 0); --k)
					{
						freshmin(F[i][x][k], F[i-1][y][k-(x == 0)]+(x != y));
					}
				}
		}
		else
		{
			for (int x = 0; x < 2; ++ x) if (x == a[i])
				for (int y = 0; y < 2; ++ y)
					for (int k = n; k >= 0; --k)
					{
						freshmin(F[i][x][k], F[i - 1][y][k] + (x != y));
					}
		}
	}
	int ans = min(F[n][0][c[0]], F[n][1][c[0]]);
	writeln(ans);
}

int main()
{
	
	//for (int T = inp(); T --; )
	solve();

	return 0;
}