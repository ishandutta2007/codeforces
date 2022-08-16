#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

#ifndef HASH_H_
#define HASH_H

#include <unordered_set>
#include <unordered_map>
#include <chrono>

namespace data_structure
{
	template<typename ValueType>
	class Hash
	{
	private:
		static uint64_t splitmix64(uint64_t x) {
			// http://xorshift.di.unimi.it/splitmix64.c
			x += 0x9e3779b97f4a7c15;
			x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
			x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
			return x ^ (x >> 31);
		}
	public:
		size_t operator () (const ValueType& x) const
		{
			static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
			return splitmix64(x + FIXED_RANDOM);
		}
	};

	// Unhackable HashSet & HashMap
	// https://codeforces.com/blog/entry/62393
	template<typename ValueType>
	using HashSet = std::unordered_set<ValueType, Hash<ValueType>>;
	template<typename ValueType, typename KeyType>
	using HashMap = std::unordered_map<ValueType, KeyType, Hash<ValueType>>;
}

#endif

#ifndef BITS_H_
#define BITS_H_

#include <cstdint>

#ifdef __GNUC__

#define bit_popcount __builtin_popcount
#define bit_ctz __builtin_ctz
#define bit_clz __builtin_clz
#define bit_popcountll __builtin_popcountll
#define bit_ctzll __builtin_ctzll
#define bit_clzll __builtin_clzll

#else

static constexpr inline int32_t bit_popcount(uint32_t x)
{
	constexpr uint32_t m1 = 0x55555555;
	constexpr uint32_t m2 = 0x33333333;
	constexpr uint32_t m4 = 0x0f0f0f0f;
	constexpr uint32_t h01 = 0x01010101;
	x -= (x >> 1) & m1;
	x = (x & m2) + ((x >> 2) & m2);
	x = (x + (x >> 4)) & m4;
	return (x * h01) >> 24;
}

static constexpr inline int32_t bit_ctz(uint32_t x)
{
	return bit_popcount((x & -int32_t(x)) - 1);
}

static constexpr inline int32_t bit_clz(uint32_t x)
{
	int n = 0;
	if (!(x & 0xffff0000)) n += 16, x <<= 16;
	if (!(x & 0xff000000)) n += 8, x <<= 8;
	if (!(x & 0xf0000000)) n += 4, x <<= 4;
	if (!(x & 0xc0000000)) n += 2, x <<= 2;
	if (!(x & 0x80000000)) n += 1;
	return n;
}

static constexpr inline int32_t bit_popcountll(uint64_t x)
{
	constexpr uint64_t m1 = 0x5555555555555555;
	constexpr uint64_t m2 = 0x3333333333333333;
	constexpr uint64_t m4 = 0x0f0f0f0f0f0f0f0f;
	constexpr uint64_t h01 = 0x0101010101010101;
	x -= (x >> 1) & m1;
	x = (x & m2) + ((x >> 2) & m2);
	x = (x + (x >> 4)) & m4;
	return (x * h01) >> 56;
}

static constexpr inline int32_t bit_ctzll(uint64_t x)
{
	return bit_popcountll((x & -int64_t(x)) - 1);
}

static constexpr inline int32_t bit_clzll(uint64_t x)
{
	int n = 0;
	if (!(x & 0xffffffff00000000)) n += 32, x <<= 32;
	if (!(x & 0xffff000000000000)) n += 16, x <<= 16;
	if (!(x & 0xff00000000000000)) n += 8, x <<= 8;
	if (!(x & 0xf000000000000000)) n += 4, x <<= 4;
	if (!(x & 0xc000000000000000)) n += 2, x <<= 2;
	if (!(x & 0x8000000000000000)) n += 1;
	return n;
}

#endif

static constexpr inline int32_t bit_lg(uint32_t x)
{
	return 31 - bit_clz(x);
}

static constexpr inline int32_t bit_lgll(uint64_t x)
{
	return 63 - bit_clzll(x);
}

#endif

#ifndef BITSET_H_
#define BITSET_H_

#include <cassert>
#include <algorithm>
#include <vector>

namespace data_structure
{
	template<int n>
	class Bitset
	{
	private:
		constexpr static int size = (n >> 5) + 1;
		uint32_t a[size];
	public:
		Bitset()
		{
			std::fill_n(a, size, 0);
		}
		void Reset()
		{
			std::fill_n(a, size, 0);
		}
		void Set(int x)
		{
			a[x >> 5] |= 1 << (x & 31);
		}
		void Reset(int x)
		{
			a[x >> 5] &= 0xffffffff ^ (1 << (x & 31));
		}
		bool Test(int x)
		{
			return a[x >> 5] >> (x & 31) & 1;
		}

