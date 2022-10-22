#include <bits/stdc++.h>
using namespace std;

#define rep(i, s, t) for (int i = s; i < int(t); ++i)

#define sc	scanf
#define pr	printf
#define ff	first
#define ss	second
#define mp	make_pair
#define pb	push_back
#define eb	emplace_back
#define range(c)	c.begin(), c.end()
#define lowbit(x)	((x) & -(x))
#define pop_count	__builin_popcount
#define pop_count64	__builtin_popcountll
#define tail_count	__builtin_ctz
#define tail_count64	__builtin_ctzll
#define lead_count	__builtin_clz
#define lead_count64	__builtin_clzll

#define temp_name template<typename

temp_name T1, typename T2> ostream& operator<< (ostream& os, pair<T1, T2> const& p) { return os << "<" << p.ff << "," << p.ss << ">"; }
#define container_ostream(container)						\
temp_name... T> ostream& operator<< (ostream& os, container<T...> const& c) {	\
	if (c.empty()) return os << "{ }";					\
	auto iter = c.cbegin();							\
	os << "{ " << *iter;							\
	while (++iter != c.cend()) os << ", " << *iter;				\
	return os << " }";							\
}
container_ostream(vector);
container_ostream(set);
container_ostream(map);

void dbg() { cerr << endl;}
temp_name Head, typename... Tail> void dbg(Head h, Tail... t) { cerr << " " << h; dbg(t...); }

#ifdef LOCAL
#define debug(...) cerr << "[ "#__VA_ARGS__" ] :", dbg(__VA_ARGS__)
#else
#define debug(...) 0
#endif

typedef long long i64;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<i64> vl;

temp_name T> T& minn(T& x, T const& y) { return x = min(x, y); }
temp_name T> T& maxx(T& x, T const& y) { return x = max(x, y); }

constexpr int const mod = 1000000007;
constexpr int add(int a, int b) { return a + b < mod ? a + b : a + b - mod; }
constexpr int sub(int a, int b) { return a < b ? mod + a - b : a - b; }
constexpr int mul(int a, int b) { return 1LL * a * b % mod; }
#define more_para(type, func) temp_name... T> constexpr type func(type a, type b, T... c) { return func(func(a, b), c...); }
more_para(int, add);
more_para(int, sub);
more_para(int, mul);
constexpr int square(int a) { return mul(a, a); }
constexpr int fpow(int a, int b) { return b ? mul(b & 1 ? a : 1, square(fpow(a, b >> 1))) : 1; }

char direction(int dx, int dy) { return dx ? (dx == 1 ? 'D' : 'U') : (dy == 1 ? 'R' : 'L'); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	if (4 * n * m - 2 * n - 2 * m < k) return cout << "NO" << endl, 0;
	vector<pair<int, string>> ans, res;
	rep(i, 0, n) {
		if (i) ans.eb(1, "D");
		ans.eb(m - 1, i == n - 1 ? "R" : "RDU");
		ans.eb(m - 1, "L");
	}
	ans.eb(n - 1, "U");
	debug(ans);
	for (auto const& move : ans) if (move.ff) {
		int step = move.ss.size();
		if (k < move.ff * step) {
			int k0 = k / step, k1 = k % step;
			if (k / step) res.eb(k / step, move.ss);
			if (k % step) res.eb(1, move.ss.substr(0, k % step)); 
			break;
		} else {
			k -= move.ff * step;
			res.pb(move);
		}
	}
	cout << "YES" << endl << res.size() << endl;
	for (auto const& move : res) cout << move.ff << " " << move.ss << "\n";
}