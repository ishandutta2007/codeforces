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
#define size su1200912
int a[1005][1005];
int fa[1005],cnt[1005],size[1005];
int findroot(int x,int &z)
{
    int root;
    int cnts = 0;
    for (root=x;fa[root]!=-1;root=fa[root])
    {
        cnts = cnts ^ cnt[root];
    }
    z ^= cnts;
    int temp;
    for (;fa[x]!=-1;)
    {
        temp = fa[x];
        fa[x] = root;
        int temp_cnt = cnts ^ cnt[x];
        cnt[x] = cnts;
        cnts = temp_cnt;
        x = temp;
    }
    return root;
}
void u(int x,int y,int z)
{
    x = findroot(x, z);
    y = findroot(y, z);
    if (x == y)
    {
        return;
    }
    if (size[x] > size[y])
    {
        swap(x,y);
    }
    size[y] += size[x];
    fa[x] = y;
    cnt[x] = z;
}
int ans[1005];
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
        int i,j;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for (i=0;i<n;i++)
        {
            fa[i] = -1;
            cnt[i] = 0;
            ans[i] = -1;
            size[i] = 1;
        }
        for (i=0;i<n;i++)
        {
            for (j=1;j<n;j++)
            {
                if (a[i][j] == a[j][i])
                {
                    continue;
                }
                else if (a[i][j] < a[j][i])
                {
                    u(i,j,0);
                }
                else
                {
                    u(i,j,1);
                }
            }
        }
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                if (ans[j] != -1)
                {
                    continue;
                }
                if (fa[j] == -1)
                {
                    ans[j] = 0;
                }
                if (ans[fa[j]] == -1)
                {
                    continue;
                }
                ans[j] = ans[fa[j]] ^ cnt[j];
            }
        }
        for (i=0;i<n;i++)
        {
            if (ans[i])
            {
                for (j=0;j<n;j++)
                {
                    swap(a[j][i],a[i][j]);
                }
            }
        }
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}