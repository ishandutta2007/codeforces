#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 1e18;

const int N = 20;
const int M = 1 << N;
ll cost[N][M];
ll dp[M];
int cou[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		--a;
		
		++cou[a];
		for (int c = 0; c < N; ++c) {
			if (c == a) continue;
			cost[a][1 << c] += cou[c];
		}
	}
	for (int c = 0; c < N; ++c) {
		for (int m = 0; m < M; ++m) {
			int b = m - (m & (m-1));
			cost[c][m] = cost[c][m ^ b] + cost[c][b];
		}
	}
	for (int m = 1; m < M; ++m) {
		dp[m] = INF;
		for (int c = 0; c < N; ++c) {
			if (m & (1<<c)) {
				dp[m] = min(dp[m], dp[m ^ (1<<c)] + cost[c][m]);
			}
		}
	}

	cout << dp[M - 1] << '\n';
}