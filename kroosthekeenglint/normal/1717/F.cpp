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
const int max_n=20005;
const int inf=99999999;
struct edge
{
    int y;
    int weight;
    edge * next;
    edge * anti; 
};
edge * li[max_n];
edge * new_edge()
{
    static edge a[1000005];
    static int top=0;
    return &a[top++];
}
edge * inserts(int x,int y,int z)
{
    edge * t=new_edge();
    t->y=y;
    t->weight=z;
    t->next=li[x];
    li[x]=t;
    return t;
}
void insert_edge(int x,int y,int z)
{
    edge * t1=inserts(x,y,z);
    edge * t2=inserts(y,x,0);
    t1->anti=t2;
    t2->anti=t1;
}
int dist[max_n]; 
edge * path[max_n];
edge * cur[max_n];
int pre[max_n];
int bfs(int s,int t)
{
    memset(dist,-1,sizeof(dist));
    dist[s]=0;
    static int que[max_n];
    int front=0,rail=1;
    que[0]=s;
    for (;front<rail;front++)
    {
        int now=que[front];
        edge * x;
        for (x=li[now];x!=0;x=x->next)
        {
            if ((x->weight>0)&&(dist[x->y]==-1))
            {
                dist[x->y]=dist[now]+1;
                que[rail++]=x->y;
                if (x->y==t)
                {
                    return true;
                }
            }
        } 
    }
    return false;
}
int max_flow(int s,int t)
{
    int flow = 0;
    for (;bfs(s,t);)
    {
        memcpy(cur,li,sizeof(cur));
        int now=s;
        for (;dist[s]!=-1;)
        {
            if (now==t)
            {
                int temp;
                int max_flow=inf;
                for (temp=t;temp!=s;temp=pre[temp])
                {
                    max_flow=min(max_flow,path[temp]->weight);
                }
                for (temp=t;temp!=s;temp=pre[temp])
                {
                    path[temp]->weight-=max_flow;
                    path[temp]->anti->weight+=max_flow;
                }
                flow+=max_flow;
                now=s;
            }
            edge * x;
            for (x=cur[now];x!=0;x=x->next)
            {
                if ((dist[x->y]==dist[now]+1)&&(x->weight>0))
                {
                    path[x->y]=x;
                    pre[x->y]=now;
                    cur[now]=x;
                    now=x->y;
                    break;
                }
            }
            if (x==0)
            {
                dist[now]=-1;
                now=pre[now];
            }
        }
    }
    return flow;
}
int ss[10005];
int a[10005];
int cnt[10005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    int s = n+m+2, t=n+m+3;
    int tt = n+m+1;
    for (i=0;i<n;i++)
    {
        scanf("%d",&ss[i]);
        if (ss[i] == 0)
        {
            insert_edge(m+i, tt, inf);
        }
    }
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        y--;
        cnt[x]++;
        cnt[y]++;
        insert_edge(s,i,1);
        insert_edge(i,x+m,1);
        insert_edge(i,y+m,1);
    }
    int rest = m;
    for (i=0;i<n;i++)
    {
        if (ss[i] == 0)
        {
            continue;
        }
        if ((cnt[i]+a[i])%2!=0)
        {
            puts("NO");
            return 0;
        }
        cnt[i] = (cnt[i] + a[i])/2;
        if (cnt[i] < 0)
        {
            puts("NO");
            return 0;
        } 
        rest -= cnt[i];
        insert_edge(i+m, t, cnt[i]);
    }
    if (rest < 0)
    {
        puts("NO");
        return 0;
    }
    insert_edge(tt,t,rest);
    if (max_flow(s,t) != m)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    for (i=0;i<m;i++)
    {
        edge * t;
        for (t=li[i];t!=0;t=t->next)
        {
            if ((t->weight == 1) && ((t->y)!=s))
            {
                printf("%d ",t->y - m + 1);
            }
        }
        for (t=li[i];t!=0;t=t->next)
        {
            if (t->weight == 0)
            {
                printf("%d\n",t->y - m + 1);
            }
        }
    }
    return 0;
}