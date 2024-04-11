#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long lint;
const lint inf = 1000000000000000;

int main() {
	//freopen("input.txt", "r", stdin);
	int n = 5000, m = 100, k = 50;
	cin >> n >> m >> k;
	vector<lint> init(n);
	for (int i = 0; i < n; i++)
		cin >> init[i];
		//init[i] = 1000000000;

	vector<lint> sums (n - m + 1, 0);
	for (int i = 0; i < m; i++)
		sums[0] += init[i];
	for (int i = 1; i < sums.size(); i++)
		sums[i] = sums[i - 1] + init[i + m - 1] - init[i - 1];

	vector<vector<lint> > dp(sums.size(), vector<lint>(k));
	for (int i = 0; i < dp.size(); i++)
		for (int j = 0; j < k; j++) {
			if (j == 0)
				dp[i][j] = max(sums[i], i == 0 ? -inf : dp[i - 1][0]);
			else
				if (i - m < 0)
					dp[i][j] = -inf;
				else
					dp[i][j] = max(dp[i - m][j - 1] + sums[i], dp[i - 1][j]);
		}

	cout << dp[dp.size() - 1][k - 1];
	return 0;
}