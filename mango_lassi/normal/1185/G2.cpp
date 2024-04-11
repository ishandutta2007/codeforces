#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int T = 2500;
const int K = 17 + 1; // 17*3 = 51
ll dp[K*K*K][T+1];
ll dp2[K*K*K][4];
int cou[3];

int enc(const vector<int>& val) {
	return val[0] + cou[0] * (val[1] + cou[1] * val[2]);
}
vector<int> dec(int v) {
	int a = v % cou[0];
	int b = (v / cou[0]) % cou[1];
	int c = (v / cou[0]) / cou[1];
	return {a, b, c};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, tt;
	cin >> n >> tt;

	vector<pair<int, int>> songs(n);
	for (int i = 0; i < n; ++i) {
		int t, g;
		cin >> t >> g;
		--g;
		++cou[g];
		songs[i] = {t, g};
	}
	for (int j = 0; j < 3; ++j) ++cou[j];
	int mm = cou[0] * cou[1] * cou[2];

	dp[0][0] = 1;
	for (int j = 0; j < n; ++j) {
		int t = songs[j].first;
		int g = songs[j].second;
		for (int mask = mm-1; mask >= 0; --mask) {
			vector<int> cur = dec(mask);
			vector<int> tar = cur;
			++tar[g];
			if (tar[g] >= cou[g]) continue;
			int t_mask = enc(tar);

			for (int ct = tt - t; ct >= 0; --ct) {
				dp[t_mask][ct + t] = (dp[t_mask][ct + t] + dp[mask][ct]) % MOD;
			}
		}
	}
	for (int j = 0; j < 4; ++j) dp2[0][j] = 1;
	for (int mask = 1; mask < mm; ++mask) {
		vector<int> cur = dec(mask);
		for (int b = 0; b < 3; ++b) {
			if (cur[b] == 0) continue;
			ll mult = cur[b];
			vector<int> tar = cur;
			--tar[b];
			int t_mask = enc(tar);

			for (int a = 0; a < 4; ++a) {
				if (b == a) continue;
				dp2[mask][a] = (dp2[mask][a] + mult * dp2[t_mask][b]) % MOD;
			}
		}
	}

	ll res = 0;
	for (int mask = 0; mask < mm; ++mask) {
		res = (res + dp2[mask][3] * dp[mask][tt]) % MOD;
	}
	cout << res << '\n';
}