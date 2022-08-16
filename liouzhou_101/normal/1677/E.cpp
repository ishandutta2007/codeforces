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

#ifndef FENWICKTREE_H_
#define FENWICKTREE_H_

#include <cassert>

#include <algorithm>
#include <functional>
#include <type_traits>
#include <vector>

namespace data_structure
{
	template<typename T>
	constexpr auto lowbit(T x)
	{
		return x & -x;
	}
	// 0-indexed fenwick tree.
	// Operation can be:
	//     std::plus, std::bit_xor, decltype(std::min), decltype(std::max).
	// The corresponding init_value can be
	//     0, 0, INF, -INF
	// Currently only std::plus is checked.
	template<typename ValueType, typename Operation = std::plus<ValueType>>
	class FenwickTree
	{
	private:
		ValueType init_value;
		Operation operation;
		std::vector<ValueType> values;
		// Build in linear time.
		void Build()
		{
			for (int i = 1; i <= (int)values.size(); ++i)
				for (int j = lowbit(i) >> 1, pos = i ^ lowbit(i); j; j >>= 1)
					values[i - 1] = operation(std::move(values[i - 1]), values[(pos += j) - 1]);
		}
	public:
		explicit FenwickTree(int size, const Operation& operation = Operation(), const ValueType& init_value = 0) :
			values(size, init_value), operation(operation), init_value(init_value) { }
		template<typename InputIt>
		explicit FenwickTree(InputIt first, InputIt last, const Operation& operation = Operation(), const ValueType& init_value = ValueType()) :
			values(first, last), operation(operation), init_value(init_value)
		{
			Build();
		}
		ValueType Get(int pos)
		{
			if (!(0 <= pos && pos < (int)values.size())) return init_value;
			ValueType res(init_value);
			for (pos += 1; pos; pos ^= lowbit(pos))
				res = operation(std::move(res), values[pos - 1]);
			return res;
		}
		void Add(int pos, ValueType value)
		{
			assert(0 <= pos && pos < (int)values.size());
			for (pos += 1; pos <= values.size(); pos += lowbit(pos))
				values[pos - 1] = operation(std::move(values[pos - 1]), value);
		}
		
		template<typename T = ValueType>
		std::enable_if_t<std::is_same_v<Operation, std::plus<T>>, std::vector<T>> GetPlain()
		{
			std::vector<ValueType> res = values;
			for (int i = (int)values.size(); i >= 1; --i)
			{
				int k = lowbit(i);
				for (int j = 1, pos = i - 1; j < k; pos ^= j, j <<= 1)
					res[i - 1] -= res[pos - 1];
			}
			return res;
		}

		template<typename T = ValueType>
		std::enable_if_t<std::is_same_v<Operation, std::bit_xor<T>>, std::vector<T>> GetPlain()
		{
			std::vector<ValueType> res = values;
			for (int i = (int)values.size(); i >= 1; --i)
			{
				int k = lowbit(i);
				for (int j = 1, pos = i - 1; j < k; pos ^= j, j <<= 1)
					res[i - 1] ^= res[pos - 1];
			}
			return res;
		}
	};
}

#endif

#include <bits/stdc++.h>

