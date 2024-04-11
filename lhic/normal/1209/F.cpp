#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int N = 1e6 + 100;

int n, m;

vector<int> dig;

int cc;

vector<pair<int, int>> eds[N];

void add_edge(int x, int y, int w) {
	eds[x].emplace_back(y, w);
}

ll num[N];
pair<int, int> dd[N];
pair<int, int> go[N];

struct cmp {
	bool operator()(int a, int b) {
		return make_pair(dd[a], a) < make_pair(dd[b], b);
	}
};

set<int, cmp> ss;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n >> m;
	cc = n;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		dig.clear();
		int cur = i + 1;
		while (cur)
			dig.push_back(cur % 10), cur /= 10;
		reverse(ALL(dig));
		int now = a;
		for (int i = 0; i < dig.size(); ++i) {
			if (i + 1 != dig.size()) {
				add_edge(now, cc, dig[i]);
				now = cc;
				++cc;
			} else {
				add_edge(now, b, dig[i]);
			}
		}
		now = b;
		for (int i = 0; i < dig.size(); ++i) {
			if (i + 1 != dig.size()) {
				add_edge(now, cc, dig[i]);
				now = cc;
				++cc;
			} else {
				add_edge(now, a, dig[i]);
			}
		}
	}
	for (int i = 0; i < cc; ++i)
		num[i] = 0, dd[i] = {N, N};
	dd[0] = {-1, 0};
	int now = 0;
	go[now] = dd[0];
	ss.insert(0);
	while (!ss.empty()) {
		int x = *ss.begin();
		ss.erase(x);
		if (dd[x] != go[now]) {
			++now;
			go[now] = dd[x];
		}
		for (auto e: eds[x]) {
			int u = e.first;
			if (make_pair(now, e.second) < dd[u]) {
				ss.erase(u);
				dd[u] = make_pair(now, e.second);
				num[u] = (num[x] * 10 + e.second) % MOD;
				ss.insert(u);
			}
		}
	}
	for (int i = 1; i < n; ++i) {
		cout << num[i] << "\n";
	}
	return 0;
}