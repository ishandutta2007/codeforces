#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
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
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
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
#define mod 1100000007
#define ll long long
#define N 111000

int n,m;
char s[110][110];
bool vis[110][110];
int a[110],b[110],A,B;
bool vis1[110],vis2[110];
void dfs2(int);
void dfs1(int x)
{
	if(vis1[x])return;
	vis1[x] = 1;
	a[++ A] = x;
	rep(j, 1, m)
		if(s[x][j] == '#')
			dfs2(j);
}
void dfs2(int y)
{
	if(vis2[y])return;
	vis2[y] = 1;
	b[++ B] = y;
	rep(i, 1, n)
		if(s[i][y] == '#')
			dfs1(i);
}
int main()
{
	n = read();
	m = read();
	rep(i, 1, n)
		scanf("%s", s[i] + 1);
	rep(i, 1, n)
	{
		rep(j, 1, m)
			if(s[i][j] == '#' && !vis[i][j])
			{
				A = 0;
				B = 0;
				dfs1(i);
				rep(t1, 1, A)
					rep(t2, 1, B)
						vis[a[t1]][b[t2]] = 1;
			}
	}
	rep(i, 1, n)
		rep(j, 1, m)
		{
			if(vis[i][j] == 1 && s[i][j] == '.')
				return puts("No"), 0;
			if(vis[i][j] == 0 && s[i][j] == '#')
				return puts("No"), 0;
		}
	puts("Yes");
}