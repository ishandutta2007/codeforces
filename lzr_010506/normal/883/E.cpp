#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pii pair<int, int>
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
#define ALL(x) (x).begin(), (x).end()
using namespace std;
int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 110;
const int M = 1010;
int n, m;
char a[M][N];
int ge[210], vis[M];
int main()
{
	n = read();
	scanf("%s", a[0]);
	m = read();
	rep(i, 1, m) scanf("%s", a[i]);
	rep(i, 0, n - 1) ge[a[0][i]] ++;
	int tmp = m;
	rep(i, 1, m)
	{
		rep(j, 0, n - 1)
		{
			if(a[0][j] == '*' && ge[a[i][j]]) vis[i] = 1;
			else if(a[0][j] != '*' && a[i][j] != a[0][j]) vis[i] = 1;
		}
		tmp -= vis[i];
	}
	int ans = 0;
	rep(ch, 'a', 'z')
	{
		if(ge[ch]) continue;
		int tot = 0;
		rep(i, 1, m)
		{
			if(vis[i]) continue;
			rep(j, 0, n - 1)
				if(a[i][j] == ch)
				{
					tot ++;
					break;
				}
		}
		if(tot == tmp) ans ++;
	}
	printf("%d\n", ans);
	return 0;
}