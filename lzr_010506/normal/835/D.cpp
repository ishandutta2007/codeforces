#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 5010;
int n, l, r, cnt[N], f[N][N];
bool vis[N][N];
char s[N];

int dfs(int l, int r)
{
	if(!vis[l][r]) return 0;
	if(f[l][r]) return f[l][r];
	int mid = (l + r) >> 1;
	if((r - l) & 1) f[l][r] = min(dfs(l, mid), dfs(mid + 1, r)) + 1;
	else f[l][r] = min(dfs(l, mid - 1), dfs(mid + 1, r)) + 1;
	return f[l][r];
}

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	rep(i, 1, n)
	{
		l = i; r = i;
		while(l >= 1 && r <= n)
		{
			if(s[l] != s[r]) break;
			vis[l][r] = 1;
			l --;
			r ++;
		}
		l = i; r = i + 1;
		while(l >= 1 && r <= n)
		{
			if(s[l] != s[r]) break;
			vis[l][r] = 1;
			l --;
			r ++;
		}
	}

	rep(i, 1, n) f[i][i] = 1;
	rep(i, 1, n)
		rep(j, i + 1, n)
			if(!f[i][j])
				f[i][j] = dfs(i, j);

	rep(i, 1, n)
		rep(j, 1, n)
			cnt[f[i][j]] ++;
	rrep(i, n - 1, 1)
		cnt[i] += cnt[i + 1];
	rep(i, 1, n) cout << cnt[i] << " ";
	return 0;
}