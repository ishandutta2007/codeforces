#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

const int N = 2e5;
ll val[N];

int main() {
	int n; ll k1, k2;
	cin >> n >> k1 >> k2;
	int k = k1 + k2;
	for (int i = 0; i < n; ++i) {
		cin >> val[i];
	}
	priority_queue<ll> vals;
	for (int i = 0; i < n; ++i) {
		ll v;
		cin >> v;
		val[i] -= v;
		if (val[i] < 0) val[i] = -val[i];
		vals.push(val[i]);
	}
	for (int j = 0; j < k; ++j) {
		ll v = vals.top();
		vals.pop();
		if (v == 0) {
			vals.push(v+1);
		} else {
			vals.push(v-1);
		}
	}
	ll res = 0;
	while(! vals.empty()) {
		res += vals.top() * vals.top();
		vals.pop();
	}
	std::cout << res << '\n';
}