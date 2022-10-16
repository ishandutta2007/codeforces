#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


void work() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector <pair <LL, int>> ans;
	for (int i = 1; i <= n; i++) {
		LL sum = 0, sumsum = 0;
		for (int j = 1; j <= m; j++) {
			int x;
			scanf("%d", &x);
			sum += x;
			sumsum += sum;
		}
		ans.push_back(make_pair(sumsum, i));
	}
	sort(ans.begin(), ans.end());
	printf("%d %lld\n", ans[0].second, ans[1].first - ans[0].first);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) work();
}