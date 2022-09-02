#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

const int N = 1e5;
const int K = 200;
ll dp[2][K+1][2];
ll pref[K+2];
ll suf[K+2];

int vals[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> vals[i];
	for (int v = 1; v <= K; ++v) {
		dp[0][v][0] = 1;
		if (vals[0] != -1 && vals[0] != v) dp[0][v][0] = 0;
	}
	for (int i = 1; i < n; ++i) {
		int c = (i & 1);
		int p = c ^ 1;

		pref[0] = 0;
		for (int v = 1; v <= K; ++v) {
			pref[v] = (pref[v-1] + dp[p][v][0] + dp[p][v][1]) % MOD;
		}

		suf[K+1] = 0;
		for (int v = K; v >= 1; --v) {
			suf[v] = (suf[v+1] + dp[p][v][1]) % MOD;
		}
		for (int v = 1; v <= K; ++v) {
			suf[v] = (suf[v] + dp[p][v][0]) % MOD;
		}

		for (int v = 1; v <= K; ++v) {
			if (vals[i] != -1 && vals[i] != v) {
				dp[c][v][0] = 0;
				dp[c][v][1] = 0;
			} else {
				dp[c][v][0] = pref[v-1];
				dp[c][v][1] = suf[v];
			}
		}
	}

	ll res = 0;
	for (int v = 1; v <= K; ++v) {
		res = (res + dp[(n-1) % 2][v][1]) % MOD;
	}
	cout << res << '\n';
}