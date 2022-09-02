#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int INF = 1e9 + 7;

const int C = 20;
int conns[C];
int dp[1 << C]; // Nodes already on the path

// Returns TRUE if a is a subset of b, and FALSE otherwise
bool subset(int a, int b) {
	return (a ^ (a & b)) == 0;
}

void solve() {
	int n;
	cin >> n;

	string str, tar;
	cin >> str >> tar;

	for (int c = 0; c < C; ++c) conns[c] = 0;
	for (int i = 0; i < n; ++i) {
		int a = str[i] - 'a';
		int b = tar[i] - 'a';
		conns[a] |= 1 << b;
		// cout << i << ' ' << n << ' ' << a << ' ' << b << '\n';
	}

	// for (int i = 0; i < C; ++i) cout << conns[i] << '\n';
	
	// Optimal to make a path for every connected component. Every node in the component will appear in the path.
	// If node X appears in the order after all of the nodes its edges go to, we pay 1 for it. Otherwise, we pay 2 for it

	int res = 0; // Answer
	int ban = 0; // Already handled components
	for (int m = 1; m < (1 << C); ++m) {
		if (ban & m) continue; // Already handled nodes in this mask

		int inner = 0, outer = 0;
		for (int c = 0; c < C; ++c) {
			if (m & (1 << c)) inner |= conns[c];
			else outer |= conns[c];
		}

		// cerr << inner << ' ' << outer << '\n';

		if ((outer & m) || (! subset(inner, m))) continue; // Not a maximal component
		ban |= m; // Ban the component


		vector<int> ord;
		for (int x = m; x; x = (x-1) & m) {
			dp[x] = INF;
			ord.push_back(x);
		}

		dp[0] = -1; // Compensate for nonexistent edge
		reverse(ord.begin(), ord.end());

		for (int x : ord) {
			for (int c = 0; c < C; ++c) {
				if (x & (1 << c)) {
					dp[x] = min(dp[x], dp[x ^ (1 << c)] + 1 + (! subset(conns[c], x)));
				}
			}
		}
		res += dp[m];

		// cerr << m << ": " << dp[m] << endl;
		// for (int x : ord) cerr << x << ' '; cerr << endl;
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}