using namespace std;
using namespace io;
//using namespace algorithm;
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
	int n, q;
	read(n, q);
	vector<int> a(n + 1);
	vector<int> pos(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		read(a[i]);
		pos[a[i]] = i;
	}

	vector<vector<int>> divisor(n + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; j += i)
			divisor[j].push_back(i);
	
	set<int> H;
	for (int i = 0; i <= n + 1; ++i) H.insert(i);
	vector<tuple<int, int, int, int>> ranges;
	for (int i = 1; i <= n; ++i)
	{
		int pz = pos[i];
		H.erase(pz);
		int R = *H.lower_bound(pz) - 1;
		int L = *prev(H.lower_bound(pz)) + 1;
		vector<pair<int, int>> v;
		for (auto d : divisor[i])
		{
			int x = d, y = i / d;
			if (x == y) continue;
			int px = pos[x], py = pos[y];
			int l = min({ px, py, pz });
			int r = max({ px, py, pz });
			if (L <= l && l <= pz && pz <= r && r <= R)
			{
				// [L, l], [r, R]
				v.push_back({ l, r });
			}
		}
		sort(v.begin(), v.end(), [](auto& a, auto& b)
			{
				return get<0>(a) < get<0>(b) || get<0>(a) == get<0>(b) && get<1>(a) > get<1>(b);
			});
		vector<pair<int, int>> w;
		for (auto& [l, r] : v)
		{
			while (!w.empty() && w.back().second >= r)
				w.pop_back();
			w.push_back({ l, r });
		}
		for (auto& [l, r] : w)
		{
			ranges.push_back({ L, l, r, R });
			L = l + 1;
			// writeln(i, ' ', L, ' ', l, ' ', r, ' ', R);
		}
	}

	vector<vector<pair<int, int>>> task(n + 1);
	for (int i = 0; i < q; ++i)
	{
		int x, y;
		read(x, y);
		task[y].push_back({ x, i });
	}

	// sum(1)
	// sum(l2), sum(r1)
	// sum(l2 * r1)
	// sum(r2-r1+1) sum(l2-l1+1)
	// sum((r2-r1+1)*(l2+1))
	// sum((l2-l1+1)*(r1-1))
	struct node
	{
		int idx;
		int x, y;
		ll val;
	};
	vector<vector<node>> ev(n + 2);
	for (auto& [l1, l2, r1, r2] : ranges)
	{
		ev[r1].push_back({ 0, l1, l2, (l2 + 1) });
		ev[r2 + 1].push_back({ 0, l1, l2, -(l2 + 1) });
		ev[r1].push_back({ 1, l1, l2, (r1 - 1) });
		ev[r2 + 1].push_back({ 1, l1, l2, -(r1 - 1) });
		ev[r1].push_back({ 2, l1, l2, (ll)(l2 + 1) * (r1 - 1) });
		ev[r2 + 1].push_back({ 2, l1, l2, -(ll)(l2 + 1) * (r1 - 1) });
		ev[r1].push_back({ 8, l1, l2, (ll)1 });
		ev[r2 + 1].push_back({ 8, l1, l2, -(ll)1 });

		ev[r2 + 1].push_back({ 3, 1, l1 - 1 , (ll)(l2 - l1 + 1) * (r2 - r1 + 1)});

		ev[r2 + 1].push_back({ 4, l1, l2, (r2 - r1 + 1) });
		ev[r2 + 1].push_back({ 5, l1, l2, (ll)(l2 + 1) * (r2 - r1 + 1) });

		ev[r1].push_back({ 6, 1, l1 - 1, (ll)(l2 - l1 + 1) });
		ev[r2 + 1].push_back({ 6, 1, l1 - 1, -(ll)(l2 - l1 + 1) });
		ev[r1].push_back({ 7, 1, l1 - 1, (ll)(l2 - l1 + 1) * (r1 - 1)});
		ev[r2 + 1].push_back({ 7, 1, l1 - 1, -(ll)(l2 - l1 + 1) * (r1 - 1) });
	}

	using namespace data_structure;
	vector<FenwickTree<ll>> tree(9, FenwickTree<ll>(n + 2));
	vector<ll> res(q);
	//writeln("-------");
	for (int i = 1; i <= n; ++i)
	{
		for (auto& [op, x, y, d] : ev[i])
		{
			//writeln(i, ' ', op, ' ', x, ' ', y, ' ', d);
			tree[op].Add(x, d);
			tree[op].Add(y + 1, -d);
		}
		int r = i;
		for (auto& [l, id] : task[i])
		{
			ll l2 = tree[0].Get(l);
			ll r1 = tree[1].Get(l);
			ll l2r1 = tree[2].Get(l);
			ll c = tree[8].Get(l);
			res[id] += l2 * r + l * r1 - l2r1 - c * l * r;

			ll slsr = tree[3].Get(l);
			res[id] += slsr;

			ll sr = tree[4].Get(l);
			ll l2sr = tree[5].Get(l);
			res[id] += l2sr - l * sr;

			ll sl = tree[6].Get(l);
			ll slr1 = tree[7].Get(l);
			res[id] += sl * r - slr1;
		}
	}
	print(res, "\n");
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