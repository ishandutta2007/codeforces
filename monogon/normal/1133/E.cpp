
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int n, k;
long long a[5000];
int dp[5001][5001];

int calc(int N, int K) {
	if(N <= K) return N;
	if(K == 0) return 0;
	if(dp[N][K] != -1) {
		return dp[N][K];
	}
	auto it = lower_bound(a, a + N, a[N - 1] - 5);
	return (dp[N][K] = max((a + N - it) + calc(it - a, K - 1), calc(N - 1, K)));
}

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= k; j++) {
			dp[i][j] = -1;
		}
	}
	cout << calc(n, k) << endl;
}