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
#define debug(...) std::cerr << "["#__VA_ARGS__"] :", dbg(__VA_ARGS__)
#else
#define debug(...) 0
#endif

typedef unsigned int u32;
typedef unsigned long long u64;
typedef long long i64;
typedef std::pair<u32, u32> puu;
typedef std::vector<u32> vu;

#define lowbit(x)	((x) & -(x))
#define all(x)		x.begin(), x.end()
#define set_all(x, y)	std::memset(x, y, sizeof (x))
#define set_n(x, y, n)	std::memset(x, y, sizeof (decltype(*(x))) * (n))

#define pcount		__builtin_popcount
#define lcount		__builtin_clz
#define tcount		__builtin_ctz

tempt T& Min(T& x, const T& y) { return x = std::min<T>(x, y); }
tempt T& Max(T& x, const T& y) { return x = std::max<T>(x, y); }

final u32 maxn = 200005u;

u32 fib[40];

vu adj[maxn];

u32 ban[maxn], s[maxn], fa[maxn];

vu vert;
u32 dfs(u32 u, u32 p) {
	vert.push_back(u);
	s[u] = 1;
	fa[u] = p;
	for (const auto& v : adj[u]) if (v != p && !ban[v]) s[u] += dfs(v, u);
	return s[u];
}

bool check(u32 r, u32 k) {
	if (k <= 2u) return true;
	vert.resize(0);
	dfs(r, r);
	u32 x = 0;
	for (const auto& u : vert) {
		if (s[u] == fib[k - 1] || s[u] == fib[k - 2]) {
			x = u;
			break;
		}
	}
	if (!x) return false;
	u32 y = fa[x];
	if (s[x] == fib[k - 1]) {
		ban[y] = 1;
		if (!check(x, k - 1)) return false;
		ban[y] = 0;
		ban[x] = 1;
		if (!check(r, k - 2)) return false;
		ban[x] = 0;
	}
	else {
		ban[y] = 1;
		if (!check(x, k - 2)) return false;
		ban[y] = 0;
		ban[x] = 1;
		if (!check(r, k - 1)) return false;
		ban[x] = 0;
	}
	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	fib[1] = 1;
	fib[2] = 2;
	for (u32 i = 3; i != 40u; ++i) fib[i] = fib[i - 1] + fib[i - 2];
	u32 n;
	std::cin >> n;
	for (u32 i = 1, u, v; i != n; ++i) {
		std::cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	u32 k = std::lower_bound(fib, fib + 40, n) - fib;
	if (fib[k] != n) {
		std::cout << "NO" << std::endl;
		return 0;
	}
	std::cout << (check(1, k) ? "YES\n" : "NO\n") << std::endl;
	return 0;
}