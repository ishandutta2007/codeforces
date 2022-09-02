#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 1e5;
ll twop[N+1];
ll dp[N+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	twop[0] = 1;
	for (int i = 1; i <= N; ++i) twop[i] = (twop[i-1] * 2) % MOD;

	dp[0] = 1; // _
	dp[1] = 2; // 0, 1
	dp[2] = 4; // 00, 01, 10, 11
	for (int i = 3; i <= N; ++i) {
		dp[i] = (dp[i-1] + dp[i-2]) % MOD;
	}

	int w, h;
	cin >> w >> h;

	ll res = 0;
	res += dp[h] + dp[w] - 2;
	res %= MOD;
	cout << res << '\n';
}