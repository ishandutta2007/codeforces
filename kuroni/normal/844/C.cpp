#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, i, j, a[100005], b[100005];
vector < vector <int> > ans;
bool chk[100005];

inline bool cmp(const int &x, const int &y)
{
	return a[x] < a[y];
}

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		b[i] = i;
	}
	sort(b + 1, b + n + 1, cmp);
	for (i = 1; i <= n; i++)
		if (chk[i] == false)
		{
			j = i;
			ans.push_back({});
			do
			{
				chk[j] = true;
				ans.back().push_back(j);
				j = b[j];
			} while (j != i);
		}
	printf("%d\n", ans.size());
	for (i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i].size());
		for (j = 0; j < ans[i].size(); j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
}