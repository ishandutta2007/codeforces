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
int a[200005];
int sum[1<<19];
int tag[1<<19];
const int maxn=1<<18;
void push_down(int num,int l,int r)
{
    if (tag[num]==1)
    {
        int mid=(l+r)/2;
        tag[num*2+1]=1;
        sum[num*2+1]=mid-l;
        tag[num*2+2]=1;
        sum[num*2+2]=r-mid;
        tag[num]=-1;
    }
    if (tag[num]==0)
    {
        int mid=(l+r)/2;
        tag[num*2+1]=0;
        sum[num*2+1]=0;
        tag[num*2+2]=0;
        sum[num*2+2]=0;
        tag[num]=-1;
    }
}
int find_next_0(int num,int l,int r,int x)
{
    if (sum[num]==0)
    {
        return max(x,l);
    }
    if (sum[num]==(r-l))
    {
        return -1;
    }
    if (l==r-1)
    {
        if (sum[num]==0)
        {
            return l;
        }
        return -1;
    }
    int mid = (l+r)/2;
    push_down(num,l,r);
    if (x<mid)
    {
        int val = find_next_0(num*2+1,l,mid,x);
        if (val!=-1)
        {
            return val;
        }
        return find_next_0(num*2+2,mid,r,x); 
    }
    else
    {
        return find_next_0(num*2+2,mid,r,x);
    }
}
int find_next_1(int num,int l,int r,int x)
{
    if (sum[num]==0)
    {
        return -1;
    }
    if (sum[num]==(r-l))
    {
        return max(x,l);
    }
    if (l==r-1)
    {
        if (sum[num]==1)
        {
            return l;
        }
        return -1;
    }
    int mid = (l+r)/2;
    push_down(num,l,r);
    if (x<mid)
    {
        int val = find_next_1(num*2+1,l,mid,x);
        if (val!=-1)
        {
            return val;
        }
        return find_next_1(num*2+2,mid,r,x); 
    }
    else
    {
        return find_next_1(num*2+2,mid,r,x);
    }
}
void change(int num,int l,int r,int l0,int r0,int x)
{
    if ((l0<=l)&&(r<=r0))
    {
        sum[num]=(r-l)*x;
        tag[num]=x;
        return;
    }
    int mid=(l+r)/2;
    push_down(num,l,r);
    if (l0<mid)
    {
        change(num*2+1,l,mid,l0,r0,x);
    }
    if (mid<r0)
    {
        change(num*2+2,mid,r,l0,r0,x);
    }
    sum[num]=sum[num*2+1]+sum[num*2+2];
}
void add_num(int x)
{
    int r = find_next_0(0,0,maxn,x);
    change(0,0,maxn,r,r+1,1);
    if (r!=x)
    {
        change(0,0,maxn,x,r,0);
    }
}
void remove_num(int x)
{
    int r = find_next_1(0,0,maxn,x);
    change(0,0,maxn,r,r+1,0);
    if (r!=x)
    {
        change(0,0,maxn,x,r,1);
    }
}
int find_max_1(int num,int l,int r)
{
    if (sum[num]==0)
    {
        return -1;
    }
    if (sum[num]==r-l)
    {
        return r-1;
    }
    int mid=(l+r)/2;
    int val = find_max_1(num*2+2,mid,r);
    if (val==-1)
    {
        return find_max_1(num*2+1,l,mid);
    }
    else
    {
        return val;
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,q;
    scanf("%d%d",&n,&q);
    int i;
    memset(tag,-1,sizeof(tag));
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        add_num(a[i]);
    }
    for (i=0;i<q;i++)
    {
        int k,l;
        scanf("%d%d",&k,&l);
        k--;
        remove_num(a[k]);
        a[k]=l;
        add_num(a[k]);
        printf("%d\n",find_max_1(0,0,maxn));
    }
    return 0;
}