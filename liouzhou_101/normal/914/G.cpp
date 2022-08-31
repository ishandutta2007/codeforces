#ifndef IO_H_
#define IO_H_

#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdio>
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
		for (x = ch - '0'; read(ch) && isdigit(ch); x = x * 10 + ch - '0');
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
		bool operator == (ModInt rhs) const { return value == rhs.value; }
		bool operator != (ModInt rhs) const { return value != rhs.value; }

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

#ifndef BITTRANSFORM_H_
#define BITTRANSFORM_H_

#include <cassert>
#include <vector>
#include <utility>

namespace algorithm
{
	// OrConvolution, AndConvolution, XorConvolution are based on fast Walsh-Hadamard transform.
	// Zeta transform, Mobius transform and Fast subset convolution are implemented.
	template<typename Type>
	class BitTransform
	{
	public:
		static void OrTransform(std::vector<Type>& a)
		{
			int n = a.size();
			assert((n & -n) == n);
			for (int i = 1; i < n; i <<= 1)
				for (int j = 0, p = i << 1; j < n; j += p)
					for (int k = 0; k < i; ++k)
						a[i + j + k] += a[j + k];
		}
		static void OrInvTransform(std::vector<Type>& a)
		{
			int n = a.size();
			assert((n & -n) == n);
			for (int i = 1; i < n; i <<= 1)
				for (int j = 0, p = i << 1; j < n; j += p)
					for (int k = 0; k < i; ++k)
						a[i + j + k] -= a[j + k];
		}
		static void AndTransform(std::vector<Type>& a)
		{
			int n = a.size();
			assert((n & -n) == n);
			for (int i = 1; i < n; i <<= 1)
				for (int j = 0, p = i << 1; j < n; j += p)
					for (int k = 0; k < i; ++k)
						a[j + k] += a[i + j + k];
		}
		static void AndInvTransform(std::vector<Type>& a)
		{
			int n = a.size();
			assert((n & -n) == n);
			for (int i = 1; i < n; i <<= 1)
				for (int j = 0, p = i << 1; j < n; j += p)
					for (int k = 0; k < i; ++k)
						a[j + k] -= a[i + j + k];
		}
		static void XorTransform(std::vector<Type>& a)
		{
			int n = a.size();
			assert((n & -n) == n);
			for (int i = 1; i < n; i <<= 1)
				for (int j = 0, p = i << 1; j < n; j += p)
					for (int k = 0; k < i; ++k)
					{
						Type x = std::move(a[j + k]), y = std::move(a[i + j + k]);
						a[j + k] = x + y;
						a[i + j + k] = x - y;
					}
		}
		static void XorInvTransform(std::vector<Type>& a)
		{
			XorTransform(a);
			Type inv2 = Type(1) / Type(a.size());
			for (auto& x : a) x *= inv2;
		}
		// Compute c[k] = sum(a[i] * b[j]) for (i or j) = k.
		// Complexity: O(n log n)
		static std::vector<Type> OrConvolution(std::vector<Type> a, std::vector<Type> b)
		{
			int n = a.size();
			assert(n == b.size());
			OrTransform(a);
			OrTransform(b);
			for (int i = 0; i < n; ++i) a[i] *= b[i];
			OrInvTransform(a);
			return a;
		}
		// Compute c[k] = sum(a[i] * b[j]) for (i and j) = k.
		// Complexity: O(n log n)
		static std::vector<Type> AndConvolution(std::vector<Type> a, std::vector<Type> b)
		{
			int n = a.size();
			assert(n == b.size());
			AndTransform(a);
			AndTransform(b);
			for (int i = 0; i < n; ++i) a[i] *= b[i];
			AndInvTransform(a);
			return a;
		}
		// Compute c[k] = sum(a[i] * b[j]) for (i xor j) = k.
		// Complexity: O(n log n)
		// TODO: k-ary XOR Convolution
		static std::vector<Type> XorConvolution(std::vector<Type> a, std::vector<Type> b)
		{
			int n = a.size();
			assert(n == b.size());
			XorTransform(a);
			XorTransform(b);
			for (int i = 0; i < n; ++i) a[i] *= b[i];
			XorInvTransform(a);
			return a;
		}
		// Transform a[] to b[k] = sum(a[i]) for i is a subset of k.
		// Complexity: O(n log n)
		static void ZetaTransform(std::vector<Type>& a)
		{
			int n = a.size();
			assert((n & -n) == n);
			int k = bit_lg(n);
			for (int i = 0; i < k; ++i)
			{
				int s = (n - 1) ^ (1 << i);
				for (int t = s; t; t = (t - 1) & s)
					a[t | 1 << i] += a[t];
				a[1 << i] += a[0];
			}
		}
		// Transform a[] to b[k] = sum( (-1)^(|k \ i|) a[i]) for i is a subset of k, 
		// and k \ i denotes set minus, |s| denotes the size of the set.
		// Note that MobiusTransform is the inverse of ZetaTransform.
		// Complexity: O(n log n)
		static void MobiusTransform(std::vector<Type>& a)
		{
			int n = a.size();
			assert((n & -n) == n);
			int k = bit_lg(n);
			for (int i = 0; i < k; ++i)
			{
				int s = (n - 1) ^ (1 << i);
				for (int t = s; t; t = (t - 1) & s)
					a[t | 1 << i] -= a[t];
				a[1 << i] -= a[0];
			}
		}
		// Compute c[k] = sum(a[i] * b[k \ i]) for i is a subset of k.
		// Naive solution to this problem is typically O(3^n).
		// The implementation is based on the following reference. 
		// [BHKK07] A. Bjorklund, T. Husfeldt, P. Kaski and M. Koivisto. Fourier meets mobius: fast 
		// subset convolution. In: Proceedings of the 39th Annual ACM Symposium on Theory of Computing, 
		// pp. 67-74. 2007.
		// A tutorial: https://codeforces.com/blog/entry/72488.
		// 
		// The approach:
		// Let a{i}[s] = a[s] if |s| = i else 0, and define
		//     g[k][s] = sum( Zeta(a{i})[s] * Zeta(b{k-i})[s] ) for 0 <= i <= k.
		// Then c[s] = Mobius(g[|s|])[s].
		// 
		// An alternative approach is to note that
		//     c[k] = sum(a[i] * b[j]) for (i or j = k) and (i and j = 0).
		// Solve c[k][r] = sum( a{i}[s] * b{j}[t] ) for (i + j = k) and (s or t = r).
		// Then c[s] = c[|s|][s], and the above convolution is actually OrTransformation.
		// See https://www.luogu.com.cn/problem/P6097.
		// 
		// Both approaches have complexity: O(n (log n)^2), but the former is more efficient.
		static std::vector<Type> SubsetConvolution(std::vector<Type> a, std::vector<Type> b)
		{
			int n = a.size();
			assert(n == b.size());
			int k = bit_lg(n);
			std::vector<std::vector<Type>> f(k + 1, std::vector<Type>(n)), g = f, h = f;
			for (int s = 0; s < n; ++s)
			{
				f[bit_popcount(s)][s] = a[s];
				g[bit_popcount(s)][s] = b[s];
			}
			for (int i = 0; i <= k; ++i)
			{
				ZetaTransform(f[i]);
				ZetaTransform(g[i]);
			}
			for (int i = 0; i <= k; ++i)
			{
				for (int j = 0; j <= i; ++j)
					for (int s = 0; s < n; ++s)
						h[i][s] += f[j][s] * g[i - j][s];
				MobiusTransform(h[i]);
			}
			std::vector<Type> c(n);
			for (int s = 0; s < n; ++s)
				c[s] = h[bit_popcount(s)][s];
			return c;
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
bool freshmin(T& a, const T& b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}

template<class T>
bool freshmax(T& a, const T& b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}

using modular = SafeModularInt32<1000000007>;
using modint = ModInt<modular>;

void solve()
{
	int k = 17;
	int n = 1 << k;
	vector<modint> f(n);
	f[1] = 1;
	for (int i = 2; i < n; ++i)
		f[i] = f[i - 1] + f[i - 2];
	int m;
	read(m);
	vector<modint> a(n);
	for (int i = 0; i < m; ++i)
	{
		int x;
		read(x);
		a[x] += 1;
	}
	auto sde = BitTransform<modint>::XorConvolution(a, a);
	auto sc = a;
	auto sab = BitTransform<modint>::SubsetConvolution(a, a);
	for (int i = 0; i < n; ++i)
	{
		sde[i] *= f[i];
		sc[i] *= f[i];
		sab[i] *= f[i];
	}
	auto b = BitTransform<modint>::AndConvolution(BitTransform<modint>::AndConvolution(sab, sc), sde);
	modint res = 0;
	for (int i = 0; i < k; ++i)
		res += b[1 << i];
	writeln(res.GetValue());
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("try.in", "r", stdin);
#endif
	//int tests = next<int>();
	int tests = 1;
	while (tests--) solve();
	return 0;
}