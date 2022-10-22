#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char str[1010 * 1010], ans[1010][1010];
int main() {
	int n, l, k;
	scanf("%d%d%d%s", &n, &l, &k, str + 1);
	sort(str + 1, str + 1 + n * l);
	int cur = 1, idx = 1;
	for (int j = 1; j <= l && cur < k; j++) {
		for (int i = cur; i <= k; i++)
			ans[i][j] = str[idx++];
		while (cur < k && ans[cur][j] < ans[k][j]) cur++;
	}
	for (int j = 1; j <= l; j++)
		if (!ans[k][j])
			ans[k][j] = str[idx++];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= l; j++) {
			if (!ans[i][j]) {
				if (i < k) ans[i][j] = str[idx++];
				else ans[i][j] = str[idx++];
			}
			putchar(ans[i][j]);
		}
		putchar('\n');
	}
	return 0;
}