#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<ll> bs(n);
	vector<ll> cs(m);
	for (int i = 0; i < n; ++i) cin >> bs[i];
	for (int i = 0; i < m; ++i) cin >> cs[i];
	sort(bs.begin(), bs.end());
	sort(cs.begin(), cs.end());

	// Every boy gives to every girl !!!
	if (cs[0] < bs[n-1]) {
		cout << "-1\n";
	} else if (cs[0] == bs[n-1]) {
		ll sum = 0;
		for (int j = 0; j < m; ++j) sum += cs[j] - bs[n-1];
		for (int i = 0; i < n; ++i) sum += m * bs[i];
		cout << sum << '\n';
	} else {
		ll sum = cs[0] - bs[n-2];
		for (int j = 1; j < m; ++j) sum += cs[j] - bs[n-1];
		for (int i = 0; i < n; ++i) sum += m * bs[i];
		cout << sum << '\n';
	}
}