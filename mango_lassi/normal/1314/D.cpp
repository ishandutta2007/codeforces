#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1e18;

// rand-function that works properly on windows, and is faster than rand
// https://codeforces.com/blog/entry/61587
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand(T a, T b) {
	return uniform_int_distribution<T>(a, b)(rng);
}

const int M = 10000; // (1 - (1 - 2^-K)^M)^100 >= 0.98
const int N = 80;
const int K = 10;
int dist[N][N];
int par[N];
ll dp[N][K+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> dist[i][j];
		}
	}
	

	ll res = INF;
	for (int it = 0; it < M; ++it) {
		vector<int> parity[2] = {{}, {}};
		for (int i = 0; i < n; ++i) {
			if (i > 0) par[i] = rand(0, 1);
			parity[par[i]].push_back(i);
			for (int j = 0; j <= k; ++j) dp[i][j] = INF;
		}
		dp[0][0] = 0;
		
		for (int j = 1; j <= k; ++j) {
			for (int i : parity[1 ^ (j & 1)]) {
				for (int t : parity[j & 1]) {
					dp[t][j] = min(dp[t][j], dp[i][j-1] + dist[i][t]);
				}
			}
		}
		res = min(res, dp[0][k]);
	}
	cout << res << '\n';
}