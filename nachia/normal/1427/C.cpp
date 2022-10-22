#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int R;
int N;
int P[100001][3];
int dp[100001];
int dpmax[100001];

int main() {
	cin >> R >> N;
	
	P[0][0] = 0; P[0][1] = P[0][2] = 1;
	rep(i, N) rep(j, 3) cin >> P[i + 1][j];

	rep(i, N + 1) dp[i] = -1000000; dp[0] = 0;
	dpmax[0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = max(i - 1000, 0); j < i; j++)
			if (P[i][0] - P[j][0] >= abs(P[i][1] - P[j][1]) + abs(P[i][2] - P[j][2]))
				dp[i] = max(dp[i], dp[j] + 1);
		if (i >= 1000) dp[i] = max(dp[i], dpmax[i - 1000] + 1);
		dpmax[i] = max(dpmax[i - 1], dp[i]);
	}

	int ans = 0;
	rep(i, N + 1) ans = max(ans, dp[i]);
	cout << ans << endl;

	return 0;
}