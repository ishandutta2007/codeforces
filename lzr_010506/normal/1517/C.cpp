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
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
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
const int N = 510;
int n, a[N], ans[N][N];
const int dx[] = {0, 1};
const int dy[] = {-1, 0};

int main() 
{
	n = read();
	rep(i, 1, n) a[i] = read();
	rep(i, 1, n) ans[i][i] = a[i];
	rep(i, 1, n)
	{
		int nw = a[i], x = i, y = i;
		rep(j, 1, nw - 1)
		{
			int op = 1;
			if (y + dy[0] >= 1 && !ans[x + dx[0]][y + dy[0]]) op = 0;
			x += dx[op]; 
			y += dy[op];
			ans[x][y] = nw;
		}
	}
	rep(i, 1, n)
	{
		rep(j, 1, i)
			printf("%d ", ans[i][j]);
		puts("");
	}
	return 0;
}