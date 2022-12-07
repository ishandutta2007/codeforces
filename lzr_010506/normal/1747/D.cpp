#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], xr[N], cnt[N], nxt[N], pre[N];

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i ++) 
	{
		scanf("%d", a + i);
		xr[i] = xr[i - 1] ^ a[i];
		cnt[i] = cnt[i - 1] + (a[i] == 0);
		nxt[i] = n + 1;
	}
 
	map<int, int> lst[2];
	lst[0][0] = 0;
	for (int i = 1; i <= n; i ++)
	{
		if (lst[i & 1 ^ 1].count(xr[i])) 
		{
			int lastpos = lst[i & 1 ^ 1][xr[i]];
			pre[i] = lastpos + 1;
			nxt[lastpos + 1] = min(nxt[lastpos + 1], i);
		}
		lst[i & 1][xr[i]] = i;
	}
	while (q --)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		if(xr[r] ^ xr[l - 1]) puts("-1");
		else if (cnt[r] - cnt[l - 1] == r - l + 1) puts("0");
		else if ((r - l + 1) & 1) puts("1");
		else if (a[l] == 0 || a[r] == 0) puts("1");
		else if (nxt[l] < r || pre[r] > l) puts("2");
		else puts("-1");
	}
	return 0;
}