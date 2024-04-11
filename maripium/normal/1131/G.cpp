#include <bits/stdc++.h>

using namespace std;

const int N = 250250;
const int M = 10100100;

vector<pair<int,int>> val[N];
int h[M];
long long cost[M], dp[M], f[M];
int l[M], r[M];

void upd(int p,long long val) {
	for (; p > 0; p -= p & -p) {
		f[p] = min(f[p], val);
	}
}

long long get(int p) {
	long long ans = 1e18;
	for (; p < M; p += p & -p) {
		ans = min(ans, f[p]);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int n, m;
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		val[i].resize(k);
		for (int j = 0; j < k; ++j) {
			cin >> val[i][j].first;
		}
		for (int j = 0; j < k; ++j) {
			cin >> val[i][j].second;
		}
	}
	
	int q; 
	
	cin >> q;
	int now = 0;
	while (q--) {
		int id, mul;
		
		cin >> id >> mul;
		
		for (auto v : val[id]) {
			++now;
			h[now] = v.first;
			cost[now] = (long long) v.second * mul;
		}
	}
	
	assert(now == m);
	fill(f, f + M, 1e18);
	
	for (int i = 1; i <= m; ++i) {
		l[i] = i - 1;
		while (l[i] > 0 && h[i] > i - l[i]) {
			l[i] = l[l[i]];
		}
	} 
	
	for (int i = m; i > 0; --i) {
		r[i] = i + 1;
		while (r[i] <= m && h[i] > r[i] - i) {
			r[i] = r[r[i]];
		}
	}
	
	for (int i = 1; i <= m; ++i) {
		dp[i] = min(dp[l[i]] + cost[i], get(i));
		upd(r[i] - 1, dp[i - 1] + cost[i]);
	} 
	
	cout << dp[m] << '\n';
}