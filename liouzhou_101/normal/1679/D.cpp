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

#ifndef DIRECTEDGRAPH_H_
#define DIRECTEDGRAPH_H_

#include <cassert>
#include <algorithm>
#include <utility>
#include <vector>

namespace algorithm
{
	// Basic algorithms for 0-indexed (unweighted) directed graph, e.g.,
	// topological sort, strong connected component (Tarjan's algorithm).
	class DirectedGraph
	{
	private:
		int n;
		std::vector<std::vector<int>> edge;

		int time, scc_cnt;
		std::vector<int> dfn, low, stack, in_stack, belong;

		// References:
		// [Tar72] R. Tarjan. Depth-first search and linear graph algorithms. 
		// "SIAM Journal on Computing", 1(2): 146-160.
		void Tarjan(int x)
		{
			dfn[x] = low[x] = ++time;
			stack.push_back(x);
			in_stack[x] = 1;
			for (auto y : edge[x])
			{
				if (dfn[y] == 0)
				{
					Tarjan(y);
					low[x] = std::min(low[x], low[y]);
				}
				else if (in_stack[y])
					low[x] = std::min(low[x], dfn[y]);
			}
			if (dfn[x] == low[x])
			{
				while (1)
				{
					int cur = stack.back();
					stack.pop_back();
					in_stack[cur] = 0;
					belong[cur] = scc_cnt;
					if (cur == x) break;
				}
				++scc_cnt;
			}
		}
	public:
		explicit DirectedGraph(int n) : n(n), edge(n), time(0), scc_cnt(0) { }
		std::vector<int>& operator [] (int x)
		{
			assert(0 <= x && x < n);
			return edge[x];
		}
		const std::vector<int>& operator [] (int x) const
		{
			assert(0 <= x && x < n);
			return edge[x];
		}
		void AddEdge(int x, int y)
		{
			assert(0 <= x && x < n && 0 <= y && y < n);
			edge[x].push_back(y);
		}
		int NumOfVertices() const
		{
			return n;
		}
		void RemoveDuplicatedEdges()
		{
			for (int x = 0; x < n; ++x)
			{
				sort(edge[x].begin(), edge[x].end());
				edge[x].erase(std::unique(edge[x].begin(), edge[x].end()), edge[x].end());
			}
		}
		void RemoveSelfLoops()
		{
			for (int x = 0; x < n; ++x)
			{
				std::vector<int> tmp(edge[x].size());
				auto end = std::copy_if(edge[x].begin(), edge[x].end(), tmp.begin(), [&](int y)
					{
						return y != x;
					});
				tmp.resize(end - tmp.begin());
				std::swap(edge[x], tmp);
			}
		}
		void MakeSimple()
		{
			RemoveDuplicatedEdges();
			RemoveSelfLoops();
		}
		// Return the topological sort if the graph is acyclic.
		// Otherwise, the size of the returned vector < n.
		std::vector<int> TopologicalSort() const
		{
			std::vector<int> order;
			order.reserve(n);
			std::vector<int> in_degree(n);
			for (int x = 0; x < n; ++x)
				for (auto y : edge[x])
					in_degree[y] += 1;
			for (int x = 0; x < n; ++x)
				if (in_degree[x] == 0)
					order.push_back(x);
			for (int i = 0; i < (int)order.size(); ++i)
			{
				int x = order[i];
				for (auto y : edge[x])
				{
					in_degree[y] -= 1;
					if (in_degree[y] == 0)
						order.push_back(y);
				}
			}
			return order;
		}
		// Shrink each strongly connected component (SCC) to a vertex, which returns a shrinked 
		// directed acyclic graph (DAG) H called component graph and a mapping f: V(G) -> V(H) such that
		//   1) Each vertex of H corresponds to a SCC in G,
		//   2) Two vertices x and y in G are in the same SCC iff f(x) == f(y).
		// H is simple, i.e., duplicated edges are deleted.
		// Moreover, 0, 1, 2, ... is a topological order of H.
		std::pair<DirectedGraph, std::vector<int>> StrongConnectedComponents()
		{
			time = 0;
			scc_cnt = 0;
			dfn.resize(n, 0);
			low.resize(n, 0);
			in_stack.resize(n, 0);
			belong.resize(n, 0);
			stack.clear();
			stack.reserve(n);
			for (int x = 0; x < n; ++x)
				if (dfn[x] == 0)
					Tarjan(x);
			for (auto& x : belong)
				x = scc_cnt - x - 1;
			DirectedGraph scc(scc_cnt);
			for (int x = 0; x < n; ++x)
				for (auto y : edge[x])
					if (belong[x] != belong[y])
						scc.AddEdge(belong[x], belong[y]);
			scc.RemoveDuplicatedEdges();
			return { scc, belong };
		}
	};
}

#endif

#include <bits/stdc++.h>

using namespace std;
using namespace io;
using namespace algorithm;
//using namespace data_structure;

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
using ld = double;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
	int n, m;
	ll k;
	read(n, m, k);
	if (k > n) k = n + 1;

	vector<int> a(n);
	input(a);
	vector<vector<int>> v(n);
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		read(x, y); x -= 1; y -= 1;
		v[x].push_back(y);
	}

	const int INF = 1000000000;
	auto check = [&](int m)
	{
		DirectedGraph g(n);
		for (int i = 0; i < n; ++i)
		{
			if (a[i] > m) continue;
			for (auto j : v[i])
			{
				if (a[j] > m) continue;
				g.AddEdge(i, j);
			}
		}
		auto [h, to] = g.StrongConnectedComponents();
		auto ord = h.TopologicalSort();
		reverse(ord.begin(), ord.end());
		vector<int> sz(h.NumOfVertices()), mv(h.NumOfVertices(), INF);
		for (int i = 0; i < n; ++i)
		{
			sz[to[i]] += 1;
			freshmin(mv[to[i]], a[i]);
		}
		vector<int> dp(h.NumOfVertices());
		for (auto x : ord)
		{
			if (sz[x] >= 2)
				dp[x] = n + 1;
			else
			{
				if (mv[x] <= m)
				{
					for (auto y : h[x])
					{
						freshmax(dp[x], dp[y]);
					}
					dp[x] += 1;
				}
				else dp[x] = -INF;
			}
			if (dp[x] >= k)
				return true;
		}
		return false;
	};

	int L = 0, R = 1000000010;
	int res = -1;
	while (L <= R)
	{
		int m = (L + R) / 2;
		if (check(m))
		{
			res = m;
			R = m - 1;
		}
		else
			L = m + 1;
	}
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