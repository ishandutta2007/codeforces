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

final int maxn = 105;

int dsu[maxn];
int find(int u) { return u == dsu[u] ? u : dsu[u] = find(dsu[u]); }
bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;
	dsu[u] = v;
	return true;
}

int same[maxn][maxn][maxn], n;
char s[maxn];

int vis[maxn];
std::vector<pii> edge;
void dfs(int u, int p) {
	if (vis[u]) {
		return;
	}
	vis[u] = 1;
	edge.emplace_back(p, u);
	for (int v = 1; v <= n; ++v) {
		if (same[p][v][u]) {
			dfs(v, u);
		}
	}
}

int dis[maxn][maxn];
bool check(int t) {
	std::fill_n(vis + 1, n, 0);
	edge.resize(0);
	dfs(1, t);
	dfs(t, 1);
	if (static_cast<int>(edge.size()) != n) {
		return false;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dis[i][j] = i == j ? 0 : maxn;
		}
	}
	std::iota(dsu + 1, dsu + n + 1, 1);
	for (int i = 1; i != n; ++i) {
		int x = edge[i].ff, y = edge[i].ss;
		if (!merge(x, y)) {
			return false;
		}
		dis[x][y] = dis[y][x] = 1;
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				Min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				if ((dis[i][k] == dis[j][k]) != same[i][j][k]) {
					return false;
				}
			}
		}
	}
	std::cout << "Yes\n";
	for (int i = 1; i != n; ++i) {
		std::cout << edge[i].ff << ' ' << edge[i].ss << '\n';
	}
	return true;
}

void solve() {
	for (int i = 2; i <= n; ++i) {
		if (check(i)) {
			return;
		}
	}
	std::cout << "No\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int T;
	std::cin >> T;
	for (int cas = 1; cas <= T; ++cas) {
		std::cin >> n;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				for (int k = 1; k <= n; ++k) {
					same[i][j][k] = 0;
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				std::cin >> &s[1];
				for (int k = 1; k <= n; ++k) {
					if (s[k] == '1') {
						same[i][j][k] = same[j][i][k] = 1;
					}
				}
			}
		}
		solve();
	}
	return 0;
}