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
    static edge a[800005];
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
int dp[200005][5];
//0 : have point downside        , doesn't need upside
//1 : have point downside        , need upside
//2 : doesn't have point downside, need upside
//3 : doesn't have point downside, doesn't need upside(leaf)
int fa[200005];
void dfs(int x)
{
    edge * t;
    int tot_points = 0;
    for (t=li[x];t!=0;t=t->next)
    {
        if (t->y==fa[x])
        {
            continue;
        }
        fa[t->y]=x;
        dfs(t->y);
        tot_points++;
    }
    if (tot_points == 0)
    {
        dp[x][0] = 1;
        dp[x][1] = 1;
        dp[x][2] = 0;
        dp[x][3] = 0;
    }
    else if (tot_points == 1)
    {
        for (t=li[x];t!=0;t=t->next)
        {
            if (t->y!=fa[x])
            {
                dp[x][0] = min(dp[t->y][0], min(dp[t->y][1], dp[t->y][2]) + 1);
                dp[x][1] = dp[t->y][1];
                dp[x][2] = min(dp[t->y][2], dp[t->y][3]);
                dp[x][3] = 200005;
            }
        }
    }
    else if ((x==0)&&(tot_points==2))
    {
        dp[x][0] = 0;
        dp[x][1] = 0;
        dp[x][2] = 200005;
        dp[x][3] = 200005;
        int cnt=0;
        int sum1=0, sum2=0;
        for (t=li[x];t!=0;t=t->next)
        {
            if (t->y!=fa[x])
            {
                dp[x][0] = dp[x][0] + min(dp[t->y][0], dp[t->y][1]);
                dp[x][1] = dp[x][1] + min(dp[t->y][1], dp[t->y][0]);
                cnt++;
                if (cnt==1)
                {
                    sum1 += dp[t->y][0];
                    sum2 += min(dp[t->y][2], dp[t->y][3]);
                }
                else
                {
                    sum1 += min(dp[t->y][2], dp[t->y][3]);
                    sum2 += dp[t->y][0];
                }
            }
        }
        dp[x][0] = min(dp[x][0], min(sum1, sum2));
    }
    else
    {
        dp[x][0] = 0;
        dp[x][1] = 0;
        dp[x][2] = 200005;
        dp[x][3] = 200005;
        //int sum_4 = 1;
        int max_not_upside = 0;
        for (t=li[x];t!=0;t=t->next)
        {
            if (t->y!=fa[x])
            {
                dp[x][0] = dp[x][0] + min(dp[t->y][0], dp[t->y][1]);
                //sum_4 += min(min(dp[t->y][1], dp[t->y][0]));
                dp[x][1] = dp[x][1] + min(dp[t->y][1], dp[t->y][0]);
                if (min(dp[t->y][1], dp[t->y][0]) - min(dp[t->y][2], dp[t->y][3]) > max_not_upside)
                {
                    max_not_upside = min(dp[t->y][1], dp[t->y][0]) - min(dp[t->y][2], dp[t->y][3]);
                }
            }
        }
        dp[x][0] = min(dp[x][0], dp[x][0]+1-max_not_upside);
        dp[x][1] -= max_not_upside;
        if (x==0)
        {
            dp[x][0] = min(dp[x][0], dp[x][1]);
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
        int n;
        scanf("%d",&n);
        int i;
        for (i=0;i<n;i++)
        {
            fa[i]=-1;
            li[i]=0;
        }
        for (i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x--;
            y--;
            insert_edge(x,y);
        }
        dfs(0);
        printf("%d\n",min(dp[0][0],dp[0][3]));
    }
    return 0;
}