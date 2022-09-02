#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;

	vector<int> sta;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		while(! sta.empty() && sta.back() > v) sta.pop_back();
		sta.push_back(v);
	}
	cout << (n - sta.size()) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}