#include <bits/stdc++.h>
using namespace std;

int n, m;
int sum, in[100005], top[100005];
vector <int> e[100005], path;

struct Node
{
    int u, v, w;
}data[100005];

int f(int mid)
{
    sum = 0;
    for(int i = 1; i <= n; ++i) e[i].clear();
    memset(in,0,sizeof(in));
    for(int i = 1; i <= m; ++i)
    {
        if(data[i].w > mid)
        {
            e[data[i].u].push_back(data[i].v);
            ++in[data[i].v];
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; ++i) if(!in[i]) q.push(i), top[i] = ++sum;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v : e[u])
        {
            --in[v];
            if(!in[v]) q.push(v), top[v] = ++sum;
        }
    }

    for(int i = 1; i <= n; ++i) if(in[i]) return 0;
    return 1;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= m; ++i) scanf("%d%d%d",&data[i].u,&data[i].v,&data[i].w);
    int l = 0, r = 1e9, mid, ans;
    while(l <= r)
    {
        mid = (l+r) >> 1;
        if(f(mid)) r = mid-1, ans = mid;
        else l = mid+1;
    }
    f(ans); 
    // toptop
    for(int i = 1; i <= m; ++i) if(data[i].w <= ans && top[data[i].u] > top[data[i].v]) path.push_back(i);

    printf("%d %d\n",ans,path.size());
    for(auto i : path) printf("%d ",i);
    return 0;
}