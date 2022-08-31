#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;
//using ll = long long;
using ull = uint64_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = double;

#define X first
#define Y second

//#ifndef ONLINE_JUDGE
#define FWRITE
//#endif

namespace io
{

#ifndef FWRITE
#include <unistd.h>
	auto unistd_read = read;
	auto unistd_write = write;
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
			it = ibuf + unistd_read(STDIN_FILENO, ibuf, BUFSIZE);
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
			unistd_write(STDOUT_FILENO, obuf, BUFSIZE);
#endif
			os = obuf;
		}
	}

	int inp() {
		int x = 0, f = 0; char ch;
		for (ch = getchar(); !isdigit(ch); ch = getchar())
		{
			if (ch == EOF) return -1;
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
		int f = 0; char ch;
		for (ch = getchar(); !isdigit(ch); ch = getchar())
		{
			if (ch == EOF) return 0;
			if (ch == '-') f = 1;
		}
		for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
		if (f) x = -x;
		return 1;
	}

	bool read(char* s)
	{
		char* t = s;
		char ch = getchar();
		for (; ch == ' ' || ch == '\n'; ch = getchar());
		for (; ch != ' ' && ch != '\n' && ch != EOF; ch = getchar())
			*t++ = ch;
		*t = 0;
		return s != t;
	}

	template<class T, class... Args>
	bool read(T& x, Args&... args)
	{
		return read(x) && read(args...);
	}

	template<class T>
	bool readln(T& x)
	{
		x = 0;
		int f = 0; char ch;
		for (ch = getchar(); !isdigit(ch); ch = getchar())
		{
			if (ch == EOF) return 0;
			if (ch == '-') f = 1;
		}
		for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
		if (f) x = -x;
		for (; ch != '\n' && ch != EOF; ch = getchar());
		return 1;
	}

	bool readln(char* s)
	{
		char* t = s;
		while (1)
		{
			char ch = getchar();
			if (ch == '\n' || ch == EOF) break;
			*t++ = ch;
		}
		*t = 0;
		return s != t;
	}

	template<class T, class... Args>
	bool readln(T& x, Args&... args)
	{
		return read(x) && readln(args...);
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

	void write(const char* s)
	{
		for (; *s; ++s) putchar(*s);
	}

	template<>
	void write(char* s)
	{
		write((const char*)s);
	}

	template<>
	void write(char c)
	{
		putchar(c);
	}

	template<class T, class... Args>
	void write(T x, Args... args)
	{
		write(x);
		write(args...);
	}

	void writeln()
	{
		putchar('\n');
	}

	template<class T, class... Args>
	void writeln(T x, Args... args)
	{
		write(x);
		writeln(args...);
	}

	template<class Iterator>
	bool input(Iterator st, Iterator ed)
	{
		for (; st != ed; ++st)
		{
			if (!read(*st)) return false;
		}
		return true;
	}

	template<class T>
	bool input(T& a)
	{
		return input(a.begin(), a.end());
	}

	template<class Iterator>
	void print(Iterator st, Iterator ed, const char* c = " ")
	{
		int flag = 0;
		for (; st != ed; ++st)
		{
			if (flag) write(c);
			flag = 1;
			write(*st);
		}
		writeln();
	}

	template<class T>
	void print(const T& a, const char* c = " ")
	{
		print(a.begin(), a.end(), c);
	}

	struct ender
	{
		~ender()
		{
			if (os != obuf)
#ifdef FWRITE
				fwrite(obuf, 1, os - obuf, stdout);
#else
				unistd_write(STDOUT_FILENO, obuf, os - obuf);
#endif
		}
	}__ender;

}

int64_t power(int64_t a, int64_t b, int64_t p)
{
	if (!b) return 1;
	int64_t t = power(a, b >> 1, p);
	t = t * t % p;
	if (b & 1) t = t * a % p;
	return t;
}

pll exgcd(ll a, ll b)
{
	if (b == 0) return { 1, 0 };
	//auto [x, y] = exgcd(b, a % b);
	auto e = exgcd(b, a % b);
	ll x = e.first;
	ll y = e.second;
	return { y, x - a / b * y };
}

//mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
//mt19937 rd(1);

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

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

template<class T>
T det(T x1, T y1, T x2, T y2, T x3, T y3)
{
	return x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3;
}

template<class T>
T dis(T x1, T y1, T x2, T y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

namespace Lyndon_factorization
{
	// return Lyndon factorization.
	// The Lyndon factorization of a string s is of the form
	//     s = w_1 w_2 ... w_k,
	// where w_i is simple and w_1 >= w_2 >= ... >= w_k.
	// The Lyndon factorization of any string is proved to be unique.
	// A string is called simple if it is strictly smaller than any of its own nontrivial suffixes, e.g. a, b, ab, aab, ababb.
	// A string is simple <==> it is the smallest cyclic shift of itself.
	// Format: [x_i, y_i] denotes w_i = s[x_i..x_i+y_i-1]
	// url: https://cp-algorithms.com/string/lyndon_factorization.html
	vector<pii> duval(const string& s)
	{
		int n = s.size();
		vector<pii> res;
		int i = 0;
		while (i < n)
		{
			int j = i + 1, k = i;
			while (j < n && s[k] <= s[j])
			{
				if (s[k] < s[j])
					k = i;
				else
					k++;
				j++;
			}
			while (i <= k)
			{
				res.push_back({ i, j - k });
				i += j - k;
			}
		}
		return res;
	}
}

void init()
{
}

const int MAXN = 600010;

void solve()
{
	int n;
	read(n);
	vector<tuple<ld, ld, ld>> v(n);
	for (auto& [x1, x2, y] : v)
	{
		x1 = inp();
		x2 = inp();
		y = inp();
	}

	using pdd = pair<ld, ld>;

	const ld INF = 1e18;
	{
		vector<pdd> range;
		ld minv = INF, maxv = -INF;
		for (auto& [x1, x2, y] : v)
		{
			freshmin(minv, x1);
			freshmax(maxv, x2);
			range.push_back({ x1, x2 });
		}
		sort(range.begin(), range.end());
		ld last = range[0].second;
		int ok = 1;
		for (int i = 1; i < range.size(); ++i)
		{
			auto [x, y] = range[i];
			if (last > x) ok = 0;
			last = y;
		}
		if (ok == 1)
		{
			ld res = maxv - minv;
			printf("%.12f\n", res);
			return;
		}
	}

	vector<pdd> range;

	for (int i = 0; i < n; ++i)
	{
		auto [xi1, xi2, yi] = v[i];
		for (int j = 0; j < n; ++j)
		{
			auto [xj1, xj2, yj] = v[j];
			if (yi > yj)
			{
				ld L = atan2(yi - yj, xi2 - xj1);
				ld R = atan2(yi - yj, xi1 - xj2);
				assert(L <= R);
				range.push_back({ L, R });
			}
		}
	}

	sort(range.begin(), range.end());
	assert(range.size() >= 1);

	ld best = range[0].first;
	ld last = range[0].second;

	const ld eps = 1e-10;

	for (int i = 1; i < range.size(); ++i)
	{
		auto [x, y] = range[i];
		if (last - eps < x)
		{
			if (fabs(tan(best)) < fabs(tan(last))) best = last;
			if (fabs(tan(best)) < fabs(tan(x))) best = x;
			last = y;
		}
		else
		{
			freshmax(last, y);
		}
	}

	if (fabs(tan(best)) < fabs(tan(last))) best = last;
	/*
	auto check = [&](ld k)
	{
		vector<pdd> range;
		for (auto& [x1, x2, y] : v)
		{
			ld b1 = y - k * x1;
			ld b2 = y - k * x2;
			ld z1 = -b1 / k;
			ld z2 = -b2 / k;
			if (z1 > z2) swap(z1, z2);
			range.push_back({ z1,z2 });
		}
		sort(range.begin(), range.end());
		ld last = range[0].second;
		for (int i = 1; i < range.size(); ++i)
		{
			auto [x, y] = range[i];
			if (last > x) return false;
			last = y;
		}
		return true;
	};
	
	auto solve = [&]() -> ld
	{
		const ld eps = 1e-10;
		ld L = 0, R = acos(-1) / 2 - eps;
		for (int loop = 1; loop <= 100; ++loop)
		{
			ld m = (L + R) / 2;
			if (check(tan(m)))
				L = m;
			else
				R = m;
		}
		ld k = tan((L + R) / 2);
		ld minv = 1e18, maxv = -1e18;
		for (auto& [x1, x2, y] : v)
		{
			ld b1 = y - k * x1;
			ld b2 = y - k * x2;
			ld z1 = -b1 / k;
			ld z2 = -b2 / k;
			if (z1 > z2) swap(z1, z2);
			freshmin(minv, z1);
			freshmax(maxv, z2);
		}
		return maxv - minv;
	};

	auto res1 = solve();

	for (auto& [x1, x2, y] : v)
	{
		x1 = -x1;
		x2 = -x2;
	}

	check(3);

	auto res2 = solve();

	auto res = min(res1, res2);
	*/

	ld minv = INF, maxv = -INF;
	ld k = tan(best);
	for (auto& [x1, x2, y] : v)
	{
		ld b1 = y - k * x1;
		ld b2 = y - k * x2;
		ld z1 = -b1 / k;
		ld z2 = -b2 / k;
		if (z1 > z2) swap(z1, z2);
		freshmin(minv, z1);
		freshmax(maxv, z2);
	}
	ld res = maxv - minv;
	printf("%.12f\n", res);
}

int main()
{

	int T = 1;
	//read(T);
	init();
	for (int test = 1; test <= T; ++test)
	{
		//write("Case #", test, ": ");
		solve();
	}

	return 0;
}