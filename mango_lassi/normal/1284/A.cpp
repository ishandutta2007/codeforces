#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> s(n), t(m);
	for (int i = 0; i < n; ++i) cin >> s[i];
	for (int i = 0; i < m; ++i) cin >> t[i];
	
	int q;
	cin >> q;
	for (; q > 0; --q) {
		int y;
		cin >> y;
		--y;
		cout << s[y % n] << t[y % m] << '\n';
	}
}