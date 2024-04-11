#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int sum_edge[200005];
int known_edge[200005];
int min_val[200005];
int dist[200005];
bool vis[200005];
struct edge
{
    int y;
    edge * next;
};
edge * li[200005];
edge * new_edge()
{
    static edge a[200005];
    static int top=0;
    return &a[top++];
}
void insert_edge(int x,int y)
{
    swap(x,y);
    edge * t=new_edge();
    t->y=y;
    t->next=li[x];
    li[x]=t;
}
void bfs(int s)
{
    priority_queue<pair<int, int> > q;
    q.push(make_pair(0,s));
    dist[s]=0;
    for (;!q.empty();)
    {
        int now=q.top().second;
        q.pop();
        if (vis[now])
        {
            continue;
        }
        vis[now]=true;
        edge * t;
        for (t=li[now];t!=0;t=t->next)
        {
            if ((dist[t->y]==-1) || (dist[t->y] > dist[now] + sum_edge[t->y]))
            {
                dist[t->y] = dist[now] + sum_edge[t->y];
                q.push(make_pair(-dist[t->y],t->y));
                known_edge[t->y]++;
            }
            else if (dist[t->y] > dist[now] + (sum_edge[t->y] - known_edge[t->y]))
            {
                dist[t->y] --;
                q.push(make_pair(-dist[t->y],t->y));
                known_edge[t->y]++;
            }
            else
            {
                known_edge[t->y]++;
            }
        }
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    for (i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        y--;
        insert_edge(x,y);
        sum_edge[x]++;
    }
    memset(dist,-1,sizeof(dist));
    bfs(n-1);
    printf("%d\n",dist[0]);
    return 0;
}