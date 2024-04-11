#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	
	int mask = 0;
	for (int j = 0; j < k; ++j) mask |= (1<<j);

	// Does greedy work? Hopefully :Dd
	ll ans = 0;
	int xs = 0;
	map<int, int> prefs;
	for (int i = 0; i < n; ++i) {
		++prefs[xs];

		int v;
		cin >> v;
		xs ^= v;

		if (prefs[xs ^ mask] < prefs[xs]) xs ^= mask;
		ans += (i+1) - prefs[xs];
	}
	cout << ans << '\n';
}