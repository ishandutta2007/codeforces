#include <bits/stdc++.h>
using namespace std;
int bit[222222], sz, test, n, pos[33], ps;
long long ans, cur;
char s[111111], t[111111];
vector<int> arr[33];
void update(int p)
{
	while(p <= sz)
	{
		bit[p] ++;
		p += p & (-p);
	}
}
int query(int p)
{
	int res = 0;
	while(p >= 1)
	{
		res += bit[p];
		p -= p & (-p);
	}
	return res;
}
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		scanf("%s%s", s, t);
		sz = 1;
		while(sz < n) sz <<= 1;
		for (int i = 0; i <= sz; i++) bit[i] = 0;
		ans = 1e18; cur = 0;
		for (int i = 0; i < 26; i++)
		{
			arr[i].clear();
			pos[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			arr[s[i] - 'a'].push_back(i + 1);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < t[i] - 'a'; j++)
			{
				if (pos[j] < arr[j].size())
				{
					ans = min(ans, cur + arr[j][pos[j]] - 1 - query(arr[j][pos[j]]));
				}
			}
			if (pos[t[i] - 'a'] >= arr[t[i] - 'a'].size()) break;
			ps = arr[t[i] - 'a'][pos[t[i] - 'a']];
			pos[t[i] - 'a'] ++;
			cur += (ps - 1 - query(ps));
			update(ps);
		}
		if (ans > 1e17) printf("-1\n");
		else printf("%lld\n", ans);
	}
	return 0;
}