		// not checked
		Bitset& Flip()
		{
			for (int i = 0; i < size - 1; ++i)
				a[i] = ~a[i];
			a[size - 1] = ~a[size - 1] & ((1 << (n & 31)) - 1);
			return *this;
		}
		Bitset operator ~ () const
		{
			return Bitset(*this).Flip();
		}

		Bitset& operator <<= (int shift)
		{
			int block = shift >> 5;
			int offset = shift & 31;
			if (offset == 0)
			{
				for (int i = size - block - 1; i >= 0; --i)
					a[i + block] = a[i];
			}
			else
			{
				for (int i = size - block - 1; i >= 1; --i)
					a[i + block] = (a[i] << offset) | (a[i - 1] >> (32 - offset));
				a[block] = a[0] << offset;
			}
			std::fill_n(a, block, 0);
			return *this;
		}
		// not checked
		Bitset& operator >>= (int shift)
		{
			int block = shift >> 5;
			int offset = shift & 31;
			if (offset == 0)
			{
				for (int i = block; i < size; ++i)
					a[i - block] = a[i];
			}
			else
			{
				for (int i = block; i < size - 1; ++i)
					a[i - block] = (a[i] >> offset) | (a[i + 1] << (32 - offset));
				a[size - block - 1] = a[size - 1] >> offset;
			}
			std::fill_n(a + size - block, block, 0);
			return *this;
		}
		Bitset operator >> (int shift) const
		{
			return Bitset(*this) >>= shift;
		}
		Bitset operator << (int shift) const
		{
			return Bitset(*this) <<= shift;
		}

		Bitset& operator |= (const Bitset& rhs)
		{
			for (int i = 0; i < size; ++i)
				a[i] |= rhs.a[i];
			return *this;
		}
		Bitset& operator &= (const Bitset& rhs)
		{
			for (int i = 0; i < size; ++i)
				a[i] &= rhs.a[i];
			return *this;
		}
		Bitset& operator ^= (const Bitset& rhs)
		{
			for (int i = 0; i < size; ++i)
				a[i] ^= rhs.a[i];
			return *this;
		}
		Bitset operator | (const Bitset& rhs) const
		{
			return Bitset(*this) |= rhs;
		}
		Bitset operator & (const Bitset& rhs) const
		{
			return Bitset(*this) &= rhs;
		}
		Bitset operator ^ (const Bitset& rhs) const
		{
			return Bitset(*this) ^= rhs;
		}

		int FindFirst(int pos = 0)
		{
			if (pos >= n) return n;
			int block = pos >> 5;
			int shift = pos & 31;
			if (uint32_t tmp = a[block] >> shift << shift; tmp)
				return std::min(block << 5 | bit_ctz(tmp), n);
			for (++block; block < size; ++block)
				if (a[block])
					return std::min(block << 5 | bit_ctz(a[block]), n);
			return n;
		}

		// TODO: [And, Or, Xor] * [Shl, Shr]
		// Bitset& OrShl(int shift);
	};
}

#endif

#include <bits/stdc++.h>

using namespace std;
using namespace io;
//using namespace algorithm;
using namespace data_structure;

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
//using modular = algorithm::SafeModularInt32<1000000007>;
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

const int MAXN = 100010;
using bits = Bitset<MAXN>;

void solve()
{
	int n, m;
	read(n, m);
	int N = n * m;
	int B = sqrt(N);

	vector<vector<int>> v(n, vector<int>(m + 1));
	HashMap<int, int> c;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			read(v[i][j]);
			c[v[i][j]] += 1;
		}
		sort(v[i].begin() + 1, v[i].end());
		read(v[i][0]);
	}
	sort(v.begin(), v.end());

	HashMap<int, bits> bs;
	for (const auto& [x, y] : c)
		if (y > B)
		{
			bits& b = bs[x];
			for (int i = 0; i < n; ++i)
				if (find(v[i].begin() + 1, v[i].end(), x) != v[i].end())
					b.Set(i);
		}
	const int INF = 2000000010;
	int res = INF;
	bits b;
	for (int i = 0; i < n; ++i)
	{
		b.Reset();
		for (int j = 1; j <= m; ++j)
			if (bs.count(v[i][j])) b |= bs[v[i][j]];
		b.Flip();
		int j = b.FindFirst();
		while (j < n)
		{
			int flag = 0;
			for (int x = 1, y = 1; x <= m; ++x)
			{
				while (y <= m && v[j][y] < v[i][x]) ++y;
				if (y <= m && v[i][x] == v[j][y]) flag = 1;
			}
			if (!flag)
			{
				freshmin(res, v[i][0] + v[j][0]);
				break;
			}
			j = b.FindFirst(j + 1);
		}
	}
	if (res == INF) res = -1;
	writeln(res);
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