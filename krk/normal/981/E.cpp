#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 10005;

int n, q;
int dp[Maxn];
iii quer[Maxn];

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 0; i < q; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		quer[i] = iii(ii(a, b), c);
	}
	sort(quer, quer + q);
	dp[0] = n;
	for (int i = 0; i < q; i++)
		for (int j = n - quer[i].second; j >= 0; j--) if (dp[j] >= quer[i].first.first) {
			int nxt = min(dp[j], quer[i].first.second);
			int nj = j + quer[i].second;
			dp[nj] = max(dp[nj], nxt);
		}
	vector <int> res;
	for (int i = 1; i <= n; i++)
		if (dp[i] > 0) res.push_back(i);
	printf("%d\n", int(res.size()));
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}