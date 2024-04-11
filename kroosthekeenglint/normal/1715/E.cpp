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
long long dist[100005];
long long last_dist[100005];
struct edge
{
    int y;
    int weight;
    edge * next;
};
edge * li[100005];
edge * new_edge()
{
    static edge a[200005];
    static int top=0;
    return &a[top++];
}
void inserts(int x,int y,int z)
{
    edge * t = new_edge();
    t->y=y;
    t->weight = z;
    t->next=li[x];
    li[x]=t; 
}
void insert_edge(int x,int y,int z)
{
    inserts(x,y,z);
    inserts(y,x,z);
}
int n;
bool vis[100005];
void dijkstra()
{
    priority_queue<pair<long long,int> > q;
    int i;
    for (i=0;i<n;i++)
    {
        vis[i] = false; 
        if (dist[i] != -1)
        {
            q.push(make_pair(-dist[i], i));
        }
    }
    for (;!q.empty();)
    {
        int now = q.top().second;
        q.pop();
        if (vis[now])
        {
            continue;
        }
        vis[now]=true;
        edge * t;
        for (t=li[now];t!=0;t=t->next)
        {
            if ((dist[t->y] == -1) || (dist[t->y] > dist[now] + t->weight))
            {
                dist[t->y] = dist[now] + t->weight;
                q.push(make_pair(-dist[t->y], t->y));
            }
        }
    }
}
struct line
{
    long long k;
    long long b;
    long long calc(int i)
    {
        return k * i + b;
    }
    line (long long kk = 0, long long bb = 0)
    {
        k = kk;
        b = bb;
    }
    friend line operator - (const line &a,const line &b)
    {
        return line(a.k-b.k,a.b-b.b);
    }
    friend __int128 operator * (const line &a,const line &b)
    {
        return (__int128)a.k*b.b - (__int128)b.k*a.b;
    }
    
};
line que[100005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int m,k;
    scanf("%d%d%d",&n,&m,&k);
    int i;
    for (i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x--;
        y--;
        insert_edge(x,y,z);
    }
    memset(dist,-1,sizeof(dist));
    dist[0] = 0;
    for (i=1;i<=k;i++)
    {
        dijkstra();
        int j;
        for (j=0;j<n;j++)
        {
            last_dist[j] = dist[j];
            if (last_dist[j] == -1)
            {
                last_dist[j] = 999999999999999ll;
            }
            dist[j] = 999999999999999ll;
        }
        int front = 0, rail = 0;
        for (j=0;j<n;j++)
        {
            line x(-2 * j, (long long)j * j + last_dist[j]);
            for (;front<rail-1;rail--)
            {
                if ((x - que[rail - 1]) * (que[rail-1] - que[rail-2]) > 0)
                {
                    break;
                }
            }
            que[rail++] = x;
            for (;front<rail-1;front++)
            {
                if (que[front].calc(j) < que[front+1].calc(j))
                {
                    break;
                }
            }
            dist[j] = min(dist[j], que[front].calc(j) + (long long)j * j);
        }
        front=0;
        rail=0;
        for (j=n-1;j>=0;j--)
        {
            int k = n-1-j;
            line x(-2 * k, (long long)k * k + last_dist[j]);
            for (;front<rail-1;rail--)
            {
                if ((x - que[rail - 1]) * (que[rail-1] - que[rail-2]) > 0)
                {
                    break;
                }
            }
            que[rail++] = x;
            for (;front<rail-1;front++)
            {
                if (que[front].calc(k) < que[front+1].calc(k))
                {
                    break;
                }
            }
            dist[j] = min(dist[j], que[front].calc(k) + (long long)k * k);
        }
    }
    dijkstra();
    for (i=0;i<n;i++)
    {
        printf("%lld ",dist[i]);
    }
    return 0;
}