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

struct query_t {
	int op, l, r, x;
	query_t(int op = 0, int l = 0, int r = 0, int x = 0): op(op), l(l), r(r), x(x) { }
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, q;
	std::cin >> n >> q;
	vi a(n + 1);
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	vi num(-1 + all(a));
	std::vector<query_t> que(q);
	for (int i = 0; i != q; ++i) {
		int op, l, r, x;
		std::cin >> op;
		if (op == 1) {
			std::cin >> l >> x;
			num.push_back(x);
		}
		else {
			std::cin >> l >> r >> x;
			--l;
		}
		que[i] = {op, l, r, x};
	}
	std::sort(all(num));
	num.resize(std::unique(all(num)) - num.begin());
	for (int i = 1; i <= n; ++i) {
		a[i] = std::lower_bound(all(num), a[i]) - num.begin();
	}
	for (int i = 0; i != q; ++i) {
		if (que[i].op == 1) {
			que[i].x = std::lower_bound(all(num), que[i].x) - num.begin();
		}
	}
	std::mt19937 rng(std::time(nullptr));
	std::vector<int8_t> ans(q, 1);
	for (int t = 0; t != 100; ++t) {
		for (auto& x : num) {
			x = rng() / 4;
		}
		vi b = a;
		vl bit(n + 1);
		for (int j = 1; j <= n; ++j) {
			bit[j] += num[b[j]];
			if (j + lowbit(j) <= n) {
				bit[j + lowbit(j)] += bit[j];
			}
		}
		for (int j = 0; j != q; ++j) {
			if (que[j].op == 1) {
				int x = num[que[j].x] - num[b[que[j].l]];
				b[que[j].l] = que[j].x;
				for (int k = que[j].l; k <= n; k += lowbit(k)) {
					bit[k] += x;
				}
			}
			else {
				i64 x = 0;
				for (int k = que[j].r; k; k ^= lowbit(k)) {
					x += bit[k];
				}
				for (int k = que[j].l; k; k ^= lowbit(k)) {
					x -= bit[k];
				}
				ans[j] &= x % que[j].x == 0;
			}
		}
	}
	for (int i = 0; i != q; ++i) {
		if (que[i].op == 2) {
			std::cout << (ans[i] ? "YES\n" : "NO\n");
		}
	}
	return 0;
}