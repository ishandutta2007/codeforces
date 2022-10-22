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
char a[400005];
struct edge
{
    int y;
    int weight;
    edge * next;
};
edge * new_edge()
{
    static edge a[1600005];
    static int top=0;
    return &a[top++];
}
edge * li[400005];
void insert_edge(int x,int y,int z)
{
    if (z == -1)
    {
        return;
    }
    edge * t = new_edge();
    t->y=y;
    t->weight = z;
    t->next=li[x];
    li[x]=t;
}
int check(char x)
{
    if (x == '.')
    {
        return 1;
    }
    if (x == '#')
    {
        return 0;
    }
    return -1;
}
int dist[400005];
int pre[400005];
bool vis[400005];
void dijkstra(int s,int t)
{
    int i;
    for (i=0;i<=t;i++)
    {
        dist[i] = -1;
        pre[i] = -1;
        vis[i] = 0;
    }
    dist[s] = 0;
    priority_queue<pair<int,int> > q;
    q.push(make_pair(0,s));
    for (;!q.empty();)
    {
        int now = q.top().second;
        q.pop();
        if (vis[now])
        {
            continue;
        }
        vis[now] = true;
        edge * t;
        for (t=li[now];t!=0;t=t->next)
        {
            if ((dist[t->y] == -1) || (dist[t->y] > dist[now] + t->weight))
            {
                dist[t->y] = dist[now] + t->weight;
                pre[t->y] = now;
                q.push(make_pair(-dist[t->y], t->y));
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
    int t;
    scanf("%d",&t);
    int zu;
    for (zu=0;zu<t;zu++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int i;
        for (i=0;i<n;i++)
        {
            scanf("%s",a+i*m);
        }
        for (i=0;i<n*m+2;i++)
        {
            li[i] = 0;
        }
        for (i=0;i<n;i++)
        {
            int j;
            for (j=0;j<m;j++)
            {
                if (a[i*m+j] == '#')
                {
                    if (i != 0)
                    {
                        a[i*m+j-m] = '*';
                    }
                    if (j != 0)
                    {
                        a[i*m+j-1] = '*';
                    }
                    if (i != n-1)
                    {
                        a[i*m+j+m] = '*';
                    }
                    if (j != m-1)
                    {
                        a[i*m+j+1] = '*';
                    }
                }
            }
        }
        int s = n * m , t = n * m + 1;
        for (i=0;i<n;i++)
        {
            insert_edge(s, i*m, check(a[i*m]));
            insert_edge(i*m+m-1, t, 0);
        }
        for (i=0;i<n;i++)
        {
            int j;
            for (j=0;j<m;j++)
            {
                if ((i!=0) && (j!=0))
                {
                    insert_edge(i*m+j, i*m+j-m-1, check(a[i*m+j-m-1]));
                }
                if ((i!=0) && (j!=m-1))
                {
                    insert_edge(i*m+j, i*m+j-m+1, check(a[i*m+j-m+1]));
                }
                if ((i!=n-1) && (j!=0))
                {
                    insert_edge(i*m+j, i*m+j+m-1, check(a[i*m+j+m-1]));
                }
                if ((i!=n-1) && (j!=m-1))
                {
                    insert_edge(i*m+j, i*m+j+m+1, check(a[i*m+j+m+1]));
                }
            }
        }
        dijkstra(s,t);
        if (dist[t] == -1)
        {
            puts("NO");
        }
        else
        {
            int now = pre[t];
            for (;now != s;)
            {
                a[now] = '#';
                now = pre[now];
            }
            puts("YES");
            for (i=0;i<n;i++)
            {
                int j;
                for (j=0;j<m;j++)
                {
                    if (a[i*m+j] == '#')
                    {
                        printf("#"); 
                    }
                    else
                    {
                        printf(".");
                    }
                } 
                printf("\n");
            }
        }
    }
    return 0;
}