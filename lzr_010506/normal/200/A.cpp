#include <bits/stdc++.h>
#include <math.h>
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
const int N = 2010;
int n, m, k, dis[N][N];;
bool vis[N][N];
int main()
{
	n = read();
	m = read();
	k = read();
	rep(T, 0, k - 1)
	{
		int x = read();
		int y = read();
		if(!vis[x][y])
        {
            printf("%d %d\n", x, y);
            vis[x][y] = 1;
            dis[x][y] = 1;
            continue;
        }
        else
        {
            rep(i, -1, 1)
				rep(j, -1, 1)
					if(x + i > 0 && x + i <= n && y + j > 0 && y + j <= m)
		                dis[x][y] = max(dis[x + i][y + j] - abs(i) - abs(j), dis[x][y]);
            bool flag = 0;
            for(int &d = dis[x][y];; dis[x][y] ++)
            {
                for(int xx = x - d, y1 = 0; xx <= x; xx ++, y1 ++)
                {
                    if(xx <= 0) continue;
                    if(y - y1 > 0 && !vis[xx][y - y1])
                    {
                        flag = vis[xx][y - y1] = 1;
                        dis[xx][y - y1] = 1;
                        printf("%d %d\n", xx, y - y1);
                        break;
                    }
                    else if(y + y1 <= m && !vis[xx][y + y1])
                    {
                        flag = vis[xx][y + y1] = 1;
                        dis[xx][y + y1] = 1;
                        printf("%d %d\n", xx, y + y1);
                        break;
                    }
                }
                if(flag) break;
                for(int xx = x, y1 = d; xx <= d + x; xx ++, y1 --)
                {
                    if(xx > n) break;
                    if(y - y1 > 0 && !vis[xx][y - y1])
                    {
                        flag = vis[xx][y - y1] = 1;
                        dis[xx][y - y1] = 1;
                        printf("%d %d\n", xx, y - y1);
                        break;
                    }
                    else if(y + y1 <= m && !vis[xx][y + y1])
                    {
                        flag = vis[xx][y + y1] = 1;
                        dis[xx][y + y1] = 1;
                        printf("%d %d\n", xx, y + y1);
                        break;
                    }
                }
                if(flag) break;
            }
        }
    }

    return 0;
}