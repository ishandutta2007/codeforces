#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const ll INF = (ll)1e18;

ll modPow(ll a, ll b) {
	if (b & 1) return a * modPow(a, b ^ 1) % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b >> 1);
}

struct Cost {
	ll flips = 0;
	ll steps = 0;
	
	Cost() : flips(0), steps(0) {}
	Cost(ll f, ll s) : flips(f), steps(s) {}

	ll getCost() const {
		if (flips > 50) return INF;
		else return (1ll << flips) - 1 + steps;
	}
	ll getModCost() const {
		ll res = (modPow(2, flips) - 1 + steps) % MOD;
		if (res < 0) res += MOD;
		return res;
	}

	// Cheaper cost is larger, to use with priority queue
	bool operator<(const Cost& rhs) const {
		if (flips == rhs.flips) return steps > rhs.steps;
		if (flips > 50 || rhs.flips > 50) return flips > rhs.flips;
		return getCost() > rhs.getCost();
	}
};
bool worse(Cost a, Cost b) {
	return (!(b < a)) && (b.flips <= a.flips) && (b.flips % 2 == a.flips % 2);
}

const int N = 2 * (int)1e5;
vector<int> conns[N][2];
vector<Cost> dp[N];

void add(int i, Cost off, priority_queue<pair<Cost, int>>& que) {
	int r = 0;
	for (int j = 0; j + r < dp[i].size(); ++j) {
		swap(dp[i][j], dp[i][j + r]);

		if (worse(off, dp[i][j])) return;
		if (worse(dp[i][j], off)) {
			++r;
			--j;
		}
	}
	dp[i].resize((int)dp[i].size() - r);
	dp[i].push_back(off);
	dp[i].shrink_to_fit();
	que.push({off, i});
}

void solve() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a][0].push_back(b);
		conns[b][1].push_back(a);
	}

	// Store for every node the minimum cost to reach it by flipping k times
	// But don't store useless states! If we can reach it for cheaper with less flips, store only that option
	// At some point, less flips always becomes cheaper -> we only store O(log(n)) states

	priority_queue<pair<Cost, int>> que;
	add(0, Cost(0, 0), que);
	while(! que.empty()) {
		auto pr = que.top();
		que.pop();

		Cost c = pr.first;
		int i = pr.second;
		int j = c.flips & 1;

		// cerr << "Handle cost " << c.flips << ' ' << c.steps << " for " << i << '\n';

		for (auto t : conns[i][j]) {
			add(t, Cost(c.flips, c.steps + 1), que);
		}
		for (auto t : conns[i][j^1]) {
			add(t, Cost(c.flips + 1, c.steps + 1), que);
		}
	}

	if (dp[n-1].empty()) cout << -1 << '\n';
	else {
		Cost res = dp[n-1][0];
		for (auto cost : dp[n-1]) {
			if (res < cost) res = cost; // Inverted order!
		}
		cout << res.getModCost() << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}