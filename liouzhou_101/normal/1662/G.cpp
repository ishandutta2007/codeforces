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


#ifndef MODINT_H_
#define MODINT_H_

#include <cassert>
#include <cstdint>

#include <chrono>
#include <functional>
#include <random>
#include <type_traits>
#include <vector>

#ifdef __SIZEOF_INT128__
namespace std
{
	template<> struct make_signed<__int128_t> { using type = __int128_t; };
	template<> struct make_signed<__uint128_t> { using type = __int128_t; };
	template<> struct make_unsigned<__int128_t> { using type = __uint128_t; };
	template<> struct make_unsigned<__uint128_t> { using type = __uint128_t; };
}
#endif

namespace algorithm
{
#ifdef __SIZEOF_INT128__
	constexpr bool enable_int128 = true;
	using int128_t = __int128_t;
	using uint128_t = __uint128_t;
#else
	constexpr bool enable_int128 = false;
#endif

	template<typename ValueType> struct Long { using Type = ValueType; };
	template<> struct Long<int8_t> { using Type = int16_t; };
	template<> struct Long<uint8_t> { using Type = uint16_t; };
	template<> struct Long<int16_t> { using Type = int32_t; };
	template<> struct Long<uint16_t> { using Type = uint32_t; };
	template<> struct Long<int32_t> { using Type = int64_t; };
	template<> struct Long<uint32_t> { using Type = uint64_t; };
#ifdef __SIZEOF_INT128__
	template<> struct Long<int64_t> { using Type = int128_t; };
	template<> struct Long<uint64_t> { using Type = uint128_t; };
#endif

	using float80_t = long double;
	inline uint64_t mod_multiply(uint64_t a, uint64_t b, uint64_t m, float80_t mi)
	{
		uint64_t c = a * b - uint64_t(float80_t(a) * float80_t(b) * mi + float80_t(0.5)) * m;
		return int64_t(c) < 0 ? c + m : c;
	}

	template<typename ValueType, ValueType modular, bool safe_option = true, ValueType primitive_root = 0, bool ntt_option = primitive_root != 0>
	class Modular
	{
	public:
		using Type = ValueType;
		using DType = typename Long<Type>::Type;
		static_assert(std::is_unsigned_v<Type>);
		using SignedType = std::make_signed_t<Type>;
		using UnsignedType = std::make_unsigned_t<Type>;
		using SignedDType = std::make_signed_t<DType>;
		using UnsignedDType = std::make_unsigned_t<DType>;

		static constexpr Type mod = modular;
		static constexpr bool safe = safe_option || (!safe_option && modular % 2 == 0);
		static_assert(mod >= 1 && (safe || mod % 2 == 1));
		static constexpr float80_t mod_inv = float80_t(1) / mod;
		static constexpr Type omega = primitive_root;
		static constexpr bool ntt = ntt_option;

		static constexpr Type MultiplicativeInverse(Type value, int loop = 6, Type result = 1)
		{
			return loop == 0 ? result : MultiplicativeInverse(value, loop - 1, result * (2 - result * value));
		}
		static constexpr Type inv = MultiplicativeInverse(mod);
		static constexpr Type r2 = DType(-SignedDType(mod)) % mod;
		static_assert(safe || !safe && inv * mod == 1);
	};

	template<uint32_t modular, uint32_t root = 0>
	using SafeModularInt32 = Modular<uint32_t, modular, true, root>;

	template<uint32_t modular, uint32_t root = 0>
	using UnsafeModularInt32 = Modular<uint32_t, modular, false, root>;

	template<uint64_t modular, uint64_t root = 0>
	using SafeModularInt64 = Modular<uint64_t, modular, true, root>;

	template<uint64_t modular, uint64_t root = 0>
	using UnsafeModularInt64 = Modular<uint64_t, modular, false, root>;

	template<typename ValueType, bool safe_option = true, bool ntt_option = false, int id = 0>
	class UserModular
	{
	public:
		using Type = ValueType;
		using DType = typename Long<Type>::Type;
		static_assert(std::is_unsigned_v<Type>);
		using SignedType = std::make_signed_t<Type>;
		using UnsignedType = std::make_unsigned_t<Type>;
		using SignedDType = std::make_signed_t<DType>;
		using UnsignedDType = std::make_unsigned_t<DType>;

		static inline Type mod = 1;
		static constexpr bool safe = safe_option;
		static constexpr bool ntt = ntt_option;
		static inline float80_t mod_inv = 1;
		static inline Type inv = Modular<uint32_t, 1>::MultiplicativeInverse(1);
		static inline Type r2 = 0;
		static void SetModular(Type modular)
		{
			assert(modular >= 1);
			mod = modular;
			assert(mod >= 1 && (safe || mod % 2 == 1));
			mod_inv = float80_t(1) / mod;
			inv = Modular<Type, 1>::MultiplicativeInverse(mod);
			r2 = DType(-SignedDType(mod)) % mod;
			assert(safe || !safe && inv * mod == 1);
		}
	};

	using SafeUserModularInt32 = UserModular<uint32_t>;

	using UnsafeUserModularInt32 = UserModular<uint32_t, false>;

	using SafeUserModularInt64 = UserModular<uint64_t>;

#ifdef __SIZEOF_INT128__
	using UnsafeUserModularInt64 = UserModular<uint64_t, false>;
#endif

