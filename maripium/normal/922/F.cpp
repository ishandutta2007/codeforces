#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n, k;
int d[N];
int rem;
bool dp[N][210];
bool np[N], del[N];
int pr[N], cnt;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		for (int j = i + i; j <= n; j += i) ++d[j];
	}

	for (int i = 1; i <= n; ++i) d[i] += d[i - 1];

	bool ok = false;
	for (int i = 1; i <= n; ++i) {
		if (d[i] >= k) {
			n = i;
			rem = d[i] - k;
			ok = true;
			break;
		}
	}

	if (!ok) return cout << "No\n", 0;

	np[0] = np[1] = 1;
	for (int i = 2; i <= n; ++i) if (!np[i]) {
		for (int j = i + i; j <= n; j += i) np[j] = 1;
		pr[++cnt] = i;
	}

	dp[0][0] = 1;
	for (int i = 1; i <= cnt; ++i) {
		int cur = n / pr[i];
		for (int j = 0; j <= rem; ++j) {
			dp[i][j] = dp[i - 1][j];
			if (j - cur >= 0) dp[i][j] += dp[i - 1][j - cur];
		}
	}

	while(cnt > 0) {
		if (dp[cnt - 1][rem]) --cnt;
		else rem -= n / pr[cnt], del[pr[cnt]] = true, --cnt;
	}
	
	vector<int> ans;
	for (int i = 1; i <= n; ++i) if (!del[i]) ans.push_back(i);
	cout << "Yes\n" << ans.size() << endl;
	for (int i = 0;i < ans.size();++i) cout << ans[i] << ' '; cout << endl;
}