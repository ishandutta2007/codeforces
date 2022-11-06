#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[400010], nxt[400010], bef[400010];
set <pair<int, int> > S;
int ans;

int main()
{
	fill(bef, bef + 400010, 400010);
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i ++)
		scanf("%d", &a[i]);
	for (int i = n - 1; i >= 0; i --)
		nxt[i] = bef[a[i]], bef[a[i]] = i;

	for (int i = 0; i < n; i ++)
	{
		if (S.find(make_pair(i, a[i])) == S.end())
		{
			ans ++;
			if (S.size() >= k)
			{
				set <pair<int, int> >::iterator it = S.end();
				it --;
				S.erase(it);
			}
		}
		S.erase(make_pair(i, a[i]));
		S.insert(make_pair(nxt[i], a[i]));
	}
	printf("%d", ans);
	return 0;
}