#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
int a[Maxn];
int dp[Maxn];
vector <int> seq[Maxn];

int main()
{
	scanf("%d", &n);
	seq[0].push_back(0);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (dp[i - 1] + (a[i] != a[i - 1]) > dp[i]) {
			dp[i] = dp[i - 1] + (a[i] != a[i - 1]);
			seq[i].clear();
		}
		if (dp[i - 1] + (a[i] != a[i - 1]) == dp[i]) {
			for (int j = 0; j < seq[i - 1].size(); j++)
				seq[i].push_back(seq[i - 1][j]);
		}
		for (int j = 0; j < seq[i - 1].size(); j++) {
			if (dp[i - 1] + (a[i] != seq[i - 1][j]) > dp[i]) {
				dp[i] = dp[i - 1] + (a[i] != seq[i - 1][j]);
				seq[i].clear();
			}
			if (dp[i - 1] + (a[i] != seq[i - 1][j]) == dp[i])
				seq[i].push_back(a[i - 1]);
		}
		sort(seq[i].begin(), seq[i].end()); seq[i].erase(unique(seq[i].begin(), seq[i].end()), seq[i].end());
		while (seq[i].size() > 3) seq[i].pop_back();
	}
	printf("%d\n", dp[n]);
    return 0;
}