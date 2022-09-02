#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll BOUND = 1e9;

int main() {
	// Step 1: Find some position that can keep its original value: vals[i-1] < vals[i].
	// Set res[i] = vals[i].
	// Then make the sequence decreasing from this i, with this i as the smallest element.

	int n;
	cin >> n;
	vector<ll> vals(n);
	for (int i = 0; i < n; ++i) cin >> vals[i];

	int si = -1;
	for (int i = 0; i < n; ++i) {
		int ti = (i+1) % n;
		if (vals[i] < vals[ti]) si = ti;
	}
	
	if (si == -1) {
		if (vals[0] == 0) {
			cout << "YES\n";
			for (int i = 0; i < n; ++i) cout << "1 ";
			cout << '\n';
		} else {
			cout << "NO\n";
		}
	} else {
		vector<ll> res(n);
		res[si] = vals[si];
		int i = si;
		while(true) {
			int pi = i;
			--i;
			if (i < 0) i = n-1;
			if (i == si) break;

			ll mod = res[pi];
			res[i] = mod + vals[i];
			if (res[i] < BOUND) {
				res[i] += mod * (BOUND / mod + 1);
			}
		}
		
		cout << "YES\n";
		for (int i = 0; i < n; ++i) cout << res[i] << ' '; cout << '\n';
	}
}