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

#include<cassert>

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

#ifndef FENWICKTREE2D_H_
#define FENWICKTREE2D_H_

namespace data_structure
{
	template<typename ValueType, typename Operation = std::plus<ValueType>>
	class FenwickTree2D
	{
	private:
		int n, m;
		const Operation& operation;
		const ValueType& init_value;
		std::vector<ValueType> values;
		int Position(int x, int y)
		{
			return x * m + y;
		}
		// TODO Build in linear time.
	public:
		explicit FenwickTree2D(int n, int m, const Operation& operation = Operation(), const ValueType& init_value = ValueType()) :
			n(n), m(m), operation(operation), init_value(init_value), values(n * m, init_value)
		{
		}
		ValueType Get(int px, int py)
		{
			px = std::min(px, n - 1);
			py = std::min(py, m - 1);
			if (px < 0 || py < 0) return init_value;
			ValueType res = init_value;
			for (int x = px + 1; x; x ^= lowbit(x))
				for (int y = py + 1; y; y ^= lowbit(y))
					res = operation(std::move(res), values[Position(x - 1, y - 1)]);
			return res;
		}
		void Add(int px, int py, ValueType value)
		{
			assert(0 <= px && px < n && 0 <= py && py < m);
			for (int x = px + 1; x <= n; x += lowbit(x))
				for (int y = py + 1; y <= m; y += lowbit(y))
					values[Position(x - 1, y - 1)] = operation(std::move(values[Position(x - 1, y - 1)]), value);
		}
	};
}

#endif

#include <bits/stdc++.h>

using namespace std;
using namespace io;
//using namespace algorithm;
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
//using modular = algorithm::Modular<uint32_t, 998244353, false, 3>;
//using modular = algorithm::SafeModularInt32<1000000007>;

//using modint = algorithm::ModInt<modular>;
//using poly = algorithm::Polynomial<modular>;
//using linear = algorithm::LinearRecurrence<modular>;

using ll = int64_t;
using ld = double;

//const int INF = 1000000000;
//const ll INF = 1000000000000000000LL;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
	int n, m;
	read(n, m);
	struct node
	{
		int e, ei, ej, eij;
		node (int e = 0, int ei = 0, int ej = 0, int eij = 0) : e(e), ei(ei), ej(ej), eij(eij) { }
		node operator + (const node& rhs) const
		{
			return node(e ^ rhs.e, ei ^ rhs.ei, ej ^ rhs.ej, eij ^ rhs.eij);
		}
	};
	data_structure::FenwickTree2D<node> g(n, n);
	while (m--)
	{
		int op;
		read(op);
		if (op == 2)
		{
			int a, b, c, d, p;
			read(a, b, c, d, p);
			a -= 1; b -= 1;
			auto add = [&](int x, int y, int p)
			{
				if (x < n && y < n) g.Add(x, y, { p, p * (x & 1), p * (y & 1), p * (x & 1) * (y & 1) });
			};
			add(a, b, p);
			add(a, d, p);
			add(c, b, p);
			add(c, d, p);
		}
		else
		{
			int a, b, c, d;
			read(a, b, c, d);
			a -= 1; b -= 1; c -= 1; d -= 1;
			auto get = [&](int x, int y)
			{
				auto [e, ei, ej, eij] = g.Get(x, y);
				return e * ((x + 1) & 1) * ((y + 1) & 1) ^ ei * ((y + 1) & 1) ^ ej * ((x + 1) & 1) ^ eij;
			};
			int res = get(c, d) ^ get(a - 1, d) ^ get(c, b - 1) ^ get(a - 1, b - 1);
			writeln(res);
		}
	}
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