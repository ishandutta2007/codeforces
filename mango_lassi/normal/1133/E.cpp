#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int INF = 1e9 + 7;
const int K = 5000;
const int V = 5;
const int R = V + 2;
int dp[R][K+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> vals(n);
	for (int i = 0; i < n; ++i) cin >> vals[i];
	sort(vals.begin(), vals.end());

	vals.push_back(-1);
	int j = 0;
	vector<pair<int, int>> cou;
	for (int i = 0; i <= n; ++i) {
		if (vals[i] != vals[j]) {
			cou.push_back({vals[j], i-j});
			j = i;
		}
	}

	j = 0;
	int res = 0;
	for (int ii = 0; ii < cou.size(); ++ii) {
		int jj = ii;
		while(jj > 0 && cou[jj-1].first >= cou[ii].first - V) --jj;
		--jj;
		
		int sum = 0;
		for (int i = jj+1; i <= ii; ++i) sum += cou[i].second;

		int d = ii - jj;
		int p = (j - (ii - jj) + R) % R;
		int pp = (j - 1 + R) % R;
		
		// cout << ii << ' ' << jj << ' ' << j << ' ' << p << ' ' << sum << endl;

		for (int i = 1; i <= k; ++i) {
			dp[j][i] = max(dp[p][i-1] + sum, dp[pp][i]);
			res = max(res, dp[j][i]);
		}
		j = (j + 1) % R;
	}

	cout << res << '\n';
}