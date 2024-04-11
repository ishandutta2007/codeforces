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
int min_val[1<<20];
int max_val[1<<20];
int a[1<<20];
int n;
void build_tree(int num,int l,int r)
{
    if (l==r-1)
    {
        min_val[num]=a[l];
        max_val[num]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build_tree(num*2+1,l,mid);
    build_tree(num*2+2,mid,r);
    min_val[num]=min(min_val[num*2+1],min_val[num*2+2]);
    max_val[num]=max(max_val[num*2+1],max_val[num*2+2]);
}
int query_min(int num,int l,int r,int l0,int r0)
{
    if ((l0<=l)&&(r<=r0))
    {
        return min_val[num];
    }
    int mid=(l+r)/2;
    int min_val=99999999;
    if (l0<mid)
    {
        min_val=min(min_val,query_min(num*2+1,l,mid,l0,r0));
    }
    if (mid<r0)
    {
        min_val=min(min_val,query_min(num*2+2,mid,r,l0,r0));
    }
    return min_val;
}
int query_max(int num,int l,int r,int l0,int r0)
{
    if ((l0<=l)&&(r<=r0))
    {
        return max_val[num];
    }
    int mid=(l+r)/2;
    int max_val=0;
    if (l0<mid)
    {
        max_val=max(max_val,query_max(num*2+1,l,mid,l0,r0));
    }
    if (mid<r0)
    {
        max_val=max(max_val,query_max(num*2+2,mid,r,l0,r0));
    }
    return max_val;
}
int find_min(int x)
{
    int l = x + 1, r = n - 1;
    for (;l<=r;)
    {
        int mid=(l+r)/2;
        if (query_min(0,0,n,x,mid) < a[x])
        {
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    return l;
}
int find_max(int x)
{
    int l = x + 1, r = n - 1;
    for (;l<=r;)
    {
        int mid=(l+r)/2;
        if (query_max(0,0,n,x,mid) > a[x])
        {
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    return l;
}
int pos[1<<20];
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
        scanf("%d",&n);
        int i;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            pos[a[i]]=i;
        }
        build_tree(0,0,n);
        int now = 0;
        int sum = 0;
        for (;;)
        {
            if (now == n-1)
            {
                break;
            }
            if (a[now + 1] > a[now])
            {
                int end_point = find_min(now);
                now = pos[query_max(0,0,n,now,end_point)];
            }
            else
            {
                int end_point = find_max(now);
                now = pos[query_min(0,0,n,now,end_point)];
            }
            sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}