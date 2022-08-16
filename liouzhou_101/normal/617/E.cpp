#ifndef IO_H_
#define IO_H_

#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <string>
#include <type_traits>
#include <utility>

namespace io
{
	namespace internal
	{

//#ifndef ONLINE_JUDGE
#define FWRITE
//#endif

#ifdef FWRITE
#include <cstdio>
#else
#include <unistd.h>
		auto unistd_read = read;
		auto unistd_write = write;
#endif

		const int BUFSIZE = 1 << 20;
		int isize, osize;
		char ibuf[BUFSIZE + 10], obuf[BUFSIZE + 10];
		char* is = nullptr, * it = nullptr;
		char* os = obuf;
		constexpr char* ot = obuf + BUFSIZE;

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

	static inline bool read(char& x)
	{
		using namespace internal;
		if (is == it)
		{
			is = ibuf;
#ifdef FWRITE
			it = ibuf + fread(ibuf, 1, BUFSIZE, stdin);
#else
			it = ibuf + unistd_read(STDIN_FILENO, ibuf, BUFSIZE);
#endif
			if (is == it) return false;
		}
		x = *is++;
		return true;
	}

	static inline bool read(char* x)
	{
		do
		{
			if (!read(*x)) return false;
		} while (isspace(*x));
		for (++x; read(*x) && !isspace(*x); ++x);
		*x = 0;
		return true;
	}

	static inline bool read(std::string& s)
	{
		char c;
		do
		{
			if (!read(c)) return false;
		} while (isspace(c));
		s.clear();
		for (s += c; read(c) && !isspace(c); s += c);
		return true;
	}

	template<typename T>
	inline std::enable_if_t<!std::is_same_v<T, char>&& std::is_integral_v<T>&& std::is_unsigned_v<T>, bool> read(T& x)
	{
		char ch = 0;
		do
		{
			if (!read(ch)) return false;
		} while (!isdigit(ch));
		for (x = ch - '0'; read(ch) && isdigit(ch); x = x * 10 + ch - '0');
		return true;
	}

	template<typename T>
	inline std::enable_if_t<!std::is_same_v<T, char>&& std::is_integral_v<T>&& std::is_signed_v<T>, bool> read(T& x)
	{
		char ch = 0;
		bool sign = 0;
		do
		{
			if (!read(ch)) return false;
		} while (!isdigit(ch) && ch != '-');
		if (ch == '-')
		{
			sign = 1;
			x = 0;
		}
		else
			x = ch - '0';
		for (; read(ch) && isdigit(ch); x = x * 10 + ch - '0');
		if (sign) x = -x;
		return true;
	}

	// This implementation of reading floating point numbers does not cover all cases.
	// It is assumed that both integer and fractional parts can be stored in int64_t.
	// This assumption covers common cases and deserves efficiency.
	// If general cases are really needed, please use the function TODO.
	template<typename T>
	inline std::enable_if_t<std::is_floating_point_v<T>, bool> read(T& x)
	{
		constexpr T pow10[] = { 1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9, 1e10,
			1e11, 1e12, 1e13, 1e14, 1e15, 1e16, 1e17, 1e18 };
		char ch = 0;
		do
		{
			if (!read(ch)) return false;
		} while (!isdigit(ch) && ch != '-' && ch != '.');
		bool sign = ch == '-';
		if (sign)
			if (!read(ch)) return false;
		uint64_t a = 0;
		if (isdigit(ch))
		{
			a = ch - '0';
			while (read(ch) && isdigit(ch))
				a = a * 10 + ch - '0';
		}
		if (ch == '.')
		{
			uint64_t b = 0;
			int len = 0;
			while (read(ch) && isdigit(ch))
			{
				b = b * 10 + ch - '0';
				len++;
			}
			x = a + b / pow10[len];
		}
		else
			x = a;
		if (sign) x = -x;
		return true;
	}

	template<typename T, typename... Args>
	bool read(T& x, Args&... args)
	{
		return read(x) && read(args...);
	}

