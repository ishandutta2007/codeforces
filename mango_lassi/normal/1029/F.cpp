#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

// Get all divs <= sqrt(v). Other divs are v / divs[i]
vector<ll> divs(ll v) {
	vector<ll> res;
	for (ll i = 1; i*i <= v; ++i) {
		if (v % i == 0) res.push_back(i);
	}
	return res;
}

// Largest i such that vec[i] <= v
int bins(const vector<ll>& vec, ll v) {
	int low = -1;
	int high = (int)vec.size() - 1;
	while(low != high) {
		int mid = (low + high + 1) >> 1;
		if (vec[mid] <= v) low = mid;
		else high = mid - 1;
	}
	return low;
}

int main() {
	ll a, b;
	cin >> a >> b;
	ll s = a + b;

	vector<ll> a_divs = divs(a);
	vector<ll> b_divs = divs(b);
	vector<ll> s_divs = divs(s);

	ll res = INF;
	for (auto sd : s_divs) {
		ll rem = s / sd;
		ll ad = a_divs[bins(a_divs, sd)];
		ll bd = b_divs[bins(b_divs, sd)];
		if (min(a / ad, b / bd) <= rem) res = min(res, 2 * (sd + rem));
	}
	cout << res << '\n';
}