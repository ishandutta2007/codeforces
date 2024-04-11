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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		i64 n;
		int m;
		cin >> n >> m;
		vl need(61), have(61), pre(61);
		rep(i, 0, 61) need[i] = n >> i & 1;
		while (m--) {
			int a;
			cin >> a;
			++have[tail_count(a)];
		}
		rep(i, 0, 61) pre[i] = have[i] << i;
		rep(i, 1, 61) pre[i] += pre[i - 1];
		if (pre[60] < n) {
			cout << -1 << endl;
			continue;
		}
		int ans = 0;
		for (int i = 60; i; --i) {
			debug(i, have[i], need[i]);
			if (have[i] < need[i]) {
				need[i - 1] += need[i] - have[i] << 1;
				n -= have[i] << i;
			} else {
				n -= need[i] << i;
				if (i && pre[i - 1] < n) {
					++ans;
					have[i - 1] += 2;
					pre[i - 1] += 1LL << i;
				}
			}
		}
		cout << ans << endl;
	}
}