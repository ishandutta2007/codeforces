#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;



vector <pair<int, int> > ans;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	scanf("%d%d", &n, &k);
	if (double(k) > double(n - 1) / 2.)
	{
		printf("-1");
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j <= i + k; j++)
		{
			int cj = j % n;
			ans.push_back(make_pair(i, cj) );
		}
	}
	printf("%d\n", ans.size() );
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
	}


	return 0;
}