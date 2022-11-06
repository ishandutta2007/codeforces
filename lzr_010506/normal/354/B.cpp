#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define pii pair<int, int>
#define X first
#define Y second
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
const int N = 1e5 + 10;
const int inf = 110101010;
char a[25][25];
int dp[40][1 << 20], n;
bool vis[40][1 << 20];
int dfs(int x, int st)
{
	if(vis[x][st]) return dp[x][st];
    int &res = dp[x][st];
    vis[x][st] = 1;
    if(x == n * 2 - 2) res = 0;
    else
    {
        if(x & 1) res = -inf;
        else res = inf;
        int mask[30];
        memset(mask, 0, sizeof(mask));
        int cnt = 0;
        rep(j, 0, x + 1)
        {
            int X = x + 1 - j;
            int Y = j;
            if(X >= n || Y >= n) continue;
            mask[a[X][Y] - 'a'] |= (1 << cnt);
            cnt ++;
        }
        rep(i, 0, 25)
            if(mask[i])
            {
                int xt;
                if(x + 1 < n) xt = (st | (st << 1)) & mask[i];
                else xt = (st | (st >> 1)) & mask[i];
                if(!xt) continue;
                int tmp = 0;
                if(!i) tmp = 1;
                else if(i == 1) tmp = -1;
                if(x & 1) res = max(res, tmp + dfs(x + 1, xt));
                else res = min(res, tmp + dfs(x + 1, xt));
            }

    }
    if(!x)
    {
        if(a[0][0] == 'a') res ++;
        else if(a[0][0] == 'b') res --;
    }
    return res;
}
int main()
{
	n = read();
	rep(i, 0, n - 1)
		scanf("%s", a[i]);
    int res = dfs(0, 1);
    if(!res) printf("DRAW\n");
    else if(res > 0) printf("FIRST\n");
    else printf("SECOND\n");

    return 0;
}