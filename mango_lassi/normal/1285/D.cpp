#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll nxt(ll b) {
	return b ? (b << 1) : 1;
}

ll solve(const vector<ll>& vals) {
	ll b = 0;
	for (ll v : vals) {
		while(nxt(b) <= v) b = nxt(b);
	}
	if (b == 0) return 0;

	vector<ll> ons, offs;
	for (ll v : vals) {
		if (v & b) ons.push_back(v ^ b);
		else offs.push_back(v);
	}

	if (ons.empty()) return solve(offs);
	else if (offs.empty()) return solve(ons);
	else return b ^ min(solve(ons), solve(offs));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> vals(n);
	for (ll& v : vals) cin >> v;
	ll res = solve(vals);
	cout << res << '\n';
}