	template<typename Modular>
	class ModInt
	{
	public:
		using Type = typename Modular::Type;
		using DType = typename Modular::DType;
		using SignedType = typename Modular::SignedType;
		using UnsignedType = typename Modular::UnsignedType;
		using SignedDType = typename Modular::SignedDType;
		using UnsignedDType = typename Modular::UnsignedDType;
		static constexpr int bits = sizeof(Type) * 8;
	private:
		// Montgomery multiplication.
		Type value;
		static Type Reduce(DType x)
		{
			Type y = Type(x >> bits) - Type((DType(Type(x) * Modular::inv) * Modular::mod) >> bits);
			return SignedType(y) < 0 ? y + Modular::mod : y;
		}
		static Type Init(Type x)
		{
			return Reduce(DType(x) * Modular::r2);
		}
	public:
		ModInt()
		{
			this->value = 0;
		}
		template<typename ValueType>
		ModInt(const ValueType& value)
		{
			if constexpr (std::is_unsigned_v<ValueType>)
			{
				if constexpr (Modular::safe)
				{
					this->value = value < Modular::mod ? Type(value) : Type(value % Modular::mod);
				}
				else if constexpr (sizeof(ValueType) <= sizeof(Type))
				{
					this->value = Init(value);
				}
				else
				{
					this->value = Init(value % Modular::mod);
				}
			}
			else if constexpr (std::is_signed_v<ValueType>)
			{
				this->value = value >= 0 ? ModInt(std::make_unsigned_t<ValueType>(value)).value : (-ModInt(std::make_unsigned_t<ValueType>(-value))).value;
			}
			else if constexpr (std::is_same_v<ValueType, ModInt>)
			{
				this->value = value.value;
			}
			else
			{
				this->value = ModInt(value.GetValue()).value;
			}
		}
		ModInt& operator += (ModInt rhs)
		{
			this->value += rhs.value - Modular::mod;
			if (SignedType(this->value) < 0) this->value += Modular::mod;
			return *this;
		}
		ModInt& operator -= (ModInt rhs)
		{
			this->value -= rhs.value;
			if (SignedType(this->value) < 0) this->value += Modular::mod;
			return *this;
		}
		ModInt& operator *= (ModInt rhs)
		{
			if constexpr (Modular::safe)
			{
				//if constexpr (std::is_same_v<Type, uint64_t> && !enable_int128)
				if constexpr (std::is_same_v<Type, uint64_t>) // remove !enable_int128 for faster multiplication
				{
					this->value = mod_multiply(this->value, rhs.value, Modular::mod, Modular::mod_inv);
				}
				else
				{
					this->value = DType(this->value) * rhs.value % Modular::mod;
				}
			}
			else
			{
				static_assert(std::is_same_v<Type, uint32_t> || enable_int128);
				this->value = Reduce(DType(this->value) * rhs.value);
			}
			return *this;
		}
		template<typename ExpType>
		ModInt Pow(ExpType exp) const
		{
			ModInt res(1);
			for (ModInt base = *this; exp; exp >>= 1, base *= base)
				if (exp & 1) res *= base;
			return res;
		}
		ModInt Inverse() const
		{
			return this->Pow(Modular::mod - 2);
		}
		ModInt& operator /= (ModInt rhs)
		{
			return *this *= rhs.Inverse();
		}
		friend ModInt operator + (const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) += rhs; }
		friend ModInt operator - (const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) -= rhs; }
		friend ModInt operator * (const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) *= rhs; }
		friend ModInt operator / (const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) /= rhs; }
		ModInt operator - () const { return ModInt(0) - *this; }
		Type GetValue() const
		{
			if constexpr (Modular::safe)
			{
				return this->value;
			}
			else
			{
				return Reduce(this->value);
			}
		}
		friend bool operator == (const ModInt& lhs, const ModInt& rhs) { return lhs.value == rhs.value; }
		friend bool operator != (const ModInt& lhs, const ModInt& rhs) { return lhs.value != rhs.value; }
		friend bool operator < (const ModInt& lhs, const ModInt& rhs) { return lhs.GetValue() < rhs.GetValue(); }
		friend bool operator > (const ModInt& lhs, const ModInt& rhs) { return lhs.GetValue() > rhs.GetValue(); }
		friend bool operator <= (const ModInt& lhs, const ModInt& rhs) { return lhs.GetValue() <= rhs.GetValue(); }
		friend bool operator >= (const ModInt& lhs, const ModInt& rhs) { return lhs.GetValue() >= rhs.GetValue(); }

		// Prepare inverses of 0, 1, 2, ..., n, where 0^(-1) = 0.
		static inline std::vector<ModInt> inv = std::vector<ModInt>();
		static void PrepareInverses(int n)
		{
			if (n < int(inv.size())) return;
			int m = inv.size();
			inv.resize(n + 1);
			inv[0] = 0;
			if (1 <= n) inv[1] = 1;
			for (int i = std::max(m, 2); i <= n; ++i)
				inv[i] = inv[Modular::mod % i] * (Modular::mod - Modular::mod / i);
		}
		static ModInt Inv(int n)
		{
			PrepareInverses(n);
			return inv[n];
		}
		static inline std::vector<ModInt> factorial = std::vector<ModInt>();
		static inline std::vector<ModInt> inv_factorial = std::vector<ModInt>();
		static void PrepareFactorials(int n)
		{
			if (n < (int)factorial.size()) return;
			PrepareInverses(n);
			int m = factorial.size();
			factorial.resize(n + 1);
			inv_factorial.resize(n + 1);
			factorial[0] = inv_factorial[0] = 1;
			for (int i = std::max(m, 1); i <= n; ++i)
			{
				factorial[i] = factorial[i - 1] * i;
				inv_factorial[i] = inv_factorial[i - 1] * inv[i];
			}
		}
		static void Reset()
		{
			inv.clear();
			factorial.clear();
			inv_factorial.clear();
		}
		static ModInt Factorial(int n)
		{
			PrepareFactorials(n);
			return factorial[n];
		}
		static ModInt InvFactorial(int n)
		{
			PrepareFactorials(n);
			return inv_factorial[n];
		}
		static ModInt Binomial(int n, int m)
		{
			if (m < 0 || m > n) return 0;
			PrepareFactorials(n);
			return factorial[n] * inv_factorial[m] * inv_factorial[n - m];
		}

		// only work for odd prime modular.
		static ModInt Legendre(ModInt n)
		{
			return n.Pow((Modular::mod - 1) >> 1);
		}
		static bool HasQuadraticResidue(ModInt n)
		{
			return Legendre(n) + 1 != 0;
		}
		static ModInt QuadraticResidue(ModInt n)
		{
			assert(HasQuadraticResidue(n));
			if (n == 0) return 0;
			std::default_random_engine gen((int)std::chrono::system_clock::now().time_since_epoch().count());
			std::uniform_int_distribution<Type> distribution(0, Modular::mod - 1);
			ModInt a, w;
			while (1)
			{
				a = distribution(gen);
				w = a * a - n;
				if (!HasQuadraticResidue(w)) break;
			}
			struct Number
			{
				ModInt a, b;
			};
			auto multiply = [&](Number x, Number y) -> Number
			{
				return Number{ x.a * y.a + x.b * y.b * w, x.a * y.b + x.b * y.a };
			};
			std::function<Number(Number, Type)> power = [&](Number x, Type exp) -> Number
			{
				if (exp == 0) return Number{ 1, 0 };
				Number t = power(x, exp >> 1);
				t = multiply(t, t);
				if (exp & 1) t = multiply(t, x);
				return t;
			};
			ModInt x = power(Number{ a, 1 }, (Modular::mod + 1) >> 1).a;
			return std::min(x.GetValue(), (-x).GetValue());
		}
	};
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

