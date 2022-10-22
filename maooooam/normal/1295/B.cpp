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
#define const_range(c)	c.cbegin(), c.cend()
#define lowbit(x)	((x) & -(x))
#define pop_count	__builin_popcount
#define pop_count64	__builtin_popcountll
#define tail_count	__builtin_ctz
#define tail_count64	__builtin_ctzll
#define lead_count	__builtin_clz
#define lead_count64	__builtin_clzll

#define temp_name template<typename

temp_name T1, typename T2> ostream& operator<< (ostream& os, const pair<T1, T2>& p) { return os << "<" << p.ff << "," << p.ss << ">"; }
#define container_ostream(container)						\
temp_name... T> ostream& operator<< (ostream& os, const container<T...>& c) {	\
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

temp_name T> T& minn(T& x, const T& y) { return x = min(x, y); }
temp_name T> T& maxx(T& x, const T& y) { return x = max(x, y); }

constexpr const int mod = 1000000007;
constexpr int add(int a, int b) { return a + b < mod ? a + b : a + b - mod; }
constexpr int sub(int a, int b) { return a < b ? mod + a - b : a - b; }
constexpr int mul(int a, int b) { return 1LL * a * b % mod; }
#define more_para(type, func) temp_name... T> constexpr type func(type a, type b, T... c) { return func(func(a, b), c...); }
more_para(int, add);
more_para(int, sub);
more_para(int, mul);
constexpr int square(int a) { return mul(a, a); }
constexpr int fpow(int a, int b) { return b ? mul(b & 1 ? a : 1, square(fpow(a, b >> 1))) : 1; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int n, x;
		string s;
		cin >> n >> x >> s;
		vi a(n);
		rep(i, 0, n) a[i] = s[i] == '0' ? 1 : -1;
		rep(i, 1, n) a[i] += a[i - 1];
		int p = min(0, *min_element(const_range(a)));
		int q = max(0, *max_element(const_range(a)));
		vi cnt(q - p + 1, 0);
		rep(i, 0, n) ++cnt[a[i] - p];
		debug(a);
		debug(cnt);
		if (a.back()) {
			i64 ans = !x;
			if (x < p) {
				if (a.back() < 0) {
					int t = p - x;
					x += ((t - 1) / -a.back() + 1) * -a.back();
				}
			}
			if (x > q) {
				if (a.back() > 0) {
					int t = x - q;
					x -= ((t - 1) / a.back() + 1) * a.back();
				}
			}
			while (p <= x && x <= q) {
				ans += cnt[x - p];
				x -= a.back();
			}
			cout << ans << endl;
		} else {
			cout << (p <= x && x <= q ? "-1" : "0") << endl;
		}
	}
}