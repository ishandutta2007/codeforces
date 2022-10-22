#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;

int n;
vector <int> seq[Maxn];
int a[Maxn];
int st[Maxn], hm[Maxn];
int dp[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		seq[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) 
		if (!seq[i].empty()) {
			st[seq[i].back()] = seq[i][0];
			hm[seq[i].back()] = seq[i].size();
		}
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (st[i] > 0) {
			dp[i] = max(dp[i], dp[st[i] - 1] + hm[i]);
			int my = a[i];
			for (int j = 0; j < seq[my].size(); j++)
				res = max(res, dp[seq[my][j] - 1] + int(seq[my].size()) - j);
		}
	}
	printf("%d\n", n - res);
    return 0;
}