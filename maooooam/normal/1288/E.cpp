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
	int n, m;
	cin >> n >> m;
	list<int> chat;
	vector<list<int>::iterator> iter(n + 1);
	rep(i, 1, n + 1) {
		chat.pb(i);
		iter[i] = prev(chat.end());
	}
	vi a(m), l(n + 1), r(n + 1);
	iota(range(l), 0);
	iota(range(r), 0);
	rep(i, 0, m) {
		cin >> a[i];
		l[a[i]] = 1;
		chat.erase(iter[a[i]]);
		chat.push_front(a[i]);
		iter[a[i]] = chat.begin();
	}
	int tmp = 0;
	for (int x : chat) {
		++tmp;
		minn(l[x], tmp);
		maxx(r[x], tmp);
	}
	vi bit(n + 1), last(n + 1);
	for (int x : a) if (!last[x]) {
		last[x] = 1;
		int cnt = 0;
		for (int i = x; i <= n; i += lowbit(i)) cnt += bit[i];
		maxx(r[x], x + cnt);
		debug(x, x + cnt);
		for (int i = x; i; i ^= lowbit(i)) ++bit[i];
	}
	fill(range(last), -1);
	bit.resize(m + 1);
	fill(range(bit), 0);
	rep(i, 0, m) {
		if (~last[a[i]]) {
			int cnt = 0;
			for (int j = last[a[i]] + 1; j <= m; j += lowbit(j)) cnt += bit[j];
			maxx(r[a[i]], cnt);
			debug(a[i], cnt);
			for (int j = last[a[i]] + 1; j; j ^= lowbit(j)) --bit[j];
		}
		last[a[i]] = i;
		for (int j = i + 1; j; j ^= lowbit(j)) ++bit[j];
	}
	rep(i, 1, n + 1) cout << l[i] << " " << r[i] << "\n";
}