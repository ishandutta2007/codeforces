#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
bool dp[100005][5];
vector<int> ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == 0) dp[i][j] = 1;
			else {
				if (a[i] > a[i - 1]) {
					for (int k = 0; k < j; k++) {
						dp[i][j] |= dp[i - 1][k];
					}
				} else if (a[i] < a[i - 1]) {
					for (int k = j + 1; k < 5; k++) {
						dp[i][j] |= dp[i - 1][k];
					}
				} else {
					for (int k = 0; k < 5; k++) {
						if (k != j) dp[i][j] |= dp[i - 1][k];
					}
				}
			}
		}
	}
	int pos = -1;
	for (int i = 0; i < 5; i++) {
		if (dp[n - 1][i]) {
			pos = i;
			break;
		}
	}
	if (pos == -1) {
		printf("-1\n");
		return 0;
	}
	ans.push_back(pos);
	for (int i = n - 1; i > 0; i--) {
		int npos = -1;
		if (a[i] > a[i - 1]) {
			for (int k = 0; k < pos; k++) {
				if (dp[i - 1][k]) {
					npos = k;
					break;
				}
			}
		} else if (a[i] < a[i - 1]) {
			for (int k = pos + 1; k < 5; k++) {
				if (dp[i - 1][k]) {
					npos = k;
					break;
				}
			}
		} else {
			for (int k = 0; k < 5; k++) {
				if (k == pos) continue;
				if (dp[i - 1][k]) {
					npos = k;
					break;
				}
			}
		}
		pos = npos;
		ans.push_back(pos);
	}
	for (int i = n - 1; i >= 0; i--) printf("%d ", ans[i] + 1);
	printf("\n");
	return 0;
}