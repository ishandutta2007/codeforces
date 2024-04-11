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

int query(vu l, vu r) {
	std::cerr << "query : ";
	std::cout << "? " << l.size() << ' ' << r.size() << std::endl;
	for (u32 i = 0; i != l.size(); ++i) {
		if (i) std::cout << ' ';
		std::cout << l[i];
	}
	std::cout << std::endl;
	for (u32 i = 0; i != r.size(); ++i) {
		if (i) std::cout << ' ';
		std::cout << r[i];
	}
	std::cout << std::endl;
	int x;
	std::cerr << "give : ";
	std::cin >> x;
	return x;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	u32 T;
	std::cin >> T;
	while (T--) {
		u32 n;
		std::cin >> n;
		vu a(1, 1);
		u32 p;
		for (p = 2; !query(a, vu(1, p)); ++p) {
			a.push_back(p);
		}
		vu ans;
		for (u32 i = p + 1; i <= n; ++i) {
			if (!query(a, vu(1, i))) {
				ans.push_back(i);
			}
		}
		u32 l = 1, r = p;
		while (l + 1u != r) {
			u32 m = (l + r) >> 1;
			vu b;
			for (u32 i = l; i != m; ++i) {
				b.push_back(i);
			}
			(query(b, vu(1, p)) ? r : l) = m;
		}
		for (u32 i = 1; i != p; ++i) if (i != l) ans.push_back(i);
		std::cout << "! " << ans.size();
		for (const auto& x : ans) {
			std::cout << ' ' << x;
		}
		std::cout << std::endl;
	}
	return 0;
}