#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<ll> as(n);
	for (int i = 0; i < n; ++i) cin >> as[i];
	sort(as.begin(), as.end());

	ll cur = 0;
	vector<ll> rems(m, 0);
	for (int i = 0; i < n; ++i) {
		// eat exactly i+1 candies
		// optimal to eat least sugary candy last
		rems[i % m] += as[i];
		cur += rems[i % m];
		cout << cur << ' ';
	}
	cout << '\n';
}