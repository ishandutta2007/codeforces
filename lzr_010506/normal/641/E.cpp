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
map<int, int>c[1000010];
map<int, int> vis;
int tot = 0;
inline int lowbit(int x)
{
    return x & (-x);
}
void update(int x, int t, int y)
{
	while(t <= 1e9)
	{
		c[x][t] += y;
		t += lowbit(t);
	}
}
int query(int x, int t)
{
    int res = 0;
    while(t)
    {
    	res += c[x][t];
    	t -= lowbit(t);
    }
    return res;
}
int main()
{
    int Q = read();
    while(Q --)
    {
        int op,x,y;
        op = read();
        x = read();
        y = read();
        if (op == 1 && !vis[y]) vis[y] = ++tot;
        if (op == 1) update(vis[y], x, 1);
        if (op == 2) update(vis[y], x, -1);
        if (op == 3) printf("%d\n", query(vis[y], x));
    }
    return 0;
}