#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll askAnd(int i, int j) {
	cout << "and " << i + 1 << ' ' << j + 1 << endl;
	ll res;
	cin >> res;
	return res;
}
ll askOr(int i, int j) {
	cout << "or " << i + 1 << ' ' << j + 1 << endl;
	ll res;
	cin >> res;
	return res;
}
void answer(ll v) {
	cout << "finish " << v << endl;
}

ll solveY(ll y_or_x, ll y_and_x, ll x) {
	return y_or_x ^ y_and_x ^ x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Say we know value 1 is x
	// Then, y = (y | x) ^ (y & x) ^ x

	// In both: counted in all terms -> 1
	// In y, not x: counted in first term -> 1
	// In x, not y: counted in first and last term -> 0
	// In neither: counted in no term -> 0

	int n, k;
	cin >> n >> k;

	ll or01 = askOr(0, 1);
	ll or02 = askOr(0, 2);
	ll or12 = askOr(1, 2);
	ll and01 = askAnd(0, 1);
	ll and02 = askAnd(0, 2);

	vector<ll> vals(n);
	vals[0] = solveY((or01 | or02), (and01 | and02), or12);
	vals[1] = solveY(or01, and01, vals[0]);
	vals[2] = solveY(or02, and02, vals[0]);

	for (int i = 3; i < n; ++i) {
		ll orv = askOr(0, i);
		ll andv = askAnd(0, i);
		vals[i] = solveY(orv, andv, vals[0]);
	}
	sort(vals.begin(), vals.end());
	answer(vals[k-1]);
}