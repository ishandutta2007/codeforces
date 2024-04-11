#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9 + 7;

const int N = 2 * (int)1e5;
int dp[N][2]; // 0 decreasing, 1 increasing

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	dp[0][0] = -1;
	dp[0][1] = INF;
	for (int i = 1; i < n; ++i) {
		// Previous state is either (v[i-1], dp[i-1][0]) or (dp[i-1][1], v[i-1])
		dp[i][0] = INF;
		dp[i][1] = -1;

		if (dp[i-1][0] < v[i]) {
			dp[i][1] = max(dp[i][1], v[i-1]);
		}
		if (v[i-1] < v[i]) {
			dp[i][1] = max(dp[i][1], dp[i-1][1]);
		}

		if (dp[i-1][1] > v[i]) {
			dp[i][0] = min(dp[i][0], v[i-1]);
		}
		if (v[i-1] > v[i]) {
			dp[i][0] = min(dp[i][0], dp[i-1][0]);
		}
	}

	bool fail = false;
	string res(n, '_');
	if (dp[n-1][0] >= INF && dp[n-1][1] <= -1) {
		fail = true;
	} else {
		int v0 = -1;
		int v1 = INF;
		for (int i = n-1; i >= 0; --i) {
			if ((v[i] > v0) && (dp[i][0] < v1)) {
				v0 = v[i];
				res[i] = '1';
			} else if ((v[i] < v1) && (dp[i][1] > v0)) {
				v1 = v[i];
				res[i] = '0';
			} else {
				fail = true;
			}
		}
	}
	if (fail) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (int i = 0; i < n; ++i) cout << res[i] << ' '; cout << '\n';
	}
}