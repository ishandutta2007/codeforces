#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll a, b;
	cin >> a >> b;
	
	ll sum = a + b;
	ll cou = 0;
	while (sum > cou) {
		++cou;
		sum -= cou;
	}
	// We can pack in at most the first cou elements
	// So lets pack them in. Do exact sum for a, and we manage this.
	
	vector<ll> res_a;
	vector<ll> res_b;
	while(cou > 0) {
		if (a - cou >= 0) {
			a -= cou;
			res_a.push_back(cou);
		} else {
			res_b.push_back(cou);
		}
		--cou;
	}

	cout << res_a.size() << '\n';
	for (auto it : res_a) cout << it << ' '; cout << '\n';
	
	cout << res_b.size() << '\n';
	for (auto it : res_b) cout << it << ' '; cout << '\n';
}