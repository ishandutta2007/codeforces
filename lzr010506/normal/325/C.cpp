#include <bits/stdc++.h>
#define pii pair<int, int>
#define inf 1000000000
#define ansmx 314000000
#define ll long long
using namespace std;
int read()
{
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
int m, n;
int mn[100005], mx[100005];
bool vis[100005], inq[100005];
vector<int>u[100005], v[100005];
priority_queue<pii, vector<pii>, greater<pii> >q;

inline int min(int a, int b)
{
    if(a < b) return a;
    return b;
}

inline int max(int a, int b)
{
    if(a > b) return a;
    return b;
}

struct data
{
    int id, w, r, sum;
    vector<int>v;
}p[100005];

void Init()
{
    m = read();
    n = read();
    for(int i = 1; i <= m; i ++)
    {
        p[i].id = read();
        u[p[i].id].push_back(i);
        int x = read();
        for(int j = 1; j <= x; j ++)
        {
            int y = read();
            if(y == -1) p[i].w ++;
            else
            {
                p[i].r ++;
                p[i].v.push_back(y);
                v[y].push_back(i);
            }
        }
        if(p[i].w == x) q.push(make_pair(p[i].w, p[i].id));
        p[i].sum = p[i].w;
    }
}

void dijkstra()
{
    memset(mn,127,sizeof(mn));
    while(!q.empty())
    {
        int d = min(inf, q.top().first), x = q.top().second;
        q.pop();
        if(d < mn[x])
        {
            for(int i = 0; i < v[x].size(); i ++)
            {
                int t = v[x][i];
                if(mn[x] > inf) p[t].r --, p[t].sum += d;
                else p[t].sum += d - mn[x];
                if(!p[t].r)q.push(make_pair(p[t].sum, p[t].id));
                p[t].sum = min(p[t].sum,inf);
            }
            mn[x] = d;
        }
    }
    for(int i = 1; i <= n; i ++)
        if(mn[i] > inf) mn[i] = mx[i] = -1;
}

void dp(int x)
{
    if(vis[x] || inq[x])return;
    vis[x] = inq[x] = 1;
    for(int i = 0; i < u[x].size(); i ++)
    {
        int t = u[x][i], sum = p[t].w;
        for(int j = 0; j < p[t].v.size(); j ++)
            if(mx[p[t].v[j]] == -1){sum = -1;break;}
        if(sum == -1)continue;
        for(int j = 0; j < p[t].v.size(); j ++)
        {
            int v = p[t].v[j];
            dp(v);
            if(inq[v] || mx[v] == inf){sum = inf; break;}
            sum += mx[v];
        }
        mx[x] = max(mx[x], sum);
    }
    inq[x] = 0;
}

int main()
{
    Init();
    dijkstra();
    for(int i = 1; i <= n; i ++)
        if(mx[i] != -1 && !vis[i])
            dp(i);
    for(int i = 1; i <= n; i ++)
        if(mx[i] == inf) mx[i] = -2;
    for(int i = 1; i <= n; i ++)
        printf("%d %d\n", min(mn[i], ansmx), min(mx[i], ansmx));
    return 0;
}