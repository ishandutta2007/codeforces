#include <bits/stdc++.h>

#define ff	first
#define ss	second

#define templ	template <
#define tempr	>
#define typet	typename T
#define typeu	typename U
#define types	typename... Ts
#define tempt	templ typet tempr
#define tempu	templ typeu tempr
#define final	constexpr const

tempt struct range {
	T b, e;
	range(T _b, T _e): b(_b), e(_e) { }
	T begin() const { return b; }
	T end() const { return e; }
};
tempt range<T> make_range(T b, T e) { return range<T>(b, e); }

tempt struct is_cont {
	static final bool value = false;
};
tempt struct is_cont<range<T>> {
	static final bool value = true;
};
templ types tempr struct is_cont<std::vector<Ts...>> {
	static final bool value = true;
};

templ typet , typeu tempr std::ostream&
operator<<(std::ostream& os, const std::pair<T, U>& p) {
	return os << '<' << p.ff << ',' << p.ss << '>';
}

tempt std::enable_if_t<is_cont<T>::value, std::ostream>&
operator<<(std::ostream& os, const T& c) {
	if (c.begin() == c.end()) return os << "{}";
	auto iter = c.begin();
	os << '{' << *iter;
	while (++iter != c.end()) os << ',' << *iter;
	return os << '}';
}

void dbg() { std::cerr << std::endl; }
templ typet , types tempr void
dbg(T arg, Ts... args) { std::cerr << ' ' << arg; dbg(args...); }

#ifdef LOCAL
#define debug(...) std::cerr << "[ "#__VA_ARGS__" ] :", dbg(__VA_ARGS__)
#else
#define debug(...) 0
#endif

typedef unsigned int u32;
typedef unsigned long long u64;
typedef long long i64;
typedef std::pair<u32, u32> puu;
typedef std::vector<u32> vu;
typedef std::vector<u64> vul;
typedef std::vector<int> vi;
typedef std::vector<i64> vl;
typedef std::vector<vu> vvu;

template<typename T>
using heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define lowbit(x)	((x) & -(x))
#define all(x)		x.begin(), x.end()
#define set_all(x, y)	std::memset(x, y, sizeof (x))
#define set_n(x, y, n)	std::memset(x, y, sizeof (decltype(*(x))) * (n))

#define md		((l + r) >> 1u)
#define ls		(i << 1u)
#define rs		(ls ^ 1u)
#define ll		l, md, ls
#define rr		md, r, rs

#define pcount		__builtin_popcount
#define pcount64	__builtin_popcountll
#define lcount		__builtin_clz
#define lcount64	__builtin_clzll
#define tcount		__builtin_ctz
#define tcount64	__builtin_ctzll

tempt T& Min(T& x, const T& y) { return x = std::min<T>(x, y); }
tempt T& Max(T& x, const T& y) { return x = std::max<T>(x, y); }

final u32 mod = 1000000007u;
u32 add(u32 x, u32 y) { return x + y < mod ? x + y : x + y - mod; }
u32 sub(u32 x, u32 y) { return x < y ? mod + x - y : x - y; }
u32 mul(u32 x, u32 y) { return (u64)x * y % mod; }
u32 fpow(u32 x, u32 y) {
	u32 z = 1;
	while (y) {
		if (y & 1) z = mul(z, x);
		x = mul(x, x);
		y >>= 1;
	}
	return z;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	u32 n;
	std::cin >> n;
	vu a(n + 2);
	a[0] = a[n + 1] = -1;
	auto at = [&] (u32 i) -> u32 {
		if (!a[i]) {
			std::cout << "? " << i << std::endl;
			std::cin >> a[i];
		}
		return a[i];
	};
	u32 l = 0, r = n + 1;
	while (true) {
		u32 m = (l + r) >> 1u;
		if (at(m) < at(m - 1) && at(m) < at(m + 1)) {
			std::cout << "! " << m << std::endl;
			return 0;
		}
		(at(m) > at(m - 1) ? r : l) = m;
	}
	return 0;
}