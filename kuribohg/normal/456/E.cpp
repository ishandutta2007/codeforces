#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=300010;
vector<int> graph[MAXN];
queue<int> q;
int n,m,qq,fa[MAXN],w[MAXN],in1,in2,op,dis[MAXN],a[MAXN],t;
bool used[MAXN];
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
inline void uni(int i,int j)
{
    w[find(j)]=max(max(w[find(j)],w[find(i)]),(w[find(i)]+1)/2+(w[find(j)]+1)/2+1);
    fa[find(i)]=find(j);
}
inline void BFS(int x)
{
    q.push(x);t=0;
    used[x]=true,dis[x]=0;
    while(!q.empty())
    {
        int x=q.front(),len=graph[x].size();
        q.pop();a[++t]=x;
        for(int i=0;i<len;i++)
        {
            int t=graph[x][i];
            if(!used[t])
            {
                used[t]=true,dis[t]=dis[x]+1;
                q.push(t);
            }
        }
    }
}
inline int getd(int x)
{
    int maxd=0;
    BFS(x);
    for(int i=1;i<=t;i++) if(dis[a[i]]>dis[a[maxd]]) maxd=i;
    for(int i=1;i<=t;i++) used[a[i]]=false;
    BFS(a[maxd]);
    for(int i=1;i<=t;i++) if(dis[a[i]]>dis[a[maxd]]) maxd=i;
    return dis[a[maxd]];
}
int main()
{
    scanf("%d%d%d",&n,&m,&qq);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&in1,&in2);
        graph[in1].push_back(in2);
        graph[in2].push_back(in1);
        fa[find(in1)]=find(in2);
    }
    for(int i=1;i<=n;i++)
        if(!used[i]) w[find(i)]=getd(i);
    for(int i=1;i<=qq;i++)
    {
        scanf("%d%d",&op,&in1);
        if(op==2) scanf("%d",&in2);
        if(op==1) printf("%d\n",w[find(in1)]);
        else if(find(in1)!=find(in2)) uni(in1,in2);
    }
    return 0;
}