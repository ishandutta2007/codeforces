#include <bits/stdc++.h>
#define maxn 510
using namespace std;
int f[maxn][maxn], a[maxn], n;
inline int ReadInt()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int dfs(int l, int r)
{
	if(f[l][r] != -1) return f[l][r];
	if(l == r) return 1;
	if(l > r) return 0;
	int ret = 1 + dfs(l + 1, r);
	for(int i = l + 2; i <= r; i ++)
		if (a[l] == a[i])
        	ret = min(ret, dfs(l + 1, i - 1) + dfs(i + 1, r));
    if (a[l] == a[l + 1]) ret = min(ret, 1 + dfs(l + 2, r));
    return f[l][r] = ret;
}

int main()
{
	n = ReadInt();
	for(int i = 1; i <= n; i ++)
		a[i] = ReadInt();
	memset(f, -1, sizeof(f));
	int ans = dfs(1, n);
	printf("%d",ans);
	return 0;
}