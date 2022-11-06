#include <bits/stdc++.h>
using namespace std;
const int N = 7005;
bool win[N][2], vis[N][2];
int k[2], n;
vector<int>a[2];
int visit[N][2];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
void solve(int x, bool who)
{
    vis[x][who] = 1;
    for(int i = 0; i < a[!who].size(); i ++)
    {
    	int v = a[!who][i];
        int now = (x - v + n)%n;
        if(now == 0)continue;
        if(vis[now][!who])continue;
        if(win[x][who] && ++ visit[now][!who] == k[!who])
            solve(now, !who);
        else if(!win[x][who])
            win[now][!who] = 1,
                solve(now, !who);
    }
}
int main()
{
    n = read();
    for(int i = 0; i < 2; i ++)
    {
    	k[i] = read();
        a[i].resize(k[i]);
        for(int j = 0; j < k[i]; j ++)
            a[i][j] = read();
    }
    solve(0, 1);
    solve(0, 0);
    for(int i = 0; i < 2; i ++, puts(""))
        for(int j = 1; j < n; j ++)
            if(!vis[j][i]) printf("Loop ");
            else cout << (win[j][i]? "Win " : "Lose ");
    return 0;
}