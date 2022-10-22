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

final int maxn = 505;

int e[maxn][maxn], d[maxn][maxn];

// i64 ans[maxn][maxn];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int T;
	std::cin >> T;
	for (int cas = 1; cas <= T; ++cas) {
		int n, m;
		std::cin >> n >> m;
		set_all(e, 0x3f);
		for (int i = 0; i != m; ++i) {
			int u, v, w;
			std::cin >> u >> v >> w;
			Min(e[u][v], w);
			Min(e[v][u], w);
		}
		set_all(d, 0x3f);
		for (int i = 1; i <= n; ++i) {
			d[i][i] = 0;
			for (int j = 1; j != i; ++j) {
				if (e[i][j] != e[0][0]) {
					d[i][j] = d[j][i] = 1;
				}
			}
		}
		for (int k = 1; k <= n; ++k) {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					Min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
		i64 ans = 1ll << 60;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (e[i][j] != e[0][0]) {
					Min(ans, (d[1][i] + d[n][j] + 1ll) * e[i][j]);
					for (int k = 1; k <= n; ++k) {
						if (d[1][k] + d[k][n] == d[1][n]) {
							Min(ans, (d[1][n] + d[i][k] + 2ll) * e[i][j]);
						}
					}
				}
			}
		}
		std::cout << ans << '\n';
		// set_all(ans, 0x3f);
		// for (int i = 1; i <= n; ++i) {
		// 	ans[i][i] = 0;
		// 	for (int j = 1; j <= n; ++j) {
		// 		for (int k = 1; k <= n; ++k) {
		// 			if (e[i][k] != e[0][0] && d[k][j] != d[0][0]) {
		// 				Min(ans[i][j], (d[k][j] + 1ll) * e[i][k]);
		// 			}
		// 		}
		// 	}
		// }
		// for (int k = 1; k <= n; ++k) {
		// 	for (int i = 1; i <= n; ++i) {
		// 		for (int j = 1; j <= n; ++j) {
		// 			Min(ans[i][j], ans[i][k] + ans[k][j]);
		// 		}
		// 	}
		// }
		// std::cout << ans[1][n] << '\n';
	}
	return 0;
}