#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define rrep(i, x, y) for (int i = x; i >= y; i--)
#define rep0(i, n) for (int i = 0; i < (n); i++)
#define per0(i, n) for (int i = (n)-1; i >= 0; i--)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define All(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 1010;
int n, m;
char ch[N][N];
int a[N][N];
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
void dfs(int x, int y)
{
	rep0(i, 4)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx <= 0 || xx > n || yy <= 0 || yy > m) continue;
		if(ch[xx][yy] == '#' && !a[xx][yy]) a[xx][yy] = a[x][y], dfs(xx, yy);
	}
}
int main()
{
	n = read();
	m = read();
	rep(i, 1, n)
		scanf("%s", ch[i] + 1);
	int cnt1 = 0;
	rep(i, 1, n)
		rep(j, 1, m)
			if(!a[i][j] && ch[i][j] == '#')
				a[i][j] = ++ cnt1, dfs(i, j);
	//puts("-----");
	int h = 0, c = 0;
	rep(i, 1, n)
	{
		bool flag = 1;
		rep(j, 1, m)
			if(ch[i][j] == '#') flag = 0;
		if(flag) h = 1;
	}
	rep(i, 1, m)
	{
		bool flag = 1;
		rep(j, 1, n)
			if(ch[j][i] == '#') flag = 0;
		if(flag) c = 1;
	}
	//cout << h << c << endl;
	if(h + c == 1) {puts("-1"); return 0;}
	rep(i, 1, n)
	{
		int cnt = 0;
		rep(j, 1, m)
			if(ch[i][j] == '#' && ch[i][j] != ch[i][j - 1]) cnt ++;
		if(cnt > 1) 
		{
			puts("-1");
			return 0;
		}
	}
	rep(i, 1, m)
	{
		int cnt = 0;
		rep(j, 1, n)
			if(ch[j][i] == '#' && ch[j][i] != ch[j - 1][i]) cnt ++;
		if(cnt > 1) 
		{
			puts("-1");
			return 0;
		}
	}
	printf("%d\n", cnt1);
	return 0;
}