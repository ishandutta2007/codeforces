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
		// Greedy Strategy I
		if (a[x] == a[z])
		{
			res += a[y] != a[z];
			y = z;
		}
		else if (a[y] == a[z])
		{
			res += a[x] != a[z];
			x = z;
		}
		// Greedy Strategy II
		else if (nxt[x] < nxt[y])
		{
			res += a[x] != a[z];
			x = z;
		}
		else
		{
			res += a[y] != a[z];
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