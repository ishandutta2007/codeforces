#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define rrep(i, x,  y) for(int i = x; i >= y; i --)
#define ll unsigned long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define pll pair<ll, ll>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
bool distinct(int a,int b,int c,int d)
{
	int tmp[5];
	tmp[1] = a;
	tmp[2] = b;
	tmp[3] = c;
	tmp[4] = d;
	sort(tmp + 1, tmp + 4 + 1);
	if (tmp[1] == 1 && tmp[2] == 2 && tmp[3] == 3 && tmp[4] == 4) return 1;
	return 0;
}
int n,m;
char g[110][110];
char a[1010];
int dy[6];
bool check()
{
	int x,y;
	rep(i, 1, n)
		rep(j, 1, m)
			if (g[i][j] == 'S') x = i, y = j;
	int len = strlen(a + 1);
	rep(i, 1, len)
	{
		if (dy[a[i] - '0' + 1] == 1) x ++;
		if (dy[a[i] - '0' + 1] == 2) y ++;
		if (dy[a[i] - '0' + 1] == 3) x --;
		if (dy[a[i] - '0' + 1] == 4) y --;
		if (x < 1 || x > n || y < 1 || y > m)return 0;
		if (g[x][y] == '#') return 0;
		if (g[x][y] == 'E') return 1;
	}
	return 0;
}
int main()
{
	n = read();
	m = read();
	rep(i, 1, n) scanf("%s", g[i] + 1);
	scanf("%s", a + 1);
	int ans = 0;
	for(dy[1] = 1; dy[1] <= 4; dy[1] ++)
		for(dy[2] = 1; dy[2] <= 4; dy[2] ++)
			for(dy[3] = 1; dy[3] <= 4; dy[3] ++)
				for(dy[4] = 1; dy[4] <= 4; dy[4] ++)
					if (distinct(dy[1], dy[2], dy[3], dy[4]))
						if (check()) ans ++;
	cout << ans << endl;
	return 0;
}