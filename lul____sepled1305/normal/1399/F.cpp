/** I want to know kow fast official sol is with fast I/O **/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> rg;
vector<vector<int>> dp;

int calc(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	dp[l][r] = 0;
	if (l > r) return dp[l][r];
	bool add = count(rg[l].begin(), rg[l].end(), r); // can't be greater than 1
	dp[l][r] = max(dp[l][r], add + (l + 1 > r ? 0 : calc(l + 1, r)));
	for (auto nr : rg[l]) {
		if (nr >= r) continue;
		dp[l][r] = max(dp[l][r], add + calc(l, nr) + (nr + 1 > r ? 0 : calc(nr + 1, r)));
	}
	return dp[l][r];
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> l(n), r(n);
		vector<int> val;
		for (int i = 0; i < n; ++i) {
			cin >> l[i] >> r[i];
			val.push_back(l[i]);
			val.push_back(r[i]);
		}
		sort(val.begin(), val.end());
		val.resize(unique(val.begin(), val.end()) - val.begin());
		for (int i = 0; i < n; ++i) {
			l[i] = lower_bound(val.begin(), val.end(), l[i]) - val.begin();
			r[i] = lower_bound(val.begin(), val.end(), r[i]) - val.begin();
		}
		int siz = val.size();
		dp = vector<vector<int>>(siz, vector<int>(siz, -1));
		rg = vector<vector<int>>(siz);
		for (int i = 0; i < n; ++i) {
			rg[l[i]].push_back(r[i]);
		}
		cout << calc(0, siz - 1) << endl;
	}
	
	return 0;
}