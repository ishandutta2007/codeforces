#include <bits/stdc++.h>
using namespace std;
int test, n, a[1111], fa[1111];
vector<int> ans[1111];
bool used[1111];
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		memset(used, 0, sizeof(used));
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 1)
			{
				fa[i] = i - 1;
			}
			else
			{
				fa[i] = 0;
				for (int j = i - 1; j >= 1; j--)
				{
					if (a[j] == a[i] - 1 && !used[j]) 
					{
						fa[i] = j;
						used[j] = 1;
						break;
					}
					used[j] = 1;
				}
			}
		}
		for (int i = 1; i <= n; i++) ans[i].clear();
		for (int i = 1; i <= n; i++)
		{
			if (!fa[i]) ans[i].push_back(1);
			else
			{
				ans[i] = ans[fa[i]];
				if (a[i] == 1) ans[i].push_back(1);
				else ans[i].back() ++;
			}
			for (int j = 0; j < ans[i].size(); j++)
			{
				printf("%d", ans[i][j]);
				if (ans[i].size() != j + 1) printf(".");
				else printf("\n");
			}
		}
	}
	return 0;
}