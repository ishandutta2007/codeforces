#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> as(n);
	multiset<int> bs;
	for (int i = 0; i < n; ++i) cin >> as[i];
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		bs.insert(v);
	}
	for (int i = 0; i < n; ++i) {
		auto it = bs.lower_bound(n - as[i]);
		if (it == bs.end()) {
			it = bs.lower_bound(0);
		}
		int b = *it;
		bs.erase(it);

		cout << (as[i] + b) % n << ' ';
	}
	cout << '\n';
}