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
int a[1<<18];
int val[1<<19];
void build_tree(int num,int l,int r)
{
    if (l==r-1)
    {
        val[num]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build_tree(num*2+1,l,mid);
    build_tree(num*2+2,mid,r);
    val[num]=max(val[num*2+1],val[num*2+2]);
}
int query(int num,int l,int r,int l0,int r0)
{
    if ((l0<=l)&&(r<=r0))
    {
        return val[num];
    }
    int ans=0;
    int mid=(l+r)/2;
    if (l0<mid)
    {
        ans=max(ans,query(num*2+1,l,mid,l0,r0));
    }
    if (mid<r0)
    {
        ans=max(ans,query(num*2+2,mid,r,l0,r0));
    }
    return ans;
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
        scanf("%d",&a[i]);
    }
    build_tree(0,0,m);
    int q;
    scanf("%d",&q);
    for (i=0;i<q;i++)
    {
        int x1,y1,x2,y2,k;
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&k);
        y1--;
        y2--;
        if (((x2-x1)%k==0)&&((y2-y1)%k==0))
        {
            if (y1>y2)
            {
                swap(y1,y2);
            }
            y2++;
            int val = query(0,0,m,y1,y2);
            int x = x1%k;
            x += n/k*k;
            if (x>n)
            {
                x-=k;
            }
            if (x>val)
            {
                puts("YES");
            }
            else
            {
                puts("NO");
            }
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}