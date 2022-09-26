#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;
const int K = 5e3 + 3;
const int INF = 4e9;
 
int k, n;
int t[N], a[N];
vector<pair<int,int> > z;
vector<int> id; 
int dp[2][K][2];

void minimize(int &x,int y) {
	if (y < x) x = y;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	cin >> k >> n;
	for (int i = 1;i <= n;++i) cin >> t[i];
	sort(t + 1,t + n + 1);
	for (int i = 1; i <= n - 1; ++i) z.push_back(make_pair(t[i + 1] - t[i], i));
	sort(z.begin(), z.end());

	for (int i = 0; i < min((int)z.size(), k << 2); ++i) {
		id.push_back(z[i].second);
		id.push_back(z[i].second + 1);
	}

	sort(id.begin(), id.end());
	id.resize(unique(id.begin(), id.end()) - id.begin());
	
	n = 0;
	for (int i = 0;i < id.size();++i) a[++n] = t[id[i]];
	
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j <= min(n >> 1, k); ++j) {
			for (int last = 0; last < 2; ++last) {
				dp[i][j][last] = INF;
			}
		}
	}

	dp[0][0][0] = 0;
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= min(i >> 1, k); ++j) {
			for (int last = 0; last < 2; ++last) {
				if (dp[0][j][last] == INF) continue;

				for (int chosen = 0; chosen < 2; ++chosen) {
					if (last && chosen) continue;
					minimize(dp[1][j + chosen][chosen], dp[0][j][last] + (chosen ? (a[i] - a[i - 1]) : 0));
				}
			}
		}

		for (int j = 0; j <= min(i >> 1, k); ++j) for (int last = 0; last < 2; ++last) {
			dp[0][j][last] = dp[1][j][last];
			dp[1][j][last] = INF;
		}
	}
	
	cout << min(dp[0][k][0], dp[0][k][1]) << endl;
}