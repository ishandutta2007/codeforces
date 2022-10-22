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

final int maxn = 100005;

int dsu[maxn];
int find(int u) { return u == dsu[u] ? u : dsu[u] = find(dsu[u]); }
bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) {
		return false;
	}
	dsu[u] = v;
	return true;
}

vi adj[maxn];
int pa[maxn][17], dep[maxn], dfl[maxn], dfr[maxn], tim;

void dfs(int u, int p) {
	dfl[u] = ++tim;
	pa[u][0] = p;
	dep[u] = dep[p] + 1;
	for (int i = 0; i != 16; ++i) {
		pa[u][i + 1] = pa[pa[u][i]][i];
	}
	for (const auto& v : adj[u]) {
		if (v == p) {
			continue;
		}
		dfs(v, u);
	}
	dfr[u] = tim;
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) std::swap(u, v);
	for (int i = 16; ~i; --i) if (dep[pa[u][i]] >= dep[v]) u = pa[u][i];
	if (u == v) return u;
	for (int i = 16; ~i; --i) if (pa[u][i] != pa[v][i]) {
		u = pa[u][i];
		v = pa[v][i];
	}
	return pa[u][0];
}

int ancestor(int u, int k) {
	for (int i = 0; i != 17; ++i) {
		if (k >> i & 1) {
			u = pa[u][i];
		}
	}
	return u;
}

int a[maxn];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::iota(dsu, dsu + maxn, 0);
	int n, m;
	std::cin >> n >> m;
	std::vector<pii> ban;
	for (int i = 0; i != m; ++i) {
		int u, v;
		std::cin >> u >> v;
		if (merge(u, v)) {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		else {
			ban.emplace_back(u, v);
		}
	}
	dfs(1, 1);
	for (const auto& [u, v] : ban) {
		assert(u != v && pa[u][0] != v && pa[v][0] != u);
		int f = lca(u, v);
		if (f == u) {
			f = ancestor(v, dep[v] - dep[f] - 1);
			// assert(f != u && pa[u][0] == u);
			++a[1];
			--a[dfl[f]];
			++a[dfr[f] + 1];
			++a[dfl[v]];
			--a[dfr[v] + 1];
		}
		else if (f == v) {
			f = ancestor(u, dep[u] - dep[f] - 1);
			// assert(f != v && pa[v][0] == v);
			++a[1];
			--a[dfl[f]];
			++a[dfr[f] + 1];
			++a[dfl[u]];
			--a[dfr[u] + 1];
		}
		else {
			++a[dfl[u]];
			--a[dfr[u] + 1];
			++a[dfl[v]];
			--a[dfr[v] + 1];
		}
	}
	for (int i = 1; i <= n; ++i) {
		a[i] += a[i - 1];
	}
	m = ban.size();
	for (int i = 1; i <= n; ++i) {
		std::cout << (a[dfl[i]] == m);
	}
	std::cout << std::endl;
	return 0;
}