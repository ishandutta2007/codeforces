#include <bits/stdc++.h>
using namespace std;

#define N 1000005

void Max(int &a, int b) {
	a = max(a, b);
}

int n, m, ans;
int a[N], b[N];
int dp[N][3][3];


int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) scanf("%d", a +i), b[a[i]]++;
	memset(dp, 200, sizeof dp);
	dp[0][0][0] = 0;
	n = m;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) if (dp[i][j][k] >= 0) {
				for (int l = 0; l < 3; l++) if (b[i] >= j + k + l) {
					Max(dp[i + 1][k][l], dp[i][j][k] + (b[i] - j - k - l) / 3 + l);
				}
			}
		}
	}
	cout << ans + dp[n + 1][0][0] << endl;
}