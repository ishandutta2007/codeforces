#include <bits/stdc++.h>

#define ff	first
#define ss	second

#define typet	typename T
#define typeu	typename U
#define types	typename... Ts
#define tempt	template < typet >
#define tempu	template < typeu >
#define temps	template < types >
#define final	constexpr const

tempt struct range {
	T b, e;
	range(T b, T e): b(b), e(e) { }
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
temps struct is_cont<std::vector<Ts...>> {
	static final bool value = true;
};
temps struct is_cont<std::set<Ts...>> {
	static final bool value = true;
};
temps struct is_cont<std::map<Ts...>> {
	static final bool value = true;
};

template < typet , typeu > std::ostream&
operator<<(std::ostream& os, const std::pair<T, U>& p) {
	return os << '<' << p.ff << ',' << p.ss << '>';
}

tempt std::enable_if_t<is_cont<T>::value, std::ostream>&
operator<<(std::ostream& os, const T& c) {
	auto it = c.begin();
	if (it == c.end()) return os << "{}";
	for (os << '{' << *it; ++it != c.end(); os << ',' << *it);
	return os << '}';
}

void dbg() { std::cerr << std::endl; }
template < typet , types > void dbg(T arg, Ts... args) {
	std::cerr << ' ' << arg; dbg(args...);
}

#ifdef LOCAL
#define debug(arg...) do { std::cerr << "["#arg"] :"; dbg(arg); } while (false)
#else
#define debug(...) do { } while (false)
#endif // LOCAL

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using vi = std::vector<int>;
using vl = std::vector<i64>;
using vu = std::vector<u32>;
using vul = std::vector<u64>;
using pii = std::pair<int, int>;
using puu = std::pair<u32, u32>;
using vvi = std::vector<vi>;
using vvu = std::vector<vu>;

#define lowbit(x)	((x) & -(x))
#define all(x)		x.begin(), x.end()
#define set_all(x, y)	std::memset(x, y, sizeof(x))
#define set_n(x, y, n)	std::memset(x, y, sizeof(decltype(*(x))) * (n))

#define pcount		__builtin_popcount
#define lcount		__builtin_clz
#define tcount		__builtin_ctz
#define pcount64	__builtin_popcountll
#define lcount64	__builtin_clzll
#define tcount64	__builtin_ctzll

tempt void Min(T& x, const T& y) { if (x > y) x = y; }
tempt void Max(T& x, const T& y) { if (x < y) x = y; }

final int mod = 1000000007;
inline int add(int x, int y) { return x + y < mod ? x + y : x + y - mod; }
inline int sub(int x, int y) { return x < y ? mod + x - y : x - y; }
inline int mul(i64 x, int y) { return x * y % mod; }
inline void Add(int& x, int y) { x = add(x, y); }
inline void Sub(int& x, int y) { x = sub(x, y); }
inline void Mul(int& x, int y) { x = mul(x, y); }
int pow(int x, int y) {
	int z = 1;
	for (; y; y /= 2) {
		if (y & 1) Mul(z, x);
		Mul(x, x);
	}
	return z;
}

tempt using heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

final int maxn = 1000005;

int p2[maxn], f[maxn], sf[maxn];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	p2[0] = 1;
	for (int i = 1; i != maxn; ++i) {
		p2[i] = mul(p2[i - 1], 2);
	}
	int T;
	std::cin >> T;
	for (int cas = 1; cas <= T; ++cas) {
		int n;
		std::cin >> n;
		if (n == 1) {
			std::cout << "1\n";
			continue;
		}
		f[n] = 1;
		sf[n] = 1;
		sf[n + 1] = 0;
		for (int i = n - 1; i; --i) {
			f[i] = sub(sf[i + 1], sf[std::min(i * 2 - 1, n) + 1]);
			sf[i] = add(f[i], sf[i + 1]);
			// debug(i, f[i]);
		}
		std::cout << "0\n";
		int las = 1, x = pow(p2[n], mod - 2);
		for (int i = 2; i != n; ++i) {
			int ans = mul(f[i], p2[i / 2 + 1]);
			Mul(ans, x);
			std::cout << ans << '\n';
			Sub(las, ans);
		}
		std::cout << las << '\n';
	}
	return 0;
}