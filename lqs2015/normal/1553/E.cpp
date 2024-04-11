#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n, m, p[333333], a[333333], num[333333], b[333333], res;
vector<int> ans;
bool used[333333];
bool can(int x)
{
	for (int i = 1; i <= x; i++) b[i] = a[n - x + i];
	for (int i = x + 1; i <= n; i++) b[i] = a[i - x];
	for (int i = 1; i <= n; i++) used[i] = 0;
	res = n;
	for (int i = 1; i <= n; i++)
	{
		if (!used[i])
		{
			res --;
			for (int j = i; !used[j]; j = b[j])
			{
				used[j] = 1;
			}
		}
	}
	return (res <= m);
}
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
		for (int i = 1; i <= n; i++) a[p[i]] = i;
		for (int i = 0; i < n; i++) num[i] = 0;
		for (int i = 1; i <= n; i++)
		{
			num[(a[i] - i + n) % n] ++;
		}
		ans.clear();
		for (int i = 0; i < n; i++)
		{
			if (n - num[i] - (n - num[i]) / 2 > m) continue;
			if (can(i)) ans.push_back(i);
		}
		printf("%d ", (int)ans.size());
		for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
		printf("\n");
	}
	return Accepted;
}