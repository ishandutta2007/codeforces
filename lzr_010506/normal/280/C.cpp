#include <bits/stdc++.h>
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define db double
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
#define ll long long
const int mod = 998244353;
using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
const int N = 100010;
vector<int> a[N];
int dep[N];

void dfs(int x, int fa)
{
	dep[x] = dep[fa] + 1;
	int nn = a[x].size();
	rep(i, 0, nn - 1)
	{
		int to = a[x][i];
		if(to == fa) continue;
		dfs(to, x);
	}
}

int main()
{
	int n = read();
	rep(i, 1, n - 1)
	{
		int x = read();
		int y = read();
		a[x].pb(y);
		a[y].pb(x);
	}
	dfs(1, 0);
	db ans = 0.0;
	rep(i, 1, n) ans += 1.0 / dep[i];
	printf("%.12lf", ans);
	return 0;
}
/*
6 7
1 2 3
1 3 4
2 4 3
3 4 1
3 5 2
4 6 1
5 6 1
*/