#ifndef NTT_H_
#define NTT_H_


namespace algorithm
{
	template<typename, typename = void>
	struct has_omega : std::false_type { };

	template<typename T>
	struct has_omega<T, std::void_t<decltype(T::omega)>> : std::true_type { };

	template<typename T>
	inline constexpr bool has_omega_v = has_omega<T>::value;

	template<typename Modular, bool safe_option = Modular::safe>
	class NTT
	{
	private:
		using Type = ModInt<Modular>;
		using ModType = decltype(Modular::mod);
		static inline int level = 0;
		static inline std::vector<Type> roots = std::vector<Type>();
		static inline std::vector<Type> iroots = std::vector<Type>();
		static inline std::vector<Type> dw = std::vector<Type>();
		static inline std::vector<Type> idw = std::vector<Type>();
		static constexpr int multiply_n_threshold = 64;
		static constexpr int multiply_m_threshold = 32;
	public:
		static Type FindRoot()
		{
			ModType size = ModType(1) << level;
			Type root = 2;
			while (!(root.Pow(size) == 1 && root.Pow(size / 2) != 1))
				root += 1;
			return root;
		}
	private:
		static void Transform(std::vector<Type>& c)
		{
			const int n = c.size();
			const int logn = bit_ctz(n), nh = n >> 1;
			const Type one = 1, imag = roots[level - 2];
			if (logn & 1)
			{
				for (int i = 0; i < nh; ++i)
				{
					Type a = c[i], b = c[i + nh];
					c[i] = a + b;
					c[i + nh] = a - b;
				}
			}
			for (int e = logn & ~1; e >= 2; e -= 2)
			{
				const int m = 1 << e, m4 = m >> 2;
				Type w2 = one;
				for (int i = 0; i < n; i += m)
				{
					Type w1 = w2 * w2, w3 = w1 * w2;
					for (int j = i; j < i + m4; ++j)
					{
						Type a0 = c[j], a1 = c[j + m4] * w2;
						Type a2 = c[j + m4 * 2] * w1, a3 = c[j + m4 * 3] * w3;
						Type t02p = a0 + a2, t13p = a1 + a3;
						Type t02m = a0 - a2, t13m = (a1 - a3) * imag;
						c[j] = t02p + t13p;
						c[j + m4] = t02p - t13p;
						c[j + m4 * 2] = t02m + t13m;
						c[j + m4 * 3] = t02m - t13m;
					}
					w2 *= dw[bit_ctz(~(i >> e))];
				}
			}
		}
		static void InvTransform(std::vector<Type>& c)
		{
			const int n = c.size();
			const int logn = bit_ctz(n), nh = n >> 1;
			const Type one = 1, imag = iroots[level - 2];
			for (int e = 2; e <= logn; e += 2)
			{
				const int m = 1 << e, m4 = m >> 2;
				Type w2 = one;
				for (int i = 0; i < n; i += m)
				{
					Type w1 = w2 * w2, w3 = w1 * w2;
					for (int j = i; j < i + m4; ++j)
					{
						Type a0 = c[j], a1 = c[j + m4];
						Type a2 = c[j + m4 * 2], a3 = c[j + m4 * 3];
						Type t01p = a0 + a1, t23p = a2 + a3;
						Type t01m = a0 - a1, t23m = (a2 - a3) * imag;
						c[j] = t01p + t23p;
						c[j + m4 * 2] = (t01p - t23p) * w1;
						c[j + m4] = (t01m + t23m) * w2;
						c[j + m4 * 3] = (t01m - t23m) * w3;
					}
					w2 *= idw[bit_ctz(~(i >> e))];
				}
			}
			if (logn & 1)
			{
				for (int i = 0; i < nh; ++i)
				{
					Type a = c[i], b = c[i + nh];
					c[i] = a + b;
					c[i + nh] = a - b;
				}
			}
		}
		static void PrepareRoots()
		{
			level = bit_ctzll(Modular::mod - 1);
			roots = std::vector<Type>(level);
			iroots = std::vector<Type>(level);
			if constexpr (has_omega_v<Modular>)
			{
				if (Modular::omega != 0)
					roots[0] = Type(Modular::omega).Pow((Modular::mod - 1) >> level);
				else
					roots[0] = FindRoot().Pow((Modular::mod - 1) >> level);
			}
			else
			{
				roots[0] = FindRoot().Pow((Modular::mod - 1) >> level);
			}
			iroots[0] = roots[0].Inverse();
			for (int i = 1; i < level; ++i)
			{
				roots[i] = roots[i - 1] * roots[i - 1];
				iroots[i] = iroots[i - 1] * iroots[i - 1];
			}
			dw = std::vector<Type>(level - 1);
			dw[0] = roots[level - 3];
			for (int i = 1; i < level - 2; ++i)
				dw[i] = dw[i - 1] * iroots[level - 1 - i] * roots[level - 3 - i];
			dw[level - 2] = dw[level - 3] * iroots[1];
			idw = std::vector<Type>(level - 1);
			idw[0] = iroots[level - 3];
			for (int i = 1; i < level - 2; ++i)
				idw[i] = idw[i - 1] * roots[level - 1 - i] * iroots[level - 3 - i];
			idw[level - 2] = idw[level - 3] * roots[1];
		}
	public:
		static void Reset()
		{
			roots.clear();
			iroots.clear();
			dw.clear();
			idw.clear();
		}
		static std::vector<Type> Multiply(std::vector<Type> a, std::vector<Type> b)
		{
			int n = a.size(), m = b.size();
			int s = n + m - 1;
			if (std::max(n, m) <= multiply_n_threshold || std::min(n, m) <= multiply_m_threshold)
			{
				std::vector<Type> c(s);
				for (int i = 0; i < n; ++i)
					for (int j = 0; j < m; ++j)
						c[i + j] += a[i] * b[j];
				return c;
			}
			if constexpr (Modular::ntt)
			{
				if (roots.empty()) PrepareRoots();
				int size = 1 << (31 - bit_clz(2 * s - 1));
				assert(ModType(size) <= ModType(1) << level);
				Type inv = Type(size).Inverse();
				if (a == b)
				{
					a.resize(size);
					Transform(a);
					for (auto& x : a) x *= x * inv;
				}
				else
				{
					a.resize(size);
					b.resize(size);
					Transform(a);
					Transform(b);
					for (int i = 0; i < size; ++i) a[i] *= b[i] * inv;
				}
				InvTransform(a);
				a.resize(s);
				return a;
			}
			else
			{
				using modular1 = algorithm::Modular<uint32_t, 1484783617, safe_option, 5>;
				using modular2 = algorithm::Modular<uint32_t, 1711276033, safe_option, 29>;
				using modular3 = algorithm::Modular<uint32_t, 1811939329, safe_option, 13>;
				using modint1 = ModInt<modular1>;
				using modint2 = ModInt<modular2>;
				using modint3 = ModInt<modular3>;
				std::vector<modint1> a1(a.begin(), a.end()), b1(b.begin(), b.end());
				std::vector<modint1> c1 = NTT<modular1>::Multiply(a1, b1);
				std::vector<modint2> a2(a.begin(), a.end()), b2(b.begin(), b.end());
				std::vector<modint2> c2 = NTT<modular2>::Multiply(a2, b2);
				std::vector<modint3> a3(a.begin(), a.end()), b3(b.begin(), b.end());
				std::vector<modint3> c3 = NTT<modular3>::Multiply(a3, b3);
				int s = c1.size();
				assert(s == c2.size() && s == c3.size());
				std::vector<Type> c(s);
				// See "CRT.h" for a detailed implementation for Chinese Remainder Theorem. 
				// We explicitly repeat it here for efficiency.
				constexpr uint32_t m1 = modular1::mod, m2 = modular2::mod, m3 = modular3::mod;
				constexpr uint64_t m12 = uint64_t(m1) * uint64_t(m2);
				Type m12mod = m12;
				modint2 m1_inv2 = modint2(m1).Inverse();
				modint3 m12_inv3 = modint3(m12).Inverse();
				for (int i = 0; i < s; ++i)
				{
					//a12 = a1 + uint64_t(a2 + modular2::mod - a1) * m1_inv2 % m2 * m1;
					uint64_t c12 = c1[i].GetValue() + ((c2[i] - modint2(c1[i])) * m1_inv2).GetValue() * uint64_t(m1);
					c[i] = Type(c12) + Type((c3[i] - modint3(c12)) * m12_inv3) * m12mod;
				}
				return c;
			}
			/*
			else if constexpr (std::is_same_v<typename Modular::Type, uint32_t>)
			{
				// max element <= 2^31 - 1 < 2.15 * 10^9
				// assume final size <= 2^23 < 8.4 * 10^6
				// max result <= (2.15 * 10^9)^2 * 8.4 * 10^6 < 3.89 * 10^25
				if constexpr (!enable_int128)
				//if constexpr (true)
				{
					using modular1 = algorithm::Modular<uint32_t, 1484783617, safe_option, 5>;
					using modular2 = algorithm::Modular<uint32_t, 1711276033, safe_option, 29>;
					using modular3 = algorithm::Modular<uint32_t, 1811939329, safe_option, 13>;
					using modint1 = ModInt<modular1>;
					using modint2 = ModInt<modular2>;
					using modint3 = ModInt<modular3>;
					std::vector<modint1> a1(a.begin(), a.end()), b1(b.begin(), b.end());
					std::vector<modint1> c1 = NTT<modular1>::Multiply(a1, b1);
					std::vector<modint2> a2(a.begin(), a.end()), b2(b.begin(), b.end());
					std::vector<modint2> c2 = NTT<modular2>::Multiply(a2, b2);
					std::vector<modint3> a3(a.begin(), a.end()), b3(b.begin(), b.end());
					std::vector<modint3> c3 = NTT<modular3>::Multiply(a3, b3);
					int s = c1.size();
					assert(s == c2.size() && s == c3.size());
					std::vector<Type> c(s);
					// See "CRT.h" for a detailed implementation for Chinese Remainder Theorem. 
					// We explicitly repeat it here for efficiency.
					constexpr uint32_t m1 = modular1::mod, m2 = modular2::mod, m3 = modular3::mod;
					constexpr uint64_t m12 = uint64_t(m1) * uint64_t(m2);
					Type m12mod = m12;
					modint2 m1_inv2 = modint2(m1).Inverse();
					modint3 m12_inv3 = modint3(m12).Inverse();
					for (int i = 0; i < s; ++i)
					{
						//a12 = a1 + uint64_t(a2 + modular2::mod - a1) * m1_inv2 % m2 * m1;
						uint64_t c12 = c1[i].GetValue() + ((c2[i] - modint2(c1[i])) * m1_inv2).GetValue() * uint64_t(m1);
						c[i] = Type(c12) + Type((c3[i] - modint3(c12)) * m12_inv3) * m12mod;
					}
					return c;
				}
				else
				{
					using modular1 = algorithm::Modular<uint64_t, 999999999817285633, safe_option, 5>;
					using modular2 = algorithm::Modular<uint64_t, 999999999708233729, safe_option, 3>;
					using modint1 = ModInt<modular1>;
					using modint2 = ModInt<modular2>;
					std::vector<modint1> a1(a.begin(), a.end()), b1(b.begin(), b.end());
					std::vector<modint1> c1 = NTT<modular1>::Multiply(a1, b1);
					std::vector<modint2> a2(a.begin(), a.end()), b2(b.begin(), b.end());
					std::vector<modint2> c2 = NTT<modular2>::Multiply(a2, b2);
					int s = c1.size();
					assert(s == c2.size());
					std::vector<Type> c(s);
					constexpr uint64_t m1 = modular1::mod;
					modint2 m1_inv2 = modint2(m1).Inverse();
					for (int i = 0; i < s; ++i)
					{
						c[i] = Type(c1[i]) + Type((c2[i] - modint2(c1[i])) * m1_inv2) * Type(m1);
					}
					return c;
				}
			}
			else if constexpr (std::is_same_v<typename Modular::Type, uint64_t>)
			{
				// TODO
				assert(false);
				// max element <= 2^63 - 1 < 9.23 * 10^18
				// assume final size <= 2^23 < 8.4 * 10^6
				// max result <= (9.23 * 10^18)^2 * 8.4 * 10^6 < 7.16 * 10^44
				if constexpr (!enable_int128)
				{
					using modint1 = ModInt<algorithm::Modular<uint32_t, 998244353, Modular::safe, 31>>;
					using modint2 = ModInt<algorithm::Modular<uint32_t, 1107296257, Modular::safe, 309>>;
					using modint3 = ModInt<algorithm::Modular<uint32_t, 1224736769, Modular::safe, 149>>;
					using modint4 = ModInt<algorithm::Modular<uint32_t, 1300234241, Modular::safe, 119>>;
					using modint5 = ModInt<algorithm::Modular<uint32_t, 1484783617, Modular::safe, 113>>;
				}
				else
				{
					using modular1 = algorithm::Modular<uint64_t, 999999999817285633, safe_option, 5>;
					using modular2 = algorithm::Modular<uint64_t, 999999999708233729, safe_option, 3>;
					using modular3 = algorithm::Modular<uint64_t, 999999999565627393, safe_option, 5>;
				}
			}
			else
			{
				assert(false);
			}
			*/
		}
		static std::vector<Type> TransposeMultiply(std::vector<Type> a, std::vector<Type> b)
		{
			if (roots.empty()) PrepareRoots();
			int n = a.size(), m = b.size();
			if (n < m) return { 0 };

			if (std::min(n - m + 1, m) <= multiply_n_threshold || std::max(n - m + 1, m) <= multiply_m_threshold)
			{
				std::vector<Type> res(n - m + 1);
				for (int i = 0; i < n - m + 1; ++i)
					for (int j = 0; j < m; ++j)
						res[i] += b[j] * a[i + j];
				return res;
			}

			int size = 1 << (31 - bit_clz(2 * n - 1));
			a.resize(size);
			reverse(b.begin(), b.end());
			b.resize(size);
			Transform(a);
			Transform(b);
			Type inv = Type(size).Inverse();
			for (int i = 0; i < size; ++i) a[i] *= b[i] * inv;
			InvTransform(a);
			return std::vector<Type>(a.begin() + m - 1, a.begin() + n);
		}
	};
}

