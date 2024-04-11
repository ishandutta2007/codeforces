#include <bits/stdc++.h>

using namespace std;

bool dp[105][105][2];

void prepare() {
	dp[0][0][0] = true;
	for (int i = 0; i <= 100; ++i) {
		for (int j = 0; j <= 100; ++j) {
			for (int k = 0; k < 2; ++k) {
				if (i) {
					// take even
					if (!dp[i - 1][j][k ^ (j & 1) ^ 1]) {
						dp[i][j][k] = true;
					}
				} 
				if (j) {
					// take odd
					if (!dp[i][j - 1][k ^ (j & 1) ^ 1]) {
						dp[i][j][k] = true;
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	prepare();
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (int &a : A) cin >> a;
		int i = 0;
		int j = 0;
		for (int a : A) {
			if (a % 2) j++;
			else i++;
		}
		if (dp[i][j][0]) {
			cout << "Alice\n";
		} else {
			cout << "Bob\n";
		}
	}
	return 0;
}