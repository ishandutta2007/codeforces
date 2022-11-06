#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define ll long long
#define X idst
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define mod 1000000007
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, m;
vector<int> a[100010];
int vis[100010];
inline bool check(int a, int b)
{
	if(abs(a - b) == m) return 1;
	if(a % m)
		if(a + 1 == b)
			return 1;
	if(b % m)
		if(b + 1 == a)
			return 1;
	return 0;
}
void dfs(int p, int x, int y, int id)
{
	if(y == m)
	{
		dfs(p, x + 1, 0, id);
		return;
	}
	if(p == n * m)
	{
		puts("YES");
		rep(i, 0, n - 1)
		{
			rep(j, 0, m - 1)
				printf("%d ",a[i][j]);
			puts("");
		}
		exit(0);
	}
	int flag = 1;
	rep(i, id, n * m)
	{
		if(flag) id = i;
		if(vis[i]) continue;
		flag = 0;
		if(x && check(a[x - 1][y], i)) continue;
		else if(y && check(a[x][y - 1], i)) continue;
		a[x][y] = i;
		vis[i] ++;
		dfs(p + 1, x, y + 1, id);
		vis[i] --;
	}
}
int main()
{
	n = read();
	m = read();
	rep(i, 0, n - 1)
		rep(j, 0, m - 1)
			a[i].pb(0);
	dfs(0, 0, 0, 1);
	puts("NO");
	return 0;
}