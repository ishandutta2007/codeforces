#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

ll xorOp(ll a, ll b, vector<pair<char, pair<ll, ll>>>& ans) {
	ans.push_back({'^', {a, b}});
	return a ^ b;
}
ll addOp(ll a, ll b, vector<pair<char, pair<ll, ll>>>& ans) {
	ans.push_back({'+', {a, b}});
	return a + b;
}
ll shiftOp(ll v, int k, vector<pair<char, pair<ll, ll>>>& ans) {
	for (; k; --k) v = addOp(v, v, ans);
	return v;
}

void solve() {
	ll x;
	cin >> x;

	vector<pair<char, pair<ll, ll>>> ans;
	if (x % 4 == 3) {
		addOp(x, x, ans);
		x = xorOp(x, 2*x, ans);
	}
	if (x != 1) {
		int k = 0;
		while(x >= (1ll << (k+1))) ++k;
		ll xs = shiftOp(x, k, ans);
		
		xorOp(x, xs, ans);
		addOp(x, xs, ans);
		ll v = xorOp(x + xs, x ^ xs, ans);

		while(v <= x) v = shiftOp(v, 1, ans);
		while(true) {
			if (x & v) x = xorOp(x, v, ans);
			if (x == 1) break;

			ll y = x;
			while(true) {
				if (y & v) y = xorOp(y, v, ans);
				if (y == v/2) break;
				else y = shiftOp(y, 1, ans);
			}
			v = y;
		}
	}

	cout << ans.size() << '\n';
	for (auto pr : ans) cout << pr.second.first << ' ' << pr.first << ' ' << pr.second.second << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
	
}