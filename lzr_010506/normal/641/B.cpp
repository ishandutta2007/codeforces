#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int a[110][110];
struct Node
{
	int type, r, c, x;
}p[10010];
int main()
{
    int n, m, q;
    n = read();
    m = read();
    q = read();
    rep(i, 1, q)
    {
        int op = read();
        if (op == 3)
        {
            p[i].type = 3;
            p[i].r = read();
            p[i].c = read();
            p[i].x = read();
        }
        if (op == 2)
        {
            p[i].type = 2;
            p[i].c = read();
        }
        if (op == 1)
        {
            p[i].type = 1;
            p[i].r = read();
        }
    }
    rrep(i, q, 1)
    {
        if (p[i].type == 1)
        {
            int row = p[i].r;
            int t = a[row][m];
            rrep(i, m, 2) a[row][i] = a[row][i - 1];
            a[row][1] = t;
        }
        if (p[i].type == 2)
        {
            int col = p[i].c;
            int t = a[n][col];
            rrep(i, n, 2) a[i][col] = a[i - 1][col];
            a[1][col] = t;
        }
        if (p[i].type == 3) a[p[i].r][p[i].c] = p[i].x;
    }
    rep(i, 1, n)
    {
    	rep(j, 1, m)
    		cout << a[i][j] << " ";
    	puts("");
    }
    return 0;
}