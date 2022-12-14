#include <bits/stdc++.h>
using namespace std;
int n, a[222222], dp[222222], mn[222222], cnt[222222];
vector<int> pos[222222];
multiset<int> s;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		cnt[a[i]] ++;
		pos[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) mn[i] = 1e9;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		dp[i] = min(dp[i], mn[a[i]] + 2);
		s.insert(dp[i - 1]);
		cnt[a[i]] --;
		if (!cnt[a[i]])
		{
			for (int j = 0; j < pos[a[i]].size(); j++) s.erase(s.find(dp[pos[a[i]][j] - 1]));
		}
		if (!s.empty()) dp[i] = min(dp[i], *s.begin() + 1);
		mn[a[i]] = min(mn[a[i]], dp[i - 1]);
	}
//	for (int i = 1 ; i <= n; i++) cout << dp[i] << " ";
//	cout << endl;
	printf("%d\n", n - dp[n]);
	return 0;
}