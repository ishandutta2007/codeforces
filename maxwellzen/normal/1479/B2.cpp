#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 100010;
 
int n;
int a[MAXN];
int pos[MAXN], nxt[MAXN];
 
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i <= n; ++i)
		pos[i] = n + 1;
	for (int i = n; i >= 0; --i)
	{
		nxt[i] = pos[a[i]];
		pos[a[i]] = i;
	}
	int x = 0, y = 0; // the last elements of the two subarrays
	int res = 0;
	for (int z = 1; z <= n; ++z)
	{
		// if one of the two last elements matches a[z], just append a[z] after it.
		if (a[x] == a[z])
		{
			x = z;
		}
		else if (a[y] == a[z])
		{
			y = z;
		}
		// otherwise, replace the later one.
		else if (nxt[x] > nxt[y])
		{
			res += 1;
			x = z;
		}
		else
		{
			res += 1;
			y = z;
		}
	}
	printf("%d\n", res);
}
 
int main()
{
	solve();
	return 0;
}