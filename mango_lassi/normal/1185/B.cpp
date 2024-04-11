#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

bool solve() {
	string a, b;
	cin >> a >> b;
	if (a[0] != b[0]) return false;

	int j = 1;
	for (int i = 1; i < a.size(); ++i) {
		while(j < b.size() && b[j] != a[i]) {
			if (b[j] != b[j-1]) return false;
			++j;
		}
		if (j >= b.size()) return false;
		++j;
	}
	for (; j < b.size(); ++j) {
		if (b[j] != b[j-1]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		bool res = solve();
		if (res) cout << "YES\n";
		else cout << "NO\n";
	}
}