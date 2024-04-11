#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	ll x, k;
	cin >> x >> k;
	vector<int> res;
	while(x != 0) {
		ll v = x % k;
		if (v < 0) v += k;
		res.push_back(v);
		x -= v;
		x /= k;
		x *= -1;
	}
	cout << res.size() << '\n';
	for (auto it : res) cout << it << ' '; cout << '\n';
}