#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ll k;
	cin >> n >> k;

	vector<ll> vals(n);
	for (int i = 0; i < n; ++i) cin >> vals[i];
	sort(vals.begin(), vals.end());

	int h = n/2;
	int cou = 1;
	ll v = vals[h];
	while(k >= cou) {
		int t = h + cou;
		ll d = (t < n ? vals[t] - v : INF);
		ll add = min(k / cou, d);
		k -= add * cou;
		v += add;
		++cou;
	}
	cout << v << '\n';
}