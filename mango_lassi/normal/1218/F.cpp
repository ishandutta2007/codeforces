#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ll k;
	cin >> n >> k;

	vector<ll> xs(n);
	for (int i = 0; i < n; ++i) cin >> xs[i];

	ll a;
	cin >> a;

	bool fail = false;
	ll res = 0;
	priority_queue<ll> que;
	for (int i = 0; i < n; ++i) {
		ll c;
		cin >> c;
		que.push(-c);
		while(! que.empty() && k < xs[i]) {
			k += a;
			res += -que.top();
			que.pop();
		}
		if (k < xs[i]) fail = true;
	}
	if (fail) {
		cout << -1 << '\n';
	} else {
		cout << res << '\n';
	}
}