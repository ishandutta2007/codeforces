#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int a[110][110];
vector<int> ans;
vector<pii> rows;
int main() {
	int n, m;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	int last_sum = 0;
	for (int i = 1; i <= n; i++)
		last_sum += a[i][m];
	for (int i = 1; i <= n; i++)
		ans.push_back(i);
	for (int i = 1; i < m; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++)
			sum += a[j][i];
		if (sum >= last_sum) {
			ans.clear();
			break;
		}
		int d = last_sum - sum;
		rows.clear();
		for (int j = 1; j <= n; j++)
			rows.push_back(pii(a[j][i] - a[j][m], j));
		sort(rows.begin(), rows.end());
		int num = -1;
		for (int i = 0; i < (int)rows.size(); i++) {
			if (rows[i].first > 0) break;
			d += rows[i].first;
			if (d <= 0) {
				num = i + 1;
				break;
			}
		}
		if (num != -1 && (num < (int)ans.size())) {
			ans.clear();
			for (int i = 0; i < num; i++)
				ans.push_back(rows[i].second);
		}
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); i++)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}