#endif

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <algorithm>
#include <functional>
#include <utility>
#include <queue>
#include <vector>
#include <initializer_list>

namespace algorithm
{
	template<typename Modular, bool safe_option = Modular::safe>
	class Polynomial
	{
	public:
		using Type = ModInt<Modular>;
		using NTTType = NTT<Modular, safe_option>;
	private:
		std::vector<Type> a;
		static constexpr int divide_n_threshold = 80;
		static constexpr int divide_m_threshold = 32;
		static constexpr int evaluate_n_threshold = 80;
		static constexpr int evaluate_m_threshold = 32;
		explicit Polynomial() : a() { }
	public:
		template<typename T>
		Polynomial(const std::initializer_list<T>& poly) : a(poly.begin(), poly.end()) { assert(!a.empty()); }
		template<typename T>
		Polynomial(const std::vector<T>& poly) : a(poly.begin(), poly.end()) { assert(!a.empty()); }
		Polynomial(const std::vector<Type>& poly) : a(poly.begin(), poly.end()) { assert(!a.empty()); }
		explicit Polynomial(int size) : a(size) { assert(size >= 1); }
		int Size() const { return a.size(); }
		Type& operator [] (int index) { return a[index]; }
		Type operator [] (int index) const { return a[index]; }
		Polynomial& Shrink()
		{
			while (a.back() == 0 && a.size() >= 2) a.pop_back();
			return *this;
		}
		Polynomial& Reduce(int size)
		{
			a.resize(size);
			return *this;
		}
		Polynomial Modulo(int size) const
		{
			return Polynomial(*this).Reduce(size);
		}
		friend Polynomial Reduce(const Polynomial& poly, int size)
		{
			return Polynomial(poly).Reduce(size);
		}
		Polynomial& operator <<= (int shift)
		{
			int size = a.size();
			a.resize(size + shift);
			for (int i = size + shift - 1; i >= shift; --i)
				a[i] = a[i - shift];
			for (int i = 0; i < shift; ++i)
				a[i] = 0;
			return *this;
		}
		Polynomial& operator >>= (int shift)
		{
			int size = a.size();
			if (shift >= size)
				a.clear();
			else
			{
				for (int i = 0; i < size - shift; ++i)
					a[i] = a[i + shift];
				a.resize(size - shift);
			}
			return *this;
		}
		Polynomial operator << (int shift) { return Polynomial(*this) <<= shift; }
		Polynomial operator >> (int shift) { return Polynomial(*this) >>= shift; }
		Polynomial& operator += (const Polynomial& rhs)
		{
			int n = this->a.size(), m = rhs.a.size();
			int s = std::max(n, m);
			this->a.resize(s);
			for (int i = 0; i < m; ++i)
				this->a[i] += rhs.a[i];
			return this->Shrink();
		}
		Polynomial& operator -= (const Polynomial& rhs)
		{
			int n = this->a.size(), m = rhs.a.size();
			int s = std::max(n, m);
			this->a.resize(s);
			for (int i = 0; i < m; ++i)
				this->a[i] -= rhs.a[i];
			return this->Shrink();
		}
		Polynomial& operator *= (const Polynomial& rhs)
		{
			this->a = NTTType::Multiply(this->a, rhs.a);
			return this->Shrink();
		}
		Polynomial& operator += (const Type& rhs)
		{
			a[0] += rhs;
			return *this;
		}
		Polynomial& operator -= (const Type& rhs)
		{
			a[0] -= rhs;
			return *this;
		}
		Polynomial& operator *= (const Type& rhs)
		{
			for (auto& x : a) x *= rhs;
			return this->Shrink();
		}
		template<typename ValueType>
		Polynomial operator + (const ValueType& rhs) const { return Polynomial(*this) += rhs; }
		template<typename ValueType>
		Polynomial operator - (const ValueType& rhs) const { return Polynomial(*this) -= rhs; }
		template<typename ValueType>
		Polynomial operator * (const ValueType& rhs) const { return Polynomial(*this) *= rhs; }
		Polynomial operator - () const
		{
			Polynomial c = *this;
			for (auto& x : c.a) x = -x;
			return c;
		}
		Polynomial Reverse() const
		{
			return Polynomial(std::vector<Type>(a.rbegin(), a.rend())).Shrink();
		}
		template<typename ValueType>
		Polynomial Add(const ValueType& rhs) const { return *this + rhs; }
		template<typename ValueType>
		Polynomial Subtract(const ValueType& rhs) const { return *this - rhs; }
		template<typename ValueType>
		Polynomial Multiply(const ValueType& rhs) const { return *this * rhs; }
		Polynomial Minus() { return -*this; }
		friend Polynomial Add(const Polynomial& lhs, const Polynomial& rhs) { return lhs + rhs; }
		friend Polynomial Subtract(const Polynomial& lhs, const Polynomial& rhs) { return lhs - rhs; }
		friend Polynomial Multiply(const Polynomial& lhs, const Polynomial& rhs) { return lhs * rhs; }
		friend Polynomial Minus(const Polynomial& poly) { return -poly; }
		friend Polynomial MultiplyAll(const std::vector<Polynomial>& polys)
		{
			if (polys.empty()) return { 1 };
			constexpr auto cmp = [](const Polynomial& lhs, const Polynomial& rhs) -> bool
			{
				return lhs.Size() > rhs.Size();
			};
			std::priority_queue<Polynomial, std::vector<Polynomial>, decltype(cmp)> q(cmp, polys);
			while (q.size() > 1)
			{
				Polynomial a = q.top(); q.pop();
				Polynomial b = q.top(); q.pop();
				q.push(a * b);
			}
			return q.top();
		}
		Polynomial Pow(int exp) const
		{
			Polynomial res = { 1 };
			if (exp == 0) return res;
			for (int k = 31 - bit_clz(exp); k >= 0; --k)
			{
				res *= res;
				if (exp >> k & 1) res *= *this;
			}
			return res;
		}
		template<typename ValueType>
		Polynomial& AddReduce(const ValueType& rhs, int size) { return (*this += rhs).Reduce(size); }
		template<typename ValueType>
		Polynomial& SubtractReduce(const ValueType& rhs, int size) { return (*this -= rhs).Reduce(size); }
		template<typename ValueType>
		Polynomial& MultiplyReduce(const ValueType& rhs, int size) { return (*this *= rhs).Reduce(size); }
		template<typename ValueType>
		Polynomial AddMod(const ValueType& rhs, int size) const { return (*this + rhs).Reduce(size); }
		template<typename ValueType>
		Polynomial SubtractMod(const ValueType& rhs, int size) const { return (*this - rhs).Reduce(size); }
		template<typename ValueType>
		Polynomial MultiplyMod(const ValueType& rhs, int size) const { return (*this * rhs).Reduce(size); }
		friend Polynomial AddMod(const Polynomial& lhs, const Polynomial& rhs, int size) { return (lhs + rhs).Reduce(size); }
		friend Polynomial SubtractMod(const Polynomial& lhs, const Polynomial& rhs, int size) { return (lhs - rhs).Reduce(size); }
		friend Polynomial MultiplyMod(const Polynomial& lhs, const Polynomial& rhs, int size) { return (lhs * rhs).Reduce(size); }
		Polynomial InverseMod(int size) const
		{
			if (size == 1)
			{
				assert(a[0] != 0);
				return Polynomial({ a[0].Inverse() });
			}
			int m = (size + 1) >> 1;
			Polynomial half = this->Modulo(m).InverseMod(m);
			return half.MultiplyReduce(-this->MultiplyMod(half, size) + 2, size);
		}
		Polynomial DerivateMod(int size) const
		{
			Polynomial res = Polynomial(std::vector<Type>(size));
			for (int i = 1; i <= size && i < int(a.size()); ++i) res.a[i - 1] = a[i] * i;
			return res;
		}
		Polynomial IntegrateMod(int size) const
		{
			Type::PrepareInverses(size);
			Polynomial res = Polynomial(std::vector<Type>(size));
			for (int i = 0; i < size - 1 && i < int(a.size()); ++i) res.a[i + 1] = a[i] * Type::inv[i + 1];
			return res;
		}
		Polynomial LnMod(int size) const
		{
			assert(a[0] == 1);
			return this->InverseMod(size).MultiplyReduce(this->DerivateMod(size), size).IntegrateMod(size);
		}
		Polynomial ExpMod(int size) const
		{
			if (size == 1)
			{
				assert(a[0] == 0);
				return Polynomial({ 1 });
			}
			int m = (size + 1) >> 1;
			Polynomial half = this->Modulo(m).ExpMod(m);
			return half.MultiplyMod((*this - half.LnMod(size)) += 1, size);
		}
		Polynomial PowMod(Type exp, int size) const
		{
			if (exp == 0) return Polynomial({ 1 }).Reduce(size);
			if (exp == 1) return this->Modulo(size);
			int tail = 0;
			while (tail < int(a.size()) && a[tail] == 0) ++tail;
			if (tail == int(a.size())) return Polynomial({ 0 }).Reduce(size);
			if (tail == 0)
			{
				Type coef = a[0];
				Type inv_coef = coef.Inverse();
				Type coef_exp = coef.Pow(exp.GetValue());
				return this->MultiplyMod(inv_coef, size).LnMod(size).MultiplyMod(exp, size).ExpMod(size).MultiplyMod(coef_exp, size);
			}
			using DType = typename Type::DType;
			if (DType(exp.GetValue()) * tail >= DType(size)) return Polynomial({ 0 }).Reduce(size);
			int shift = exp.GetValue() * tail;
			return Polynomial(std::vector<Type>(a.begin() + tail, a.end() - shift + tail)).PowMod(exp, size - shift) <<= shift;
		}
		Polynomial SqrtMod(int size) const
		{
			Type coef = a[0];
			Type inv_coef = coef.Inverse();
			Type sqrt_coef = Type::QuadraticResidue(a[0]);
			return this->MultiplyMod(inv_coef, size).PowMod((Modular::mod + 1) >> 1, size) *= sqrt_coef;
		}
		Polynomial& operator /= (Polynomial rhs)
		{
			rhs.Shrink();
			assert(rhs.a.back() != 0);
			int n = a.size(), m = rhs.a.size();
			if (n < m)
			{
				a = { 0 };
				return *this;
			}
			if (n <= divide_n_threshold || std::min(m, n - m) <= divide_m_threshold)
			{
				Type coef = rhs.a.back();
				Type inv_coef = coef.Inverse();
				for (auto& x : rhs.a) x *= inv_coef;
				std::vector<Type> c(n - m + 1);
				for (int i = n - m; i >= 0; --i)
				{
					Type cur = a[i + m - 1];
					c[i] = cur * inv_coef;
					for (int j = m - 1; j >= 0; --j) a[i + j] -= rhs.a[j] * cur;
				}
				a = c;
				return *this;
			}
			std::reverse(a.begin(), a.end());
			std::reverse(rhs.a.begin(), rhs.a.end());
			this->Reduce(n - m + 1).MultiplyReduce(rhs.InverseMod(n - m + 1), n - m + 1);
			std::reverse(a.begin(), a.end());
			return *this;
		}
		Polynomial& operator /= (const Type& rhs) { return *this *= rhs.Inverse(); }
		Polynomial operator / (Polynomial rhs) const { return Polynomial(*this) /= rhs; }
		template<typename ValueType>
		Polynomial DivideBy(ValueType rhs) const { return *this / rhs; }
		std::pair<Polynomial, Polynomial> DivMod(Polynomial rhs) const
		{
			rhs.Shrink();
			assert(rhs.a.back() != 0);
			int n = a.size(), m = rhs.a.size();
			if (n < m) return { Polynomial({ 0 }), *this };
			if (n <= divide_n_threshold || std::min(m, n - m) <= divide_m_threshold)
			{
				Type coef = rhs.a.back();
				Type inv_coef = coef.Inverse();
				for (auto& x : rhs.a) x *= inv_coef;
				std::vector<Type> quotient(n - m + 1);
				std::vector<Type> remainder = a;
				for (int i = n - m; i >= 0; --i)
				{
					Type cur = remainder[i + m - 1];
					quotient[i] = cur * inv_coef;
					for (int j = m - 1; j >= 0; --j) remainder[i + j] -= rhs.a[j] * cur;
				}
				return { quotient, Polynomial(remainder).Shrink() };
			}
			Polynomial quotient = *this / rhs;
			return { quotient, *this - quotient * rhs };
		}
		Polynomial& operator %= (Polynomial rhs)
		{
			rhs.Shrink();
			assert(rhs.a.back() != 0);
			int n = a.size(), m = rhs.a.size();
			if (n < m) return *this;
			if (n <= divide_n_threshold || std::min(m, n - m) <= divide_m_threshold)
			{
				Type coef = rhs.a.back();
				Type inv_coef = coef.Inverse();
				for (auto& x : rhs.a) x *= inv_coef;
				for (int i = n - m; i >= 0; --i)
				{
					Type cur = a[i + m - 1];
					for (int j = m - 1; j >= 0; --j) a[i + j] -= rhs.a[j] * cur;
				}
				return this->Shrink();
			}
			return *this -= (*this / rhs) * rhs;
		}
		Polynomial operator % (Polynomial rhs) const { return Polynomial(*this) %= rhs; }
		Polynomial Remainder(Polynomial rhs) const { return *this % rhs; }
		Polynomial Mod(Polynomial rhs) const { return *this % rhs; }
		// x^exp mod *this
		template<typename ExpType>
		Polynomial ModPower(ExpType exp) const
		{
			if (exp < a.size())
			{
				Polynomial res(exp + 1);
				res[exp] = 1;
				return res;
			}
			Polynomial res = ModPower(exp >> 1);
			res *= res;
			if (exp & 1) res <<= 1;
			return res %= *this;
		}
		// Return f(x + delta) given polynomial f(x)
		Polynomial Translate(const Type& delta) const
		{
			int n = Size() - 1;
			if (n <= 0) return *this;
			Polynomial lhs(n + 1), rhs(n + 1);
			for (int i = 0; i <= n; ++i)
			{
				lhs[i] = i == 0 ? 1 : lhs[i - 1] * delta * Type::Inv(i);
				rhs[i] = a[n - i] * Type::Factorial(n - i);
			}
			(lhs *= rhs).Reduce(n + 1);
			Polynomial res(n + 1);
			for (int i = 0; i <= n; ++i)
				res[n - i] = Type::InvFactorial(n - i) * lhs[i];
			return res;
		}
	private:
		Polynomial TransposeMultiply(const Polynomial& rhs) const
		{
			return NTTType::TransposeMultiply(a, rhs.a);
		}
		// A. Bostan, G. Lecerf and E. Schost. Tellegen's principle into practice. In: 
		// Proceedings of the 2003 international symposium on Symbolic and algebraic computation.
		// pp. 37-44. 2003.
		class TellegenTree
		{
		private:
			int n;
			std::vector<Polynomial> tree;
			void Build(int k, int l, int r, const std::vector<Type>& a)
			{
				if (r - l == 1)
				{
					tree[k] = Polynomial({ 1, -a[l] });
					return;
				}
				int m = (l + r) / 2;
				Build(k * 2 + 1, l, m, a);
				Build(k * 2 + 2, m, r, a);
				tree[k] = tree[k * 2 + 1] * tree[k * 2 + 2];
			}
			void SolveEvaluate(int k, int l, int r, Polynomial poly, std::vector<Type>& res)
			{
				if (r - l == 1)
				{
					res[l] = poly[0];
					return;
				}
				int m = (l + r) / 2;
				SolveEvaluate(k * 2 + 1, l, m, poly.TransposeMultiply(tree[k * 2 + 2]), res);
				SolveEvaluate(k * 2 + 2, m, r, poly.TransposeMultiply(tree[k * 2 + 1]), res);
			}
			Polynomial SolveInterpolate(int k, int l, int r, std::vector<Type>& g)
			{
				if (r - l == 1)
					return Polynomial({ g[l] });
				int m = (l + r) / 2;
				return SolveInterpolate(k * 2 + 1, l, m, g) * tree[k * 2 + 2].Reverse() + SolveInterpolate(k * 2 + 2, m, r, g) * tree[k * 2 + 1].Reverse();
			}
		public:
			TellegenTree(const std::vector<Type>& a)
			{
				n = a.size();
				assert(n >= 1);
				int size = 1 << (31 - bit_clz(2 * n - 1));
				tree.resize(size * 2 - 1, Polynomial());
				Build(0, 0, n, a);
			}
			std::vector<Type> Evaluate(Polynomial poly)
			{
				poly.Shrink();
				int size = poly.a.size();
				Polynomial cur = poly.Reduce(size + n).TransposeMultiply(tree[0].InverseMod(size));
				cur.Reduce(n);
				std::vector<Type> res(n);
				SolveEvaluate(0, 0, n, cur, res);
				return res;
			}
			Polynomial Interpolate(const std::vector<Type>& value)
			{
				assert(value.size() == n);
				auto tmp = tree[0].Reverse().DerivateMod(n).Shrink();
				std::vector<Type> g = Evaluate(tree[0].Reverse().DerivateMod(n).Shrink());
				for (int i = 0; i < n; ++i) g[i] = value[i] / g[i];
				return SolveInterpolate(0, 0, n, g);
			}
		};
	public:
		Type Evaluate(const Type& x) const
		{
			Type res = 0;
			int size = a.size();
			for (int i = size - 1; i >= 0; --i) (res *= x) += a[i];
			return res;
		}
		std::vector<Type> Evaluate(const std::vector<Type>& points) const
		{
			int n = points.size();
			assert(n >= 1);
			std::vector<Type> res(n);
			int size = a.size();
			if (std::max(n, size) <= evaluate_n_threshold || std::min(n, size) <= evaluate_m_threshold)
			{
				for (int i = 0; i < n; ++i)
					res[i] = this->Evaluate(points[i]);
				return res;
			}
			TellegenTree tree(points);
			return tree.Evaluate(*this);
		}
		static Polynomial Interpolate(const std::vector<Type>& x, const std::vector<Type>& y)
		{
			assert(x.size() == y.size() && !x.empty());
			if (x.size() == 1) return Polynomial({ y[0] });
			TellegenTree tree(x);
			return tree.Interpolate(y);
		}
		// Given a polynomial f of degree d by f(0), f(1), ..., f(d) and a shift, compute 
		// f(0 + shift), f(1 + shift), ..., f(d + shift).
		// A. Bostan, P. Gaudry, and E. Schost, Linear recurrences with polynomial coefficients 
		// and application to integer factorization and Cartier-Manin operator. SIAM Journal of
		// Computing, 36(6): 1777–1806. 2007.
		static std::vector<Type> ShiftEvaluate(const std::vector<Type>& values, Type shift)
		{
			assert(!values.empty());
			int d = values.size() - 1;
			assert((d + 1) * 2 <= Modular::mod);
			typename Modular::Type shift_v = shift.GetValue();
			if (shift_v <= d) // special case: overlap
			{
				typename Modular::Type new_shift_v = d + 1;
				std::vector<Type> tmp = ShiftEvaluate(values, new_shift_v);
				std::vector<Type> res(d + 1);
				for (int i = 0; i <= d; ++i)
					res[i] = (shift_v + i <= d) ? values[shift_v + i] : tmp[(shift_v + i) - new_shift_v];
				return res;
			}
			if (shift_v >= Modular::mod - d) // special case: overlap
			{
				typename Modular::Type new_shift_v = Modular::mod - d - 1;
				std::vector<Type> tmp = ShiftEvaluate(values, new_shift_v);
				std::vector<Type> res(d + 1);
				for (int i = 0; i <= d; ++i)
					res[i] = (shift_v + i >= Modular::mod) ? values[shift_v + i - Modular::mod] : tmp[(shift_v + i) - new_shift_v];
				return res;
			}
			std::vector<Type> lhs(d + 1), rhs(2 * d + 1);
			Type::PrepareFactorials(d);
			for (int i = 0; i <= d; ++i)
			{
				lhs[i] = values[i] * Type::inv_factorial[i] * Type::inv_factorial[d - i];
				if ((d - i) & 1) lhs[i] = -lhs[i];
			}
			rhs[0] = shift - d;
			for (int i = 1; i <= 2 * d; ++i) rhs[i] = rhs[i - 1] * (shift + i - d);
			Type inv = rhs[2 * d].Inverse();
			for (int i = 2 * d; i >= 1; --i)
			{
				rhs[i] = rhs[i - 1] * inv;
				inv *= shift + i - d;
			}
			rhs[0] = inv;
			std::vector<Type> tmp = NTTType::Multiply(lhs, rhs);
			std::vector<Type> res(tmp.begin() + d, tmp.begin() + 2 * d + 1);
			Type prod = 1;
			for (int i = 0; i <= d; ++i) prod *= shift - i;
			for (int i = 0; i <= d; ++i)
			{
				res[i] *= prod;
				prod *= (shift + i + 1) * rhs[i];
			}
			return res;
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

using modular = algorithm::Modular<uint32_t, 998244353, true, 3>;
//using modular = algorithm::SafeModularInt32<1000000007>;
//using modular = algorithm::SafeUserModularInt32;

using modint = algorithm::ModInt<modular>;
using poly = algorithm::Polynomial<modular>;
//using linear = algorithm::LinearRecurrence<modular>;

using ll = int64_t;
using ld = double;

//int dx[] = { 1, 0, -1, 0 };
//int dy[] = { 0, -1, 0, 1 };

//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 1000000000;

void solve()
{
	int n;
	read(n);
	vector<vector<int>> v(n);
	for (int i = 1; i < n; ++i)
	{
		int x;
		read(x);
		x -= 1;
		v[x].push_back(i);
	}
	vector<int> sz(n);
	vector<ll> f(n);
	function<void(int)> dfs = [&](int x)
	{
		sz[x] = 1;
		for (auto y : v[x])
		{
			dfs(y);
			sz[x] += sz[y];
			f[x] += f[y];
		}
		f[x] += sz[x];
	};
	vector<ll> g(n);
	ll res = 0;
	function<void(int)> dfs2 = [&](int x)
	{
		for (auto y : v[x])
		{
			if (x == 0)
				g[y] = f[0] - f[y] - sz[y];
			else
				g[y] = g[x] + (f[x] - sz[x] - f[y]) + (n - sz[y]);
			dfs2(y);
		}
		vector<int> p;
		ll tmp = n;
		if (x != 0)
		{
			tmp += g[x];
			p.push_back(n - sz[x]);
		}
		for (auto y : v[x])
		{
			tmp += f[y];
			p.push_back(sz[y]);
		}
		sort(p.begin(), p.end());

		int sum = 0;
		for (int i = 0; i < (int)p.size() - 1; ++i)
			sum += p[i];
		if (sum <= p.back())
			tmp += (ll)sum * p.back();
		else
		{
			vector<poly> polys;
			for (int i = 0; i < (int)p.size(); ++i)
			{
				poly h(p[i] + 1);
				h[p[i]] = h[0] = 1;
				polys.push_back(h);
			}
			auto prod = MultiplyAll(polys);
			sum += p.back();

			int c = 0;
			for (int i = 0; i <= sum / 2; ++i)
				if (prod[i] != 0) c = i;
			tmp += (ll)c * (sum - c);
		}
		freshmax(res, tmp);
	};
	dfs(0);
	dfs2(0);
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