	static inline void write(const char& x)
	{
		using namespace internal;
		*os++ = x;
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

	static inline void write(const char* x)
	{
		for (; *x; ++x) write(*x);
	}

	static inline void write(const std::string& s)
	{
		write(s.c_str());
	}

	template<typename T>
	inline std::enable_if_t<!std::is_same_v<T, char>&& std::is_integral_v<T>&& std::is_unsigned_v<T>, void> write(T x)
	{
		static char buf[22] = { };
		static char* it = buf + 20;
		static char* end = buf + 20;
		do
		{
			*--it = x % 10 + '0';
			x /= 10;
		} while (x);
		for (; it < end; ++it)
			write(*it);
	}

	template<typename T>
	inline std::enable_if_t<!std::is_same_v<T, char>&& std::is_integral_v<T>&& std::is_unsigned_v<T>, void> write_number(T x, int fill)
	{
		static char buf[22] = { };
		static char* it = buf + 20;
		static char* end = buf + 20;
		do
		{
			*--it = x % 10 + '0';
			x /= 10;
		} while (x);
		for (int i = end - it; i < fill; ++i)
			write('0');
		for (; it < end; ++it)
			write(*it);
	}

	template<typename T>
	inline std::enable_if_t<!std::is_same_v<T, char>&& std::is_integral_v<T>&& std::is_signed_v<T>, void> write(const T& x)
	{
		if (x < 0) write('-'), write(std::make_unsigned_t<T>(-x));
		else write(std::make_unsigned_t<T>(x));
	}

	static inline void write_float(double x, int precision = 10)
	{
		if (std::isnan(x)) return write("NaN");
		if (std::isinf(x)) return write("Inf");
		if (x < 0) x = -x, write('-');
		constexpr double pow10[] = { 1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9, 1e10, 
			1e11, 1e12, 1e13, 1e14, 1e15, 1e16, 1e17, 1e18 };
		constexpr double pow10inv[] = { 1e-0, 1e-1, 1e-2, 1e-3, 1e-4, 1e-5, 1e-6, 1e-7, 1e-8, 1e-9, 1e-10, 
			1e-11, 1e-12, 1e-13, 1e-14, 1e-15, 1e-16, 1e-17, 1e-18 };
		x += pow10inv[precision] * 0.5;
		uint64_t a = uint64_t(x);
		write(a);
		write('.');
		uint64_t b = uint64_t((x - a) * pow10[precision]);
		write_number(b, precision);
	}

	template<typename T>
	inline std::enable_if_t<std::is_floating_point_v<T>, void> write(const T& x)
	{
		write_float(double(x));
	}

	template<typename T, typename... Args>
	void write(const T& x, const Args&... args)
	{
		write(x), write(args...);
	}
	
	static inline void writeln()
	{
		write('\n');
	}

	template<typename T, typename... Args>
	void writeln(const T& x, const Args&... args)
	{
		write(x), writeln(args...);
	}

	template<typename T>
	T next()
	{
		T x;
		read(x);
		return std::move(x);
	}

	template<typename InputIt>
	bool input(InputIt first, InputIt last)
	{
		for (; first != last; ++first)
			if (!read(*first)) return false;
		return true;
	}

	template<typename Iterable>
	bool input(Iterable& a)
	{
		for (auto& x : a)
			if (!read(x)) return false;
		return true;
	}

	template<typename InputIt>
	void print(InputIt first, InputIt last, const char* sep = " ")
	{
		for (; first != last; )
		{
			write(*first);
			if (++first != last) write(sep);
		}
		writeln();
	}

	template<typename Iterable>
	void print(const Iterable& a, const char* sep = " ")
	{
		print(a.begin(), a.end(), sep);
	}

	template<typename InputIt>
	void println(InputIt first, InputIt last)
	{
		print(first, last, "\n");
	}

	template<typename Iterable>
	void println(const Iterable& a)
	{
		println(a.begin(), a.end());
	}
}

#endif

#ifndef MO_H_
#define MO_H_

#include <cassert>
#include <algorithm>
#include <vector>

namespace algorithm
{
	// Mo's SQRT decomposition algorithm
	// The implementation is based on the order of Hilbert curve,
	// which is more efficient than other implementations.
	class Mo
	{
	public:
		int n, logn;
		struct Query
		{
			int left, right;
			int id;
			int64_t key;
			bool operator < (const Query& rhs) const
			{
				return key < rhs.key;
			}
		};
		std::vector<Query> queries;
		// HilbertOrder(x, y) denotes the order of (x, y) in the Hilbert curve. 
		// See https://en.wikipedia.org/wiki/Hilbert_curve.
		// The implementation refers to 
		// https://codeforces.com/blog/entry/61203?#comment-522213.
		int64_t HilbertOrder(int x, int y)
		{
			int64_t d = 0;
			for (int s = 1 << (logn - 1); s; s >>= 1)
			{
				bool rx = x & s, ry = y & s;
				d = d << 2 | rx * 3 ^ ry;
				if (!ry)
				{
					if (rx)
					{
						x = (1 << logn) - x;
						y = (1 << logn) - y;
					}
					std::swap(x, y);
				}
			}
			return d;
		}
	public:
		explicit Mo(int n) : n(n)
		{
			for (logn = 0; 1 << logn <= n; logn++);
		}
		// Query [left, right)
		void AddQuery(int left, int right)
		{
			assert(0 <= left && left < right && right <= n);
			queries.push_back({ left, right, (int)queries.size(), HilbertOrder(left, right) });
		}
		void AddQuery(int left, int right, int id)
		{
			assert(0 <= left && left < right&& right <= n);
			queries.push_back({ left, right, id, HilbertOrder(left, right) });
		}
		template<typename Init, typename Answer, typename AddLeft, typename AddRight, typename DelLeft, typename DelRight>
		void Solve(const Init& init, const Answer& answer, const AddLeft& add_left, const AddRight& add_right, const DelLeft& del_left, const DelRight& del_right)
		{
			std::sort(queries.begin(), queries.end());
			int left = 0, right = 0;
			init(left, right);
			for (const auto& [x, y, id, key] : queries)
			{
				while (left > x)
					add_left(--left, right);
				while (right < y)
					add_right(left, ++right);
				while (left < x)
					del_left(left++, right);
				while (right > y)
					del_right(left, right--);
				answer(x, y, id);
			}
		}
	};
}

#endif

#include <bits/stdc++.h>

using namespace std;
using namespace io;
using namespace algorithm;
//using namespace data_structure;

template<class T>
bool freshmax(T& a, const T& b)
{
	return a < b ? a = b, 1 : 0;
}

template<class T>
bool freshmin(T& a, const T& b)
{
	return a > b ? a = b, 1 : 0;
}

//using modular = algorithm::SafeModularInt32<998244353>;
//using modint = algorithm::ModInt<modular>;

using ll = int64_t;
using ld = long double;

//const int INF = 1000000000;
//const ll INF = 1000000000000000000LL;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

// string
vector<string> split(const string& s, char stop)
{
	vector<string> ret;
	string t;
	for (auto c : s)
	{
		if (c == stop)
		{
			ret.push_back(t);
			t = "";
		}
		else
			t += c;
	}
	ret.push_back(t);
	return ret;
}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 500010;

void solve()
{
	int n, m, k;
	read(n, m, k);
	Mo mo(n + 1);
	vector<int> a(n);
	for (auto& x : a)
		read(x);
	vector<int> s(n + 1);
	for (int i = 0; i < n; ++i)
		s[i + 1] = s[i] ^ a[i];
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		read(x, y);
		if (x > y) swap(x, y);
		y += 1;
		mo.AddQuery(x, y);
	}
	int64_t cur = 0;
	vector<int> u(1 << 20);
	vector<int64_t> res(m);
	auto init = [&](int& left, int& right)
	{
		left = right = 1;
		cur = 0;
		fill(u.begin(), u.end(), 0);
		u[s[0]] += 1;
	};
	auto answer = [&](int x, int y, int id)
	{
		res[id] = cur;
	};
	auto add_left = [&](int x, int y)
	{
		cur += u[s[x - 1] ^ k];
		u[s[x - 1]] += 1;
	};
	auto add_right = [&](int x, int y)
	{
		cur += u[s[y - 1] ^ k];
		u[s[y - 1]] += 1;
	};
	auto del_left = [&](int x, int y)
	{
		u[s[x - 1]] -= 1;
		cur -= u[s[x - 1] ^ k];
	};
	auto del_right = [&](int x, int y)
	{
		u[s[y - 1]] -= 1;
		cur -= u[s[y - 1] ^ k];
	};
	mo.Solve(init, answer, add_left, add_right, del_left, del_right);
	print(res, "\n");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("try.in", "r", stdin);
	//freopen("try.out", "w", stdout);
#endif
	int tests = 1;
	//tests = next<int>();
	for (int test = 1; test <= tests; ++test)
	{
		//write("Case #", test, ": ");
		solve();
	}
	return 0;
}