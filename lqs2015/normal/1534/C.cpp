#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, test, p[444444], q[444444], r[444444], ans;
bool used[444444];
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &q[i]);
		for (int i = 1; i <= n; i++) r[p[i]] = i;
		for (int i = 1; i <= n; i++) q[i] = r[q[i]];
		ans = 1;
		for (int i = 1; i <= n; i++) used[i] = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!used[i])
			{
				ans = (ans + ans) % mod;
				for (int j = i; !used[j]; j = q[j]) used[j] = 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}