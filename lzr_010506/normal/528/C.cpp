#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
#define N 100010
int out[N], deg[N];
queue<pair<int,int> >q[N];
bool vis[N * 3];

struct Node
{
    int a, b;
}ans[3 * N];

int cnt;

void dfs(int u)
{
    int i, v;
    pair<int, int> now;
    while(!q[u].empty())
    {
        now = q[u].front(); 
        q[u].pop();
        v = now.first; 
        if(vis[now.second]) continue;
        vis[now.second] = 1;
        dfs(v);
        ans[++ cnt].a = u;
        ans[cnt].b = v;
    }
}

int main()
{
    int n,m,i,a,b;
    scanf("%d%d",&n,&m);
    int num = 0;
    for(int i = 1; i <= m; i ++) 
    {
        scanf("%d%d", &a, &b);
        q[a].push(mp(b, ++ num));
        q[b].push(mp(a, num));
        deg[a] ++; 
        deg[b] ++;
    }
    int last = -1;
    for(int i = 1; i <= n; i ++)
        if(deg[i] & 1)
        {
            if(last == -1) last = i;
            else 
            {
                q[last].push(mp(i, ++ num));
                q[i].push(mp(last, num));
                last = -1;
                deg[last] ++; 
                deg[i] ++;
            }
        }
    if(num & 1) q[1].push(mp(1, ++ num));
    
    dfs(1);
    cout << cnt << endl;
    for(int i = 1; i <= cnt; i ++)
    {
        if(i & 1) printf("%d %d\n",ans[i].a,ans[i].b);
        else printf("%d %d\n",ans[i].b,ans[i].a);
    }
    return 0;
}