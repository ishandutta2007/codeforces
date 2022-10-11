#include <bits/stdc++.h>

using namespace std;

template<class T>
string to_string(T v);

string to_string(string s) {
	return "\"" + s + "\"";
}

string to_string(bool b) {
	return b ? "true" : "false";
}

template<class A, class B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<class T>
string to_string(T v) {
	string s = "{";
	bool first = true;
	for (auto x : v) {
		if (!first)
			s += ", ";
		first = false;
		s += to_string(x);
	}
	return s + "}";
}

void debug_out() { cerr << endl; }
template<class Head, class... Tail>
void debug_out(Head head, Tail... tail) {
	cerr << ' ' << to_string(head);
	debug_out(tail...);
}

#ifdef LOCAL
#define debug(...) cerr << '[' << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

const int MOD = 998244353;

struct Mint {
	int val;

	Mint(int x = 0) : val((x % MOD + MOD) % MOD) {}

	Mint operator * (Mint b) {
		return (long long) val * b.val % MOD;
	}

	Mint operator + (Mint b) {
		int now = val + b.val;
		return now - MOD * (now >= MOD);
	}
};

Mint power(Mint a, int b) {
	if (b == 0)
		return Mint(1);
	if (b % 2 == 0)
		return power(a * a, b / 2);
	return power(a, b - 1) * a;
}

pair<Mint, Mint> mult(pair<Mint, Mint> a, pair<Mint, Mint> b) {
	pair<Mint, Mint> c;
	c.first = a.first * b.second + a.second * b.first;
	c.second = a.second * b.second;
	return c;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> monsters(n);
	for (auto &x : monsters)
		cin >> x;
	sort(monsters.begin(), monsters.end());
	vector<Mint> pref_sums(n + 1, Mint(0));
	for (int i = 0; i < n; i++)
		pref_sums[i + 1] = pref_sums[i] + monsters[i];
	vector<Mint> suf_sums(n + 1, Mint(0));
	for (int i = n - 1; i >= 0; i--)
		suf_sums[i] = suf_sums[i + 1] + monsters[i];

	while (m--) {
		int a, b;
		cin >> a >> b;
		assert(a != 0);
		int id = (int) (lower_bound(monsters.begin(), monsters.end(), b) - monsters.begin());
		int cnt_more = n - id;
		int cnt_less = id;
		debug(a, b, id);
		if (a > cnt_more) {
			cout << "0\n";
			continue;
		}
		Mint ans = Mint(0);
		ans = ans + pref_sums[id] * Mint(cnt_more + 1 - a) * power(Mint(cnt_more + 1), MOD - 2);
		ans = ans + suf_sums[id] * Mint(cnt_more - a) * power(Mint(cnt_more), MOD - 2);
		cout << ans.val << '\n';
	}
}