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

#include <bits/stdc++.h>

namespace io {}
namespace algorithm {}
namespace data_structure {}

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

using ll = long long;
using ull = unsigned long long;
using ld = long double;

int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[] = { 0, -1, 0, 1, 1, -1, 1, -1 };

mt19937 rd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
//mt19937 rd(111);

void yes()
{
	writeln("YES");
}

void no()
{
	writeln("NO");
}

#ifndef MAXFLOW_H_
#define MAXFLOW_H_

#include <cassert>
#include <cstdint>
#include <vector>
#include <queue>
#include <utility>

namespace algorithm
{
	template<typename T>
	struct INF;
	template<>
	struct INF<int32_t>
	{
		static constexpr int32_t value = 0x3f3f3f3f;
	};
	template<>
	struct INF<int64_t>
	{
		static constexpr int64_t value = 0x3f3f3f3f3f3f3f3f;
	};
	template<>
	struct INF<double>
	{
		static constexpr double value = 1e100;
	};

	// Current implementation is based on Dinic's algorithm.
	// Complexity: O(n^2 m).
	// Special case: When the graph is bipartite, 
	template<typename FlowType>
	class MaxFlow
	{
	public:
		static constexpr FlowType FLOW_INF = INF<FlowType>::value;
		struct Edge
		{
			int to;
			FlowType cap;
			int rev;
			Edge(int to, FlowType cap, int rev) : to(to), cap(cap), rev(rev) { }
		};
		int n;
		std::vector<std::vector<Edge>> edge;
		int flow_s, flow_t;
		std::vector<int> level, ptr;
		int FindLevel()
		{
			std::fill(level.begin(), level.end(), 0);
			std::queue<int> q;
			q.push(flow_s);
			level[flow_s] = 1;
			while (!q.empty())
			{
				int x = q.front();
				q.pop();
				for (const auto& e : edge[x])
					if (!level[e.to] && e.cap > 0)
					{
						q.push(e.to);
						level[e.to] = level[x] + 1;
					}
			}
			return level[flow_t];
		}
		FlowType FindFlow(int x, FlowType flow)
		{
			if (x == flow_t || flow == 0) return flow;
			for (; ptr[x] < (int)edge[x].size(); ++ptr[x])
			{
				Edge& e = edge[x][ptr[x]];
				if (e.cap > 0 && level[e.to] == level[x] + 1)
				{
					FlowType tmp = FindFlow(e.to, std::min(flow, e.cap));
					if (tmp > 0)
					{
						e.cap -= tmp;
						edge[e.to][e.rev].cap += tmp;
						return tmp;
					}
				}
			}
			return 0;
		}
	public:
		explicit MaxFlow(int n) : n(n), edge(n), flow_s(0), flow_t(0) { }
		void AddEdge(int from, int to, FlowType cap)
		{
			assert(0 <= from && from < n && 0 <= to && to < n&& cap >= 0);
			edge[from].push_back(Edge(to, cap, (int)edge[to].size()));
			edge[to].push_back(Edge(from, 0, (int)edge[from].size() - 1));

			//writeln(from, ' ', to, ' ', cap);
		}
		FlowType Solve(int s, int t)
		{
			flow_s = s, flow_t = t;
			level.resize(n);
			ptr.resize(n);
			FlowType max_flow = 0;
			while (FindLevel())
			{
				std::fill(ptr.begin(), ptr.end(), 0);
				for (FlowType flow = 0; (flow = FindFlow(flow_s, FLOW_INF)) != 0; )
					max_flow += flow;
			}
			return max_flow;
		}
		std::pair<FlowType, std::vector<bool>> SolveCut(int s, int t)
		{
			FlowType flow = Solve(s, t);
			std::vector<bool> cut(n);
			std::queue<int> q;
			q.push(s);
			while (!q.empty())
			{
				int x = q.front();
				q.pop();
				for (const auto& e : edge[x])
					if (e.cap > 0 && !cut[e.to])
					{
						cut[e.to] = 1;
						q.push(e.to);
					}
			}
			return { flow, cut };
		}
	};
}

#endif

void solve()
{
	int n, m;
	read(n, m);
	vector<int> s(n), a(n);
	input(s), input(a);
	vector<pair<int, int>> edge(m);
	vector<int> b(n);
	for (auto& [x, y] : edge)
	{
		read(x, y);
		x -= 1; y -= 1;
		b[x] += 1; b[y] -= 1;
	}
	for (int i = 0; i < n; ++i)
		if (s[i]) if (abs(a[i]) % 2 != abs(b[i]) % 2) return no();

	MaxFlow<ll> g(n + 2);
	int S = n, T = n + 1;
	int ls = 0, rs = 0;
	ll sum = 0;
	for (int i = 0; i < n; ++i)
	{
		g.AddEdge(S, i, m);
		g.AddEdge(i, T, m);
		sum += m;
		if (s[i])
		{
			if (b[i] < a[i])
			{
				g.AddEdge(S, i, (a[i] - b[i]) / 2);
				ls += (a[i] - b[i]) / 2;
			}
			else if (b[i] > a[i])
			{
				g.AddEdge(i, T, (b[i] - a[i]) / 2);
				rs += (b[i] - a[i]) / 2;
			}
		}
	}
	//writeln("step1");
	for (int i = 0; i < n; ++i)
	{
		if (!s[i])
		{
			if (ls < rs)
				g.AddEdge(S, i, rs - ls);
			else if (ls > rs)
				g.AddEdge(i, T, ls - rs);
		}
	}
	//writeln("step2");
	for (auto [x, y] : edge)
	{
		g.AddEdge(y, x, 1);
	}
	//writeln("step3");
	auto flow = g.Solve(S, T);
	//writeln(flow, ' ', max(ls, rs));
	if (flow != sum + max(ls, rs)) return no();

	yes();
	for (int x = 0; x < n; ++x)
	{
		for (auto& e : g.edge[x])
		{
			if (0 <= e.to && e.to < n && e.cap == 0)
				writeln(e.to + 1, ' ', x + 1);
		}
	}
}

int main()
{
#if debug
	freopen("try.in", "r", stdin);
	//freopen("clean.out", "w", stdout);
#endif
	int tests = 1;
	//read(tests);
	for (int test = 1; test <= tests; ++test)
	{
		//write("Case #", test, ": ");
		solve();
	}
	return 0;
}