#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	ll mx = 0;
	for (int i = 0; i < n; ++i) {
		ll v;
		cin >> v;
		v += mx;
		cout << v << ' ';
		mx = max(mx, v);
	}
	cout << '\n';
}