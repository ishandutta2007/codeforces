#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 1e5;
vector<int> conns[N];
ll vals[N];

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

ll solve(int i, int p, const vector<pair<ll, ll>>& path) {
	ll res = 0;
	vector<pair<ll, ll>> nxt_path;
	for (auto pr : path) {
		pair<ll, ll> off = {gcd(pr.first, vals[i]), pr.second};
		if (! nxt_path.empty() && nxt_path.back().first == off.first) {
			nxt_path.back().second += off.second;
		} else {
			nxt_path.push_back(off);
		}
		res = (res + (off.first % MOD) * off.second) % MOD;
	}
	nxt_path.push_back({0, 1});

	for (auto t : conns[i]) {
		if (t != p) res = (res + solve(t, i, nxt_path)) % MOD;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> vals[i];
	for (int j = 0; j < n-1; ++j) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	vector<pair<ll, ll>> path = {{0, 1}};
	ll res = solve(0, -1, path);
	cout << res << '\n';
}