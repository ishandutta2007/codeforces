#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vector<int> vals(n);
	for (int i = 0; i < n; ++i) cin >> vals[i];

	int s = 0;
	while(s < n-1) {
		int x = s;
		for (int i = s; i < n; ++i) {
			if (vals[i] < vals[x]) x = i;
		}
		for (int i = x-1; i >= s; --i) {
			swap(vals[i], vals[i+1]);
		}
		if (s == x) ++s;
		else s = x;
	}
	
	for (auto v : vals) cout << v << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		solve();
	}
}