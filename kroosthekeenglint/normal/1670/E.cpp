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
struct edge
{
    int y;
    edge * next;
};
edge * new_edge()
{
    static edge a[6000005];
    static int top=0;
    return &a[top++];
}
edge * li[200005];
void inserts(int x,int y)
{
    edge * t=new_edge();
    t->y=y;
    t->next=li[x];
    li[x]=t;
}
void insert_edge(int x,int y)
{
    inserts(x,y);
    inserts(y,x);
}
int edge_x[200005],edge_y[200005];
int fa[200005];
int val[200005],val_edge[200005];
int sum=0;
int p;
void dfs(int x,int dep=1)
{
    if (x==0)
    {
        val[x]=(1<<p);
    }
    else if (dep == 0)
    {
        val[x] = sum++;
        val_edge[x] = val[x] ^ (1<<p);
    }
    else
    {
        val_edge[x]= sum++;
        val[x]= val_edge[x] ^ (1<<p);
    }
    edge * t;
    for (t=li[x];t!=0;t=t->next)
    {
        if (t->y==fa[x])
        {
            continue;
        }
        fa[t->y]=x;
        dfs(t->y,dep^1);
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
        scanf("%d",&p);
        int i;
        for (i=0;i<(1<<p);i++)
        {
            li[i]=0;
            fa[i]=-1;
        }
        for (i=1;i<(1<<p);i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x--;
            y--;
            insert_edge(x,y);
            edge_x[i]=x;
            edge_y[i]=y;
        }
        sum=1;
        dfs(0);
        printf("1\n%d",(1<<p));
        for (i=1;i<(1<<p);i++)
        {
            printf(" %d",val[i]);
        }
        printf("\n");
        for (i=1;i<(1<<p);i++)
        {
            if (fa[edge_x[i]]==edge_y[i])
            {
                printf("%d ",val_edge[edge_x[i]]);
            }
            else
            {
                printf("%d ",val_edge[edge_y[i]]);
            }
        }
        printf("\n");
    }
    
    return 0;
}