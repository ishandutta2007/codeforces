#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long ll;
const int K = 76;
const int N = 4000;
const int MOD = 998244353;

int dp[2][3 * N][K]; // Number of ways to move k times in subtree of i, and return to i
int choose[K+1][K+1]; // A choose B
ll tot[2][K];
int siz[2];

vector<int> conns[2][N];
vector<pair<int, int>> vec[2];

int getInd(int j, pair<int, int> pr) {
	int low = 0;
	int high = (int)vec[j].size() - 1;
	while (low != high) {
		int mid = (low + high) >> 1;
		if (vec[j][mid] < pr) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}
	return low;
}

void solve(int j, int i, int k) {
	for (int spend_k = 0; spend_k < k; spend_k += 2) {
		ll sum = 0;
		for (auto t : conns[j][i]) {
			int ti = getInd(j, {t, i});
			sum += dp[j][ti][spend_k];
		}
		sum %= MOD;
		
		int ind = getInd(j, {i, i});
		dp[j][ind][k] = (dp[j][ind][k] + dp[j][ind][k-2-spend_k] * sum) % MOD;

		for (auto t : conns[j][i]) {
			int ti = getInd(j, {t,i});
			int it = getInd(j, {i,t});
			sum -= dp[j][ti][spend_k];
			if (sum < 0) sum += MOD;
			dp[j][it][k] = (dp[j][it][k] + dp[j][it][k-2-spend_k] * sum) % MOD;
			sum += dp[j][ti][spend_k];
			if (sum >= MOD) sum -= MOD;
		}
	}
}

int main() {
	choose[0][0] = 1;
	for (int cou = 1; cou <= K; ++cou) {
		choose[cou][0] = 1;
		for (int pick = 1; pick <= cou; ++pick) {
			choose[cou][pick] = (choose[cou-1][pick] + choose[cou-1][pick-1]) % MOD;
		}
	}

	int need_k;
	cin >> siz[0] >> siz[1] >> need_k;

	for (int j = 0; j < 2; ++j) {
		for (int i = 0; i < siz[j] - 1; ++i) {
			int a, b;
			cin >> a >> b;
			--a; --b;
			conns[j][a].push_back(b);
			conns[j][b].push_back(a);
		}

		vec[j].reserve(3*siz[j]);
		for (int i = 0; i < siz[j]; ++i) {
			vec[j].push_back({i,i});
			for (int ei = 0; ei < conns[j][i].size(); ++ei) {
				int t = conns[j][i][ei];
				vec[j].push_back({t, i});
			}
		}
		sort(vec[j].begin(), vec[j].end());

		// Base cases for dp
		for (int i = 0; i < vec[j].size(); ++i) {
			dp[j][i][0] = 1;
		}
		tot[j][0] = siz[j];

		for (int k = 2; k <= need_k; k += 2) {
			for (int i = 0; i < siz[j]; ++i) {
				solve(j, i, k);
				int ind = getInd(j, {i, i});
				tot[j][k] += dp[j][ind][k];
			}
			tot[j][k] %= MOD;
		}
	}

	ll ans = 0;
	for (int a = 0; a <= need_k; a += 2) {
		int b = need_k - a;
		ll mult = (tot[0][a] * tot[1][b]) % MOD;
		ans += (choose[need_k][a] * mult) % MOD;
	}
	ans %= MOD;
	std::cout << ans << '\n';
}