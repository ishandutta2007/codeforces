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

typedef long long i64;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef std::vector<int> vi;
typedef std::vector<i64> vl;
typedef std::vector<u32> vu;
typedef std::vector<u64> vul;
typedef std::pair<int, int> pii;
typedef std::pair<u32, u32> puu;
typedef std::vector<vi> vvi;
typedef std::vector<vu> vvu;

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

final int maxh = 61;

// f[h][x<m][p(x)][p(x+y)][(x+y)>>h] = cnt
i64 f[maxh + 1][2][2][2][2];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int T;
	std::cin >> T;
	for (int cas = 1; cas <= T; ++cas) {
		i64 n, m;
		std::cin >> n >> m;
		set_all(f, 0);
		f[0][0][0][0][0] = 1;
		for (int h = 0; h != maxh; ++h) {
			int x = m >> h & 1, y = n >> h & 1;
			for (int i = 0; i != 2; ++i) {
				for (int j = 0; j != 2; ++j) {
					for (int k = 0; k != 2; ++k) {
						for (int l = 0; l != 2; ++l) {
							for (int u = 0; u != 2; ++u) {
								int ni = u < x || (u == x && i);
								int nj = j ^ u;
								int nk = k ^ l ^ u ^ y;
								int nl = (l + u + y) >> 1;
								f[h + 1][ni][nj][nk][nl] += f[h][i][j][k][l];
							}
						}
					}
				}
			}
		}
		std::cout << f[maxh][1][0][1][0] + f[maxh][1][1][0][0] << '\n';
	}
	return 0;
}