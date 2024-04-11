#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n, m, k;
	cin >> n >> m >> k;

	vector<ll> vec(m);
	for (int i = 0; i < m; ++i) {
		cin >> vec[i];
	}

	ll cur = 1;
	ll mx = -1;
	ll res = 0;
	int j = 0;
	while(j < vec.size()) {
		if (vec[j] <= mx) {
			++cur;
			++j;
		} else if (vec[j] < cur + k) {
			++res;
			mx = cur + k-1;
		} else {
			cur += ((vec[j] - cur) / k) * k;
		}
	}
	cout << res << '\n';
}