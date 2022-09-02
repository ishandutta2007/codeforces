#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll modInv(ll x, ll b = MOD-2) {
	if (b & 1) return x * modInv(x, b - 1) % MOD;
	if (b == 0) return 1;
	return modInv(x*x % MOD, b / 2);
}

const int N = 5000;
const int M = 1e6;
bool vb[N];
bool hb[N];

ll fact[M];
ll inv_fact[M];

ll choose(ll a, ll b) {
	ll dv = inv_fact[b] * inv_fact[a-b] % MOD;
	return fact[a] * dv % MOD;
}

vector<ll> calc(const vector<int>& vals) {
	int n = vals.size();
	vector<ll> dp(N, 0);
	dp[0] = 1;

	int cur = 0;
	for (int i = 1; i <= n; ++i) {
		int v = vals[i-1];
		vector<ll> nxt(N, 0);
		for (int x = 0; 2*x <= v; ++x) {
			ll mult = choose(v-x, x);
			for (int y = 0; y <= cur; ++y) {
				nxt[y + x] = (nxt[y + x] + dp[y] * mult) % MOD;
			}
		}
		cur += v / 2;
		dp = nxt;
	}
	return dp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	fact[0] = 1;
	for (int i = 1; i < M; ++i) fact[i] = (fact[i-1] * i) % MOD;
	for (int i = 0; i < M; ++i) inv_fact[i] = modInv(fact[i]);

	int h, w, n;
	cin >> h >> w >> n;
	for (int i = 0; i < n; ++i) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		vb[x1-1] = true;
		vb[x2-1] = true;
		hb[y1-1] = true;
		hb[y2-1] = true;
	}

	ll tot1 = 0;
	vector<int> cols = {0};
	for (int x = 0; x < w; ++x) {
		if (vb[x]) {
			if (cols.back() != 0) cols.push_back(0);
		} else {
			++tot1;
			++cols.back();
		}
	}
	if (cols.back() == 0) cols.pop_back();

	ll tot2 = 0;
	vector<int> rows = {0};
	for (int y = 0; y < h; ++y) {
		if (hb[y]) {
			if (rows.back() != 0) rows.push_back(0);
		} else {
			++tot2;
			++rows.back();
		}
	}
	if (rows.back() == 0) rows.pop_back();

	auto dp1 = calc(cols);
	auto dp2 = calc(rows);

	// place x horizontal, y vertical
	ll ans = 0;
	for (int x = 0; x <= tot1 / 2; ++x) {
		for (int y = 0; y <= tot2 / 2; ++y) {
			if (tot1 < 2*x + y || tot2 < x + 2*y) continue;
			if (x >= dp1.size() || y > dp2.size()) continue;
			ll v1 = dp1[x] * choose(tot1 - 2*x, y) % MOD;
			ll v2 = dp2[y] * choose(tot2 - 2*y, x) % MOD;
			v1 = (v1 * fact[x]) % MOD;
			v2 = (v2 * fact[y]) % MOD;
			ans = (ans + v1 * v2) % MOD;
		}
	}
	ans %= MOD;
	if (ans < 0) ans += MOD;
	cout << ans << '\n';
}