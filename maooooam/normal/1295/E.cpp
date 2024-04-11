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

constexpr int const maxn = 1 << 18;
int p[maxn], q[maxn];
i64 a[maxn], b[maxn];

i64 seg[maxn << 1], tag[maxn << 1];

#define md (l + r >> 1)
#define ls (i << 1)
#define rs (ls ^ 1)
#define ll l, md, ls
#define rr md, r, rs

i64 value(int i) { return seg[i] + tag[i]; }

void push_down(int i) { tag[ls] += tag[i]; tag[rs] += tag[i]; tag[i] = 0; }

void push_up(int i) { seg[i] = min(value(ls), value(rs)); }

void build(int l, int r, int i) {
	if (l + 1 == r) {
		seg[i] = b[l];
		tag[i] = 0;
		return;
	}
	push_down(i);
	build(ll);
	build(rr);
	push_up(i);
}

void modify(int l, int r, int i, int ql, int qr, i64 x) {
	if (l >= qr || r <= ql) return;
	if (l >= ql && r <= qr) { tag[i] += x; return; }
	push_down(i);
	modify(ll, ql, qr, x);
	modify(rr, ql, qr, x);
	push_up(i);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	rep(i, 1, n + 1) cin >> p[i];
	rep(i, 1, n + 1) cin >> a[i];
	rep(i, 1, n + 1) q[p[i]] = i;
	rep(i, 1, n + 1) b[i] = a[i] + b[i - 1];
	build(1, n, 1);
	i64 ans = a[1];
	rep(i, 1, n + 1) {
		int j = q[i];
		modify(1, n, 1, 1, q[i], a[q[i]]);
		modify(1, n, 1, q[i], n, -a[q[i]]);
		minn(ans, value(1));
	}
	cout << ans << endl;
}