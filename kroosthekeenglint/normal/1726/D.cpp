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
#define size s21803
int fa[200005];
int size[200005];
int fa2[200005];
int size2[200005];
int findroot(int x, int * fa)
{
    int root;
    for (root=x;fa[root]!=-1;root=fa[root]) ;
    int temp;
    for (;fa[x]!=-1;)
    {
        temp=fa[x];
        fa[x]=root;
        x=temp;
    }
    return root;
}
void u(int x,int y, int * fa,int * size)
{
    x = findroot(x,fa);
    y = findroot(y,fa);
    if (size[x] > size[y])
    {
        swap(x,y);
    }
    fa[x] = y;
    size[y] += size[x];
}
int x[200005],y[200005];
char ans[200005];
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
            fa[i] = -1;
            size[i] = 1;
            fa2[i] = -1;
            size2[i] = 1;
        }
        int flag = 0;
        for (i=0;i<m;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            x[i]--;
            y[i]--;
            if ((findroot(x[i],fa) == findroot(y[i],fa)))
            {
                ans[i] = '1';
                if ((findroot(x[i],fa2) == findroot(y[i], fa2)))
                {
                    flag = i + 1;
                    continue;
                }
                u(x[i],y[i],fa2,size2);
            }
            else
            {
                ans[i] = '0';
                u(x[i],y[i],fa,size);
            }
        }
        // If not ok: there is a cycle
        if (flag)
        {
            flag--;
            ans[flag] = '0';
            for (i=0;i<n;i++)
            {
                fa[i] = -1;
                size[i] = 1;
                fa2[i] = -1;
                size2[i] = 1;
            }
            u(x[flag], y[flag], fa, size);
            for (i=0;i<m;i++)
            {
                if ((ans[i] == '1') || (i == flag))
                {
                    continue;
                }
                if ((findroot(x[i],fa) == findroot(y[i],fa)))
                {
                    ans[i] = '1';
                }
                else
                {
                    ans[i] = '0';
                    u(x[i],y[i],fa,size);
                }
            }
        }
        ans[m] = '\0';
        printf("%s\n",ans);
    }
    return 0;
}