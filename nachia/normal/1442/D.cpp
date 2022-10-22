#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N, K;
vector<vector<LL>> A;
LL dp[3001][3001];
LL ans;

void proc(int l, int r) {
	if (l + 1 == r) {
		LL tmp = 0;
		rep(i, A[l].size()) tmp = max(tmp, dp[1][K - i] + A[l][i]);
		ans = max(ans, tmp);
		return;
	}

	int m = (l + r) / 2;
	int z = r - l;

	for (int i = l; i < m; i++) {
		int k = A[i].size() - 1;
		LL a = A[i].back();
		for (int j = 0; j < k; j++) dp[z - 1][j] = dp[z][j];
		for (int j = k; j <= K; j++)
			dp[z - 1][j] = max(dp[z][j - k] + a, dp[z][j]);
		z--;
	}
	proc(m, r);

	z = r - l;
	for (int i = m; i < r; i++) {
		int k = A[i].size() - 1;
		LL a = A[i].back();
		for (int j = 0; j < k; j++) dp[z - 1][j] = dp[z][j];
		for (int j = k; j <= K; j++)
			dp[z - 1][j] = max(dp[z][j - k] + a, dp[z][j]);
		z--;
	}
	proc(l, m);
}

int main() {
	scanf("%d%d", &N, &K);
	A.resize(N);
	rep(i, N) {
		int t; scanf("%d", &t);
		A[i].resize(t + 1);
		rep(j, t) { int a; scanf("%d", &a); A[i][j + 1] = a; }
		A[i].resize(min((int)A[i].size(), K + 1));
		rep(j, A[i].size() - 1) A[i][j + 1] += A[i][j];
	}

	ans = 0;
	rep(i, 3001) dp[N][i] = 0;

	proc(0, N);
	cout << ans << endl;

	return 0;
}