#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<bool> used(3*n, false);
	vector<int> matching;
	for (int j = 0; j < m; ++j) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		if (! used[a] && ! used[b]) {
			used[a] = true;
			used[b] = true;
			matching.push_back(j);
		}
	}
	if (matching.size() >= n) {
		matching.resize(n);
		cout << "Matching\n";
		for (auto j : matching) cout << j+1 << ' '; cout << '\n';
	} else {
		cout << "IndSet\n";
		int c = 0;
		for (int i = 0; c < n && i < 3*n; ++i) {
			if (! used[i]) {
				cout << i+1 << ' ';
				++c;
			}
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		solve();
	}
}