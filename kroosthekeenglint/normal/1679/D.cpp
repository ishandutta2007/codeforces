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
edge * li[200005];
edge * new_edge()
{
    static edge a[200005];
    static int top=0;
    return &a[top++];
}
void insert_edge(int x,int y)
{
    edge * t=new_edge();
    t->y=y;
    t->next=li[x];
    li[x]=t;
}
int a[200005];
int n,m;
long long k;
int depth[200005];
int vis[200005];
bool flag;
void dfs(int x,int val)
{
    if (a[x]>val)
    {
        vis[x]=2;
        return;
    }
    if (vis[x]==1)
    {
        flag=true;
        return;
    }
    if (vis[x]==2)
    {
        return;
    }
    vis[x]=1;
    depth[x]=0;
    edge * t;
    for (t=li[x];t!=0;t=t->next)
    {
        dfs(t->y,val);
        if (flag)
        {
            return;
        }
        depth[x]=max(depth[x],depth[t->y]+1);
    }
    vis[x]=2;
}
bool check(int x)
{
    flag=false;
    int i;
    for (i=0;i<n;i++)
    {
        depth[i]=-1;
        vis[i]=0;
    }
    for (i=0;i<n;i++)
    {
        if (vis[i]==0)
        {
            dfs(i,x);
        }
        if (flag)
        {
            return true;
        }
        if (depth[i]>=k)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cin>>n>>m>>k;
    if (k>n)
    {
        k=n+2;
    }
    k--;
    int i;
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
        insert_edge(x,y);
    }
    int l=0,r=1000000007;
    for (;l<=r;)
    {
        int mid=(l+r)/2;
        if (check(mid))
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    if (r==1000000007)
    {
        l=-1;
    }
    printf("%d\n",l);
    return 0;
}