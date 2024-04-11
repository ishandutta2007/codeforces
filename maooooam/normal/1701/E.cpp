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

final int maxn = 5005;

char s[maxn], t[maxn];
short A[maxn][maxn], fA[maxn][maxn], B[maxn][maxn], fB[maxn][maxn], le[maxn][26], ri[maxn][26];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int T;
	std::cin >> T;
	for (int cas = 1; cas <= T; ++cas) {
		int n, m;
		std::cin >> n >> m >> &s[1] >> &t[1];
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j != 26; ++j) {
				le[i][j] = le[i - 1][j];
			}
			le[i][s[i] - 'a'] = i;
		}
		for (int j = 0; j != 26; ++j) {
			ri[n + 1][j] = n + 1;
		}
		for (int i = n; i; --i) {
			for (int j = 0; j != 26; ++j) {
				ri[i][j] = ri[i + 1][j];
			}
			ri[i][s[i] - 'a'] = i;
		}
		for (int i = 0; i <= m + 1; ++i) {
			for (int j = 0; j <= n + 1; ++j) {
				A[i][j] = B[i][j] = -1;
			}
		}
		A[0][0] = 0;
		fA[0][0] = 0;
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (t[i] != s[j]) {
					continue;
				}
				int k = i == 1 ? 0 : le[j - 1][t[i - 1] - 'a'];
				if (A[i - 1][k] == -1) {
					continue;
				}
				A[i][j] = A[i - 1][k];
				fA[i][j] = fA[i - 1][k];
				if (j - 1 != k) {
					A[i][j] += j * 2 - 2 - k - fA[i][j];
					fA[i][j] = j - 1;
				}
			}
		}
		B[m + 1][n + 1] = 0;
		fB[m + 1][n + 1] = n;
		for (int i = m; i; --i) {
			for (int j = n; j; --j) {
				if (t[i] != s[j]) {
					continue;
				}
				int k = i == m ? n + 1 : ri[j + 1][t[i + 1] - 'a'];
				if (B[i + 1][k] == -1) {
					continue;
				}
				B[i][j] = B[i + 1][k];
				fB[i][j] = fB[i + 1][k];
				if (j + 1 != k) {
					B[i][j] += fB[i][j] - j;
					fB[i][j] = j;
				}
			}
		}
		// debug('B');
		// for (int i = 1; i <= m; ++i) {
		// 	for (int j = 1; j <= n; ++j) {
		// 		std::cerr << B[i][j] << " \n"[j == n];
		// 	}
		// }
		// debug('B');
		int ans = B[1][ri[1][t[1] - 'a']];
		if (ans == -1) {
			std::cout << "-1\n";
			continue;
		}
		if (s[1] != t[1]) {
			ans += std::min<int>(fB[1][ri[1][t[1] - 'a']], ri[1][t[1] - 'a'] * 2 + 1);
		}
		Min(ans, A[m][le[n][t[m] - 'a']] + 1 + n - le[n][t[m] - 'a']);
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				int k = ri[j + 1][t[i + 1] - 'a'];
				int x = A[i][j], y = B[i + 1][k];
				if ((x | y) == -1) {
					continue;
				}
				int z = x + y + 1;
				if (j + 1 != k) {
					z += std::min(fB[i + 1][k] - j, k * 2 - 2 - j - fA[i][j]);
				}
				Min(ans, z);
			}
		}
		std::cout << ans << '\n';
	}
	return 0;
}