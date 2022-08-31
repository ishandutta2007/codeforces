#ifndef IO_H_
#define IO_H_

#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <string>
#include <algorithm>
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
	inline bool read_unsigned_int(T& x)
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
	inline bool read_signed_int(T& x)
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

	template<typename T>
	inline bool read_int(T& x)
	{
		return read_signed_int(x);
	}

	template<typename T>
	inline std::enable_if_t<!std::is_same_v<T, char>&& std::is_integral_v<T>&& std::is_unsigned_v<T>, bool> read(T& x)
	{
		return read_unsigned_int(x);
	}

	template<typename T>
	inline std::enable_if_t<!std::is_same_v<T, char>&& std::is_integral_v<T>&& std::is_signed_v<T>, bool> read(T& x)
	{
		return read_signed_int(x);
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
	inline void write_unsigned_int(T x)
	{
		if (x == 0)
			return write('0');
		std::string s;
		while (x)
		{
			s.push_back(x % 10 + '0');
			x /= 10;
		}
		std::reverse(s.begin(), s.end());
		write(s);
	}

	template<typename T>
	inline void write_signed_int(T x)
	{
		if (x < 0)
			write('-'), write_unsigned_int(-x);
		else
			write_unsigned_int(x);
	}

	template<typename T>
	inline void write_int(T x)
	{
		write_signed_int(x);
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

#ifndef YCOMBINATOR_H_
#define YCOMBINATOR_H_

// https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
#include <functional>
#include <utility>

namespace std {

    template<class Fun>
    class y_combinator_result {
        Fun fun_;
    public:
        template<class T>
        explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}

        template<class ...Args>
        decltype(auto) operator()(Args &&...args) {
            return fun_(std::ref(*this), std::forward<Args>(args)...);
        }
    };

    template<class Fun>
    decltype(auto) y_combinator(Fun&& fun) {
        return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
    }

} // namespace std

#endif

#ifndef TREEDIVIDECONQUER_H_
#define TREEDIVIDECONQUER_H_

#include <cassert>
#include <algorithm>
#include <vector>
#include <functional>

namespace algorithm
{
	class TreeDivideConquer
	{
	private:
		int n;
		std::vector<std::vector<int>> v;
	public:
		TreeDivideConquer(int n) : n(n), v(n) { }
		void AddEdge(int x, int y)
		{
			assert(0 <= x && x < n && 0 <= y && y < n && x != y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		template<typename Operation>
		void Solve(const Operation& operation, int x = 0)
		{
			assert(0 <= x && x < n);
			std::vector<int> u(n);
			std::vector<int> size(n), most(n), pre(n);
			auto centroid = [&](int st)
			{
				std::vector<int> q = { st };
				u[st] = 1;
				for (int i = 0; i < (int)q.size(); ++i)
				{
					int x = q[i];
					size[x] = 1;
					most[x] = 0;
					for (auto y : v[x])
						if (!u[y])
						{
							u[y] = 1;
							pre[y] = x;
							q.push_back(y);
						}
				}
				for (int i = (int)q.size() - 1; i >= 0; --i)
				{
					int x = q[i];
					if (i >= 1)
					{
						size[pre[x]] += size[x];
						most[pre[x]] = std::max(most[pre[x]], size[x]);
					}
					most[x] = std::max(most[x], (int)q.size() - size[x]);
					u[x] = 0;
				}
				return *std::min_element(q.begin(), q.end(), [&](int i, int j)
					{
						return most[i] < most[j];
					});
			};
			std::y_combinator([&](auto dfs, int st) -> void
				{
					int root = centroid(st);
					operation(root, u);
					u[root] = 1;
					for (auto child : v[root])
						if (!u[child])
							dfs(child);
				})(x);
		}
	};
}

#endif


#include <bits/stdc++.h>

namespace algorithm { }
namespace data_structure { }

using namespace std;
using namespace io;
using namespace algorithm;
using namespace data_structure;

#ifdef ONLINE_JUDGE
#define debug 0
#else
#define debug 1
#endif

template<class T, class U>
bool freshmax(T& a, const U& b)
{
	return a < T(b) ? a = b, 1 : 0;
}

template<class T, class U>
bool freshmin(T& a, const U& b)
{
	return a > T(b) ? a = b, 1 : 0;
}

//using modular = algorithm::Modular<uint32_t, 998244353, true, 3>;
//using modular = algorithm::SafeModularInt32<1000000007>;
//using modular = algorithm::SafeUserModularInt32;

//using modint = algorithm::ModInt<modular>;
//using poly = algorithm::Polynomial<modular>;
//using linear = algorithm::LinearRecurrence<modular>;

using ll = int64_t;
using ull = uint64_t;
using ld = double;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
	int n;
	read(n);
	TreeDivideConquer g(n);
	vector<vector<pair<int, int>>> v(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int x, y, z;
		read(x, y, z);
		x -= 1; y -= 1; z -= 1;
		g.AddEdge(x, y);
		v[x].push_back({ y, z });
		v[y].push_back({ x, z });
	}
	vector<int> from(n), size(n);
	vector<int> low(n), high(n), cnt(n), tmp(n);
	vector<vector<int>> has(n);
	ll res = 0;
	g.Solve([&](int r, vector<int>& u)
		{
			vector<int> vc;
			int time = 0;
			from[r] = -1;
			std::y_combinator([&](auto dfs, int x) -> void
				{
					u[x] = 1;
					low[x] = ++time;
					size[x] = 1;
					for (auto& [y, z] : v[x])
						if (!u[y])
						{
							from[y] = from[x] == -1 ? y : from[x];
							if (has[z].empty()) vc.push_back(z);
							has[z].push_back(y);
							dfs(y);
							size[x] += size[y];
						}
					high[x] = time;
					u[x] = 0;
				})(r);

			for (auto z : vc)
			{
				vector<int> p, p_left;
				for (auto x : has[z])
				{
					if (p.empty() || high[p.back()] < low[x])
						p.push_back(x);
					else
						p_left.push_back(x);
				}
				vector<int> q;
				for (auto x : p_left)
				{
					if (q.empty() || high[q.back()] < low[x])
						q.push_back(x);
				}

				int sum_cnt = 0;
				for (auto x : p) cnt[from[x]] = 0;

				for (auto x : p)
				{
					cnt[from[x]] += size[x];
					sum_cnt += size[x];
					tmp[x] = size[x];
				}
				int id = 0;
				for (auto x : q)
				{
					while (id + 1 < (int)p.size() && (low[p[id + 1]] < low[x] || low[p[id + 1]] == low[x] && high[p[id + 1]] > high[x]))
						id += 1;
					tmp[p[id]] -= size[x];
				}

				for (auto x : p)
					res += ll(size[r] - size[from[x]] - (sum_cnt - cnt[from[x]])) * tmp[x];
			}

			// do not forget to clean everything ever used.
			for (auto z : vc)
				has[z].clear();
		});
	writeln(res);
}

int main()
{
#if debug
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