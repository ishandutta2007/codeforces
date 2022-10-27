#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
#define sz(a) (int)a.size()
const int N = 2e5 + 100;
const int mod = 1e9 + 7;


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int s = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			s += x;
		}
		if (s % n == 0) {
			cout << 0 << "\n";
		}
		else {
			cout << 1 << "\n";
		}
	}
	return 0;
}