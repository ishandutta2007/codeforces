#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (int)1e9 + 7;

ll query(vector<int> inds) {
	sort(inds.begin(), inds.end());

	cout << "?";
	for (auto i : inds) cout << " " << i+1;
	cout << endl;

	ll res;
	cin >> res;
	return res;
}

void answer(ll res) {
	cout << "! " << res << endl;
}

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> dp(n+1, INF);
	vector<pair<int, int>> nxt(n+1, make_pair(-1, -1));
	
	dp[n] = 0;
	vector<int> que = {n};
	for (int ind = 0; ind < que.size(); ++ind) {
		int m = que[ind];

		// a: amount ACTIVE
		// b: amount INACTIVE
		for (int a = 0; a <= min(k, m); ++a) {
			int b = k-a;
			if (b > n-m) continue;
			
			int t = m - a + b;
			if (dp[t] > dp[m] + 1) {
				dp[t] = dp[m];
				nxt[t] = {b, a};
				que.push_back(t);
			}
		}
	}

	if (dp[0] == INF) {
		cout << -1 << endl;
		return;
	}

	ll res = 0;
	vector<bool> act(n, 0);
	int m = 0;

	while(m < n) {
		int a = nxt[m].first;
		int b = nxt[m].second;

		// cerr << m << ' ' << a << ' ' << b << ": ";
		// for (int i = 0; i < n; ++i) cerr << act[i]; cerr << endl;

		m = m - a + b;
		vector<int> inds;
		for (int i = 0; i < n; ++i) {
			if (a > 0 && act[i]) {
				inds.push_back(i);
				--a;
			} else if (b > 0 && !act[i]) {
				inds.push_back(i);
				--b;
			}
		}
		for (int i : inds) act[i] = !act[i];
		res ^= query(inds);
	}
	answer(res);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}