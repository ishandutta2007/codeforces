#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

// rand-function that works properly on windows, and is faster than rand
// https://codeforces.com/blog/entry/61587
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand(T a, T b) {
	return uniform_int_distribution<T>(a, b)(rng);
}

const ll P1 = (ll)1e9 + 7;
const ll P2 = 9 * (ll)1e8 + 11;
const ll M1 = rand(1ll, P1-1);
const ll M2 = rand(1ll, P2-1);

ll hashVec(const vector<int>& vec) {
	ll h1 = 0, h2 = 0;
	for (int v : vec) {
		h1 = (h1 * M1 + v) % P1;
		h2 = (h2 * M2 + v) % P2;
	}
	return h1 + P1 * h2;
}

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> conns(n);
	vector<pair<ll, ll>> res(n);
	for (int i = 0; i < n; ++i) cin >> res[i].second;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		conns[b-1].push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		sort(conns[i].begin(), conns[i].end());
		res[i].first = hashVec(conns[i]);
	}
	sort(res.begin(), res.end());

	ll ans = 0;
	for (int i = 0; i < n;) {
		int j = i;
		ll sum = 0;
		while(j < n && res[j].first == res[i].first) {
			sum += res[j].second;
			++j;
		}
		if (res[i].first != 0) ans = gcd(ans, sum);
		i = j;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();

}