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
struct statement
{
    int l;
    int r;
    int x;
    void read()
    {
        scanf("%d%d%d",&l,&r,&x);
        l--;
        r--;
        if (l>r)
        {
            swap(l,r);
        }
    }
    friend bool operator < (const statement &a, const statement &b)
    {
        if (a.l == b.l)
        {
            return a.r<b.r;
        }
        return a.l<b.l;
    }
};
statement a[200005];
int ans[200005];
int tag[200005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    for (i=0;i<n;i++)
    {
        ans[i]=0;
    }
    for (i=0;i<m;i++)
    {
        a[i].read();
        if (a[i].l == a[i].r)
        {
            ans[a[i].l] |= a[i].x;
        }
    }
    sort(a,a+m);
    int j;
    for (j=30;j>=0;j--)
    {
        for (i=0;i<n;i++)
        {
            tag[i] = 0;
        }
        for (i=0;i<m;i++)
        {
            if ((a[i].x & (1<<j)) == 0)
            {
                tag[a[i].l] = -1;
                tag[a[i].r] = -1;
            }
        }
        for (i=0;i<m;i++)
        {
            if ((a[i].x & (1<<j)))
            {
                if (tag[a[i].l] == -1)
                {
                    tag[a[i].r] = 1;
                    ans[a[i].r] |= (1<<j);
                }
                if (tag[a[i].r] == -1)
                {
                    tag[a[i].l] = 1;
                    ans[a[i].l] |= (1<<j);
                }
            }
        }
        for (i=0;i<m;i++)
        {
            if (a[i].x & (1<<j))
            {
                if ((ans[a[i].l] & (1<<j)))
                {
                    continue;
                }
                ans[a[i].r] |= (1<<j);
            }
        }
    }
    for (i=0;i<n;i++)
    {
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}