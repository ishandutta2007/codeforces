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

bool ask(const vi& a) {
	std::cout << "? " << a.size();
	for (const auto& x : a) {
		std::cout << ' ' << x;
	}
	std::cout << std::endl;
	char s[5];
	std::cin >> s;
	return s[0] == 'Y';
}

bool guess(int x) {
	std::cout << "! " << x << std::endl;
	char s[5];
	std::cin >> s;
	return s[1] == ')';
}

void brute(int x) {
	assert(guess(x));
}

void brute(int x, int y) {
	if (!guess(x)) {
		assert(guess(y));
	}
}

void brute(int x, int y, int z) {
	if (ask({x})) {
		if (ask({y})) {
			brute(x, y);
		}
		else {
			brute(x, z);
		}
	}
	else {
		if (ask({x})) {
			if (ask({y})) {
				brute(x, y);
			}
			else {
				brute(x, z);
			}
		}
		else {
			brute(y, z);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	vi wait(n);
	std::iota(all(wait), 1);
	while (static_cast<int>(wait.size()) > 3) {
		int n = wait.size();
		int b = n / 2;
		int a = b / 2, c = b + (n - b) / 2;
		bool u = ask(vi(wait.begin(), wait.begin() + b));
		bool v = ask(vi(wait.begin() + a, wait.begin() + c));
		vi nxt;
		if (u && v) {
			nxt = vi(wait.begin(), wait.begin() + c);
		}
		if (u && !v) {
			nxt = vi(wait.begin(), wait.begin() + b);
			for (auto it = wait.begin() + c; it != wait.end(); ++it) {
				nxt.push_back(*it);
			}
		}
		if (!u && v) {
			nxt = vi(wait.begin() + a, wait.end());
		}
		if (!u && !v) {
			nxt = vi(wait.begin() + b, wait.end());
			for (int i = 0; i != a; ++i) {
				nxt.push_back(wait[i]);
			}
		}
		std::swap(wait, nxt);
	}
	n = wait.size();
	if (n == 1) {
		brute(wait[0]);
	}
	if (n == 2) {
		brute(wait[0], wait[1]);
	}
	if (n == 3) {
		brute(wait[0], wait[1], wait[2]);
	}
	return 0;
}