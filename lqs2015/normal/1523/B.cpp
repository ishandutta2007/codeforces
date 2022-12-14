#include <bits/stdc++.h>
using namespace std;
int test, n, a[1111];
vector<pair<int, pair<int, int> > > ans;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		ans.clear();
		for (int i = 1; i <= n; i += 2)
		{
			ans.push_back(make_pair(2, make_pair(i, i + 1)));
			ans.push_back(make_pair(1, make_pair(i, i + 1)));
			ans.push_back(make_pair(1, make_pair(i, i + 1)));
			ans.push_back(make_pair(2, make_pair(i, i + 1)));
			ans.push_back(make_pair(1, make_pair(i, i + 1)));
			ans.push_back(make_pair(1, make_pair(i, i + 1)));
		}
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < ans.size(); i++)
		{
			printf("%d %d %d\n", ans[i].first, ans[i].second.first, ans[i].second.second);
		}
	}
	return 0;
}