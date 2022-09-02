#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const ll TI = 499122177;

int getj(ll a, ll b) {
	int j = 0;
	while(!(a & (1ll << j)) && ((1ll<<(j+1)) <= (b-a+1))) ++j;
	return j;
}

ll sum(ll a, ll b) {
	if (a > b) return 0;
	ll avg = (a + b) % MOD;
	ll len = (b - a + 1) % MOD;
	return ((avg * len) % MOD) * TI % MOD; 
}

vector<pair<ll, ll>> process(const vector<pair<ll, ll>>& segs) {
	vector<pair<ll, ll>> res;
	for (auto pr : segs) {
		ll a = pr.first;
		ll b = pr.second;
		while(a <= b) {
			int j = getj(a, b);
			res.push_back({a, a + (1ll << j) - 1});
			a += (1ll << j);

		}
	}
	sort(res.begin(), res.end());

	vector<pair<ll, ll>> act;
	for (auto pr : res) {
		if (! act.empty() && act.back().first == pr.first) act.pop_back();
		if (act.empty() || act.back().second < pr.second) act.push_back(pr);
	}
	return act;
}

void buildRes(const vector<pair<ll, ll>>& as, const vector<pair<ll, ll>>& bs, vector<pair<ll, ll>>& res) {
	auto as_d = process(as);
	for (auto p1 : as_d) {
		ll a1 = p1.first;
		ll b1 = p1.second;
		ll l1 = b1 - a1 + 1;
		ll m = ~(l1 - 1);
		int j = getj(p1.first, p1.second);
		for (auto p2 : bs) {
			ll a2 = p2.first;
			ll b2 = p2.second;
			ll l2 = b2 - a2 + 1;

			ll a = (a1 ^ a2) & m;
			ll b = a + l1 - 1;
			res.push_back({a, b});

			a = (a1 ^ b2) & m;
			b = a + l1 - 1;
			res.push_back({a, b});

			if (l2 > l1) {
				a = (a1 ^ (a2 + l1)) & m;
				b = a + l1 - 1;
				res.push_back({a, b});

				a = (a1 ^ (b2 - l1)) & m;
				b = a + l1 - 1;
				res.push_back({a, b});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<ll, ll>> as(n);
	for (int i = 0; i < n; ++i) cin >> as[i].first >> as[i].second;

	int m;
	cin >> m;
	vector<pair<ll, ll>> bs(m);
	for (int i = 0; i < m; ++i) cin >> bs[i].first >> bs[i].second;

	vector<pair<ll, ll>> res;
	buildRes(as, bs, res);
	buildRes(bs, as, res);
	sort(res.begin(), res.end());

	// for (auto pr : res) cerr << pr.first << ',' << pr.second << ' '; cerr << endl;

	ll ans = 0;
	ll lst = -1;
	for (auto pr : res) {
		ans += sum(max(lst + 1, pr.first), pr.second);
		lst = max(lst, pr.second);
	}
	cout << ans % MOD << '\n';
}