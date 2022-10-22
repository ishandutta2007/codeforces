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

tempt struct bit_t {
	std::vector<T> a, b;
	int n;
	bit_t() = default;
	void init(int _n) {
		n = _n; a.resize(n); b.resize(n);
		set_n(&a[0], 0, n);
		set_n(&b[0], 0, n);
	}
	void add(int p, T x) {
		T y = x * p;
		for (int i = p; i < n; i += lowbit(i)) {
			a[i] += x; b[i] += y;
		}
	} // [p, n) += x
	T sum(int p) const {
		T s = 0;
		for (int i = p++; i; i ^= lowbit(i)) s += a[i] * p - b[i];
		return s;
	} // sum(0, p]
	void add(int l, int r, T x) {
		add(l, x);
		add(r + 1, -x);
	}
	T sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
};

final int maxn = 200005;

int have[maxn];

std::mt19937 rng;
struct treap_t {
	int ls, rs, w, s, v;
	i64 sum, tag;
	treap_t() = default;
	treap_t(int v, i64 sum): ls(0), rs(0), w(rng()), s(1), v(v), sum(sum), tag(0) { }
};
treap_t node[maxn * 2];
int node_cnt;
int new_node(int v, i64 x) { node[++node_cnt] = treap_t(v, x); return node_cnt; }

#define L(t)	node[t].ls
#define R(t)	node[t].rs
#define W(t)	node[t].w
#define S(t)	node[t].s
#define V(t)	node[t].v
#define Sum(t)	node[t].sum
#define Tag(t)	node[t].tag

inline i64 value(int t) {
	return Sum(t) + Tag(t) * S(t);
}

inline void push(int t) {
	S(t) -= S(L(t)) + S(R(t));
	Sum(t) -= value(L(t)) + value(R(t));
	Sum(t) += Tag(t) * S(t);
	Tag(L(t)) += Tag(t);
	Tag(R(t)) += Tag(t);
	Tag(t) = 0;
}

inline void pull(int t) {
	S(t) += S(L(t)) + S(R(t));
	Sum(t) += value(L(t)) + value(R(t));
}

void split_by_key(int t, int& l, int& r, int v) {
	if (!t) { l = r = 0; return; }
	push(t);
	if (V(t) < v) {
		l = t;
		split_by_key(R(l), R(l), r, v);
	}
	else {
		r = t;
		split_by_key(L(r), l, L(r), v);
	}
	pull(t);
} /// < >=

int merge(int l, int r) {
	if (!l | !r) return l ^ r;
	if (W(l) < W(r)) {
		push(l);
		R(l) = merge(R(l), r);
	}
	else {
		push(r);
		L(r) = merge(l, L(r));
		l = r;
	}
	pull(l);
	return l;
}

void modify(int& t, int l, int r, int x) {
	int tl = 0, tr = 0;
	split_by_key(t, tl, t, l);
	split_by_key(t, t, tr, r + 1);
	Tag(t) += x;
	t = merge(merge(tl, t), tr);
}

std::pair<i64, int> query(int& t, int l, int r) {
	int tl = 0, tr = 0;
	split_by_key(t, tl, t, l);
	split_by_key(t, t, tr, r + 1);
	std::pair<i64, int> ret(value(t), S(t));
	t = merge(merge(tl, t), tr);
	return ret;
}

void erase(int& t, int v) {
	int tl = 0, tr = 0;
	split_by_key(t, tl, t, v);
	split_by_key(t, t, tr, v + 1);
	t = merge(tl, tr);
}

void insert(int& t, int v, int x) {
	int tl = 0, tr = 0;
	split_by_key(t, tl, t, v);
	split_by_key(t, t, tr, v + 1);
	t = merge(merge(tl, new_node(v, x)), tr);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	rng.seed(std::time(nullptr));
	int q, d;
	std::cin >> q >> d;
	int u = 0, v = 0;
	i64 ans = 0;
	for (int i = 0; i != q; ++i) {
		int a;
		std::cin >> a;
		if (have[a]) {
			erase(u, a);
			erase(v, a);
			modify(u, a + 1, a + d, -1);
			modify(v, a - d, a - 1, -1);
		}
		auto [ud, ri] = query(u, a + 1, a + d);
		auto [vd, le] = query(v, a - d, a - 1);
		i64 dif = (ud + vd + le * (le - 1ll) / 2 + ri * (ri - 1ll) / 2) / 2;
		have[a] ^= 1;
		if (have[a]) {
			modify(u, a + 1, a + d, 1);
			modify(v, a - d, a - 1, 1);
			insert(u, a, le);
			insert(v, a, ri);
		}
		have[a] ? ans += dif : ans -= dif;
		std::cout << ans << '\n';
	}
	return 0;
}