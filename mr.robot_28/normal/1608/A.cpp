#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define sz(a) (int)a.size()
const int N = 3e5 + 100;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 2; i <= n + 1; i++) {
			cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}