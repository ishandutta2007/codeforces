#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int INF = 1e9 + 7;
const int D = 500;
const int S = 5000;
int dp[D][S + 1];
pair<int, pair<int, int>> pr[D][S + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int d, s;
	cin >> d >> s;

	for (int a = 0; a < d; ++a) {
		for (int b = 0; b <= s; ++b) dp[a][b] = INF;
	}

	vector<pair<int, int>> que;
	dp[0][0] = 0;
	que.push_back({0, 0});
	for (int i = 0; i < que.size(); ++i) {
		int cd = que[i].first;
		int cs = que[i].second;
		if (cd == 0 && cs == s) break;

		int cc = dp[cd][cs];
		for (int j = 0; j < 10; ++j) {
			int td = (cd * 10 + j) % d;
			int ts = cs + j;
			if (ts > s) break;
			if (dp[td][ts] > cc + 1) {
				dp[td][ts] = cc + 1;
				pr[td][ts] = {j, {cd, cs}};
				que.push_back({td, ts});
			}
		}
	}

	if (dp[0][s] != INF) {
		int len = dp[0][s];
		string res (len, '?');
		pair<int, int> cur = {0, s};
		for (int i = len-1; i >= 0; --i) {
			auto pref = pr[cur.first][cur.second];
			res[i] = '0' + pref.first;
			cur = pref.second;
		}
		cout << res << '\n';
	} else {
		cout << "-1\n";
	}
}