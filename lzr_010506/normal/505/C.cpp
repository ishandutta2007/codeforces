#include <bits/stdc++.h>
#define ll long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
using namespace std;
const int N = 30010;
const int M = 510;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int a[N], f[N][M];
int n, d, xx, mx;
int dfs(int i, int j)
{
    int jj = j - xx;
    if(i > mx) return 0;
    if(~f[i][jj]) return f[i][jj];
    if(j <= 1) f[i][jj] = a[i] + max(dfs(i + j, j), dfs(i + j + 1, j + 1));
    else f[i][jj] = a[i] + max(dfs(i + j, j), max(dfs(i + j - 1, j - 1), dfs(i + j + 1, j + 1)));

    return f[i][jj];
}
int main()
{
	n = read();
	d = read();
	rep(i, 1, n)
    {
        int x = read();
        a[x] ++;
        mx = max(mx, x);
    }

	memset(f, -1, sizeof(f));
	xx = d - 250;
	cout << dfs(d, d);
	return 0;
}