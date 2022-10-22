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
		string s;
		cin >> s;
		set<int> adj[26];
		vi link(26);
		rep(i, 1, s.size()) {
			int u = s[i - 1] - 'a', v = s[i] - 'a';
			if (adj[u].insert(v).ss) link[u] ^= v;
			if (adj[v].insert(u).ss) link[v] ^= u;
		}
		vi node[26], vis(26), nxt(27);
		bool ok = true;
		rep(i, 0, 26) {
			node[adj[i].size()].pb(i);
			if (int(adj[i].size()) > 2) ok = false;
		}
		if (!ok) {
			cout << "NO" << endl;
			continue;
		}
		int x = 26;
		for (int u : node[1]) if (!vis[u]) {
			vis[u] = 1;
			nxt[x] = u;
			int v = link[u];
			while (true) {
				vis[v] = 1;
				nxt[u] = v;
				if (int(adj[v].size() == 1)) break;
				v = link[v] ^ u;
				u = nxt[u];
			}
			x = v;
		}
		for (int u : node[0]) {
			nxt[x] = u;
			x = u;
		}
		for (int u : node[2]) if (!vis[u]) ok = false;
		if (!ok) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		x = 26;
		rep(i, 0, 26) {
			x = nxt[x];
			cout << char(x + 'a');
		}
		cout << endl;
	}
}