#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

void solve() {
	ll h;
	int n;
	cin >> h >> n;

	// Two back-to-back: pop
	// One: Must remove it
	vector<ll> blocks(n);
	for (int i = 0; i < n; ++i) {
		cin >> blocks[i];
	}
	int res = 0;
	for (int i = 1; i < n; ++i) {
		if (i == n-1) res += (blocks[i] >= 2);
		else {
			if (i+1 < n && blocks[i] == blocks[i+1] + 1) ++i;
			else ++res;
		}
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) solve();
}