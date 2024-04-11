#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

template<class T>
void setmin(T &a, T b) {
	if (a > b)
		a = b;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;
	int cnt = accumulate(a.begin(), a.end(), 0);
	int sum = n - cnt;
	vector<int> b;
	{
		int now = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 0)
				now++;
			else {
				b.push_back(now);
				now = 0;	
			}
		}
		b.push_back(now);
	}
	int n_queries = n * (n - 1) / 2;
	if (cnt == 0 || cnt == n) {
		for (int i = 0; i <= n_queries; i++)
			cout << 0 << ' ';
		cout << '\n';
		return 0;
	}
	n = (int) b.size();
	vector<int> pref(n + 1, 0);
	for (int i = 0; i < n; i++)
		pref[i + 1] = pref[i] + b[i];
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(sum + 1, vector<int>(n_queries + 1, INF)));
	dp[0][0][0] = 0;
	b.insert(b.begin(), 0);
	for (int i = 1; i <= n; i++)
		for (int s = 0; s <= sum; s++)
			for (int k = 0; k <= n_queries; k++)
				if (dp[i - 1][s][k] != INF)
					for (int j = s; j <= sum; j++)
						setmin(dp[i][j][abs(j - pref[i]) + k], dp[i - 1][s][k] + (j - s) * (j - s));

	{
		for (int i = 1; i <= n_queries; i++)
			setmin(dp.back().back()[i], dp.back().back()[i - 1]);
		for (int i = 0; i <= n_queries; i++) 
			cout << (sum * sum - dp.back().back()[i]) / 2 << ' ';
		cout << '\n';
	}
}