#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll ca, cb;

pair<ll, ll> ask(int i) {
	cout << "+ " << (i+1) << endl;
	ll va, vb;
	cin >> va >> vb;
	va -= ca;
	vb -= cb;
	ca += va;
	cb += vb;
	return {va, vb};
}

void answer(vector<int>& res) {
	cout << "! ";
	for (auto v : res) cout << v << ' '; cout << endl;
}

// v = a(a-1) / 2 -> a
// In case of ambiguity (a = 0 or 1), returns 1
ll get(ll v) {
	ll a = 1;
	while(a * (a-1) / 2 < v) ++a;
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	cin >> ca >> cb;

	vector<int> ans(n, -1);

	// 1. Solve first three in 4 operations
	auto q1 = ask(0);
	auto q2 = ask(1);
	auto q3 = ask(2);
	auto q4 = ask(0);

	ans[0] = get(q4.first) + 1;
	if (q2.second == 0) ans[2] = 1;
	else ans[2] = get(q3.first) + 1;
	ans[1] = q4.second / ans[2];

	// 2. Solve rest in n-4 operations
	ll pre = q3.second - (ans[0] - 1) * ans[1]; // v[i-2] * v[i] + v[i] * v[i+1]
	for (int i = 3; i < n; ++i) {
		if (i == n-1) {
			ans[i] = pre / ans[i-2];
		} else {
			auto qr = ask(i);
			if (pre == 0) ans[i] = 1;
			else ans[i] = get(qr.first) + 1;
			pre = qr.second - ans[i-2] * ans[i-1]; // v[i-1] * v[i+1] + v[i+1] * v[i+2]
		}
	}

	ans[0] -= 2;
	for (int i = 1; i < n-1; ++i) --ans[i];
	answer(ans);
}