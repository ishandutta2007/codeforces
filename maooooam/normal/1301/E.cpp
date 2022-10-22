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

constexpr int const maxn = 512;
constexpr int const maxq = 300000;
char pic[maxn][maxn];
int have[maxn][maxn], a[maxn][maxn], r1[maxq], r2[maxq], c1[maxq], c2[maxq], ans[maxq];
vector<pii> pos[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(a, 0x3f, sizeof (a));
	int n, m, q;
	cin >> n >> m >> q;
	rep(i, 1, n + 1) cin >> pic[i] + 1;
	rep(o, 0, 4) {
		memset(have, 0, sizeof (have));
		rep(i, 1, n + 1) rep(j, 1, m + 1) have[i][j] = pic[i][j] == "RGYB"[o];
		rep(i, 1, maxn) rep(j, 1, maxn) have[i][j] += have[i - 1][j] + have[i][j - 1] - have[i - 1][j - 1];
		rep(i, 1, n) rep(j, 1, m) {
			int x = 0;
			rep(k, 1, maxn) {
				int cnt;
				if (o == 0) cnt = have[i][j] + have[i - k][j - k] - have[i - k][j] - have[i][j - k];
				if (o == 1) cnt = have[i][j + k] + have[i - k][j] - have[i - k][j + k] - have[i][j];
				if (o == 2) cnt = have[i + k][j] + have[i][j - k] - have[i][j] - have[i + k][j - k];
				if (o == 3) cnt = have[i + k][j + k] + have[i][j] - have[i][j + k] - have[i + k][j];
				if (cnt != k * k) break;
				x = k;
				if (k == i || k == j) break;
			}
			minn(a[i][j], x);
		}
	}
	rep(i, 1, n) rep(j, 1, n) debug(i, j, a[i][j]);
	rep(i, 0, q) cin >> r1[i] >> c1[i] >> r2[i] >> c2[i];
	rep(i, 0, q) {
		--r1[i], --c1[i];
		++r2[i], ++c2[i];
	}
	rep(i, 1, n) rep(j, 1, m) pos[a[i][j]].eb(i + 1, j + 1);
	memset(have, 0, sizeof (have));
	for (int k = min(n, m) >> 1; k; --k) {
		for (auto const& p : pos[k]) have[p.ff][p.ss] = 1;
		memcpy(a, have, sizeof (a));
		// if (k <= 2) {
		// 	debug(k);
		// 	rep(i, 1, n + 1) rep(j, 1, m + 1) debug(i, j, have[i][j]);
		// }
		rep(i, 1, maxn) rep(j, 1, maxn) a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		rep(o, 0, q) if (!ans[o] && r2[o] - r1[o] > k + k && c2[o] - c1[o] > k + k && a[r2[o] - k][c2[o] - k] + a[r1[o] + k][c1[o] + k] > a[r1[o] + k][c2[o] - k] + a[r2[o] - k][c1[o] + k]) ans[o] = k;
	}
	rep(i, 0, q) cout << (ans[i] * ans[i] << 2) << "\n";
}