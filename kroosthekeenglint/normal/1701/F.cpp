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
int active[1<<20];
long long sum[1<<20];
long long tag1[1<<20];      // + ?
long long tag2[1<<20];      // +0, 1, ... ? times 
long long tag3[1<<20];      // +?, ... 1, 0 times 
int q,d;
const int max_n=1<<18;
void push_down(int num,int l,int r)
{
    if (r-l==2)
    {
        sum[num*2+1] += tag1[num];
        sum[num*2+2] += tag1[num];
    }
    else
    {
        sum[num*2+1] += (long long)tag1[num] * active[num*2+1];
        sum[num*2+2] += (long long)tag1[num] * active[num*2+2];
    }
    tag1[num*2+1] += tag1[num];
    tag1[num*2+2] += tag1[num];
    tag1[num] = 0;
    sum[num*2+1] += (long long)tag2[num] * (active[num*2+1] - 1) * active[num*2+1] / 2;
    sum[num*2+2] += (long long)tag2[num] * (active[num*2+2] - 1) * active[num*2+2] / 2;
    if (r-l==2)
    {
        sum[num*2+2] += tag2[num] * active[num*2+1];
    }
    else
    {
        sum[num*2+2] += (long long)tag2[num] * active[num*2+1] * active[num*2+2];
    }
    tag1[num*2+2] += (long long)tag2[num] * active[num*2+1]; 
    tag2[num*2+1] += tag2[num];
    tag2[num*2+2] += tag2[num];
    tag2[num] = 0;
    sum[num*2+1] += (long long)tag3[num] * (active[num*2+1] - 1) * active[num*2+1] / 2;
    sum[num*2+2] += (long long)tag3[num] * (active[num*2+2] - 1) * active[num*2+2] / 2;
    if (r-l==2)
    {
        sum[num*2+1] += tag3[num] * active[num*2+2];
    }
    else
    {
        sum[num*2+1] += (long long)tag3[num] * active[num*2+2] * active[num*2+1];
    }
    tag1[num*2+1] += (long long)tag3[num] * active[num*2+2]; 
    tag3[num*2+1] += tag3[num];
    tag3[num*2+2] += tag3[num];
    tag3[num] = 0;
}
void push_up(int num,int l,int r)
{
    active[num] = active[num*2+1] + active[num*2+2]; 
    if (r-l==2)
    {
        sum[num] = sum[num*2+1] * active[num*2+1] + sum[num*2+2] * active[num*2+2];
    }
    else
    {
        sum[num] = sum[num*2+1] + sum[num*2+2];
    }
}
void change(int num,int l,int r,int x,int d)
{
    if (l==r-1)
    {
        active[num]+=d;
        return;
    }
    push_down(num,l,r);
    int mid=(l+r)/2;
    if (x<mid)
    {
        change(num*2+1,l,mid,x,d);
    }
    else
    {
        change(num*2+2,mid,r,x,d);
    }
    push_up(num,l,r);
}
int query_sum(int num,int l,int r,int l0,int r0)
{
    if ((l0<=l)&&(r<=r0))
    {
        return active[num];
    }
    push_down(num,l,r);
    int mid=(l+r)/2;
    int sum_ans = 0;
    if (l0<mid)
    {
        sum_ans += query_sum(num*2+1,l,mid,l0,r0);
    }
    if (mid<r0)
    {
        sum_ans += query_sum(num*2+2,mid,r,l0,r0);
    }
    return sum_ans;
}
void change_tag1(int num,int l,int r,int l0,int r0,long long d)
{
    if ((l0<=l)&&(r<=r0))
    {
        if (l==r-1)
        {
            sum[num]+=d;
        }
        else
        {
            sum[num]+=active[num]*d;
        }
        tag1[num] += d;
        return;
    }
    push_down(num,l,r);
    int mid=(l+r)/2;
    if (l0<mid)
    {
        change_tag1(num*2+1,l,mid,l0,r0,d);
    }
    if (mid<r0)
    {
        change_tag1(num*2+2,mid,r,l0,r0,d);
    }
    push_up(num,l,r);
}
void change_tag2(int num,int l,int r,int l0,int r0,int d)
{
    if ((l0<=l)&&(r<=r0))
    {
        sum[num]+=(long long)active[num]*(active[num]-1)/2*d;
        tag2[num] += d;
        return;
    }
    push_down(num,l,r);
    int mid=(l+r)/2;
    int l_val = 0;
    if (l0<mid)
    {
        change_tag2(num*2+1,l,mid,l0,r0,d);
        l_val = query_sum(num*2+1,l,mid,l0,r0);
    }
    if (mid<r0)
    {
        change_tag1(num*2+2,mid,r,l0,r0,(long long)d*l_val);
        change_tag2(num*2+2,mid,r,l0,r0,d);
    }
    push_up(num,l,r);
}
void change_tag3(int num,int l,int r,int l0,int r0,int d)
{
    if ((l0<=l)&&(r<=r0))
    {
        sum[num]+=(long long)active[num]*(active[num]-1)/2*d;
        tag3[num] += d;
        return;
    }
    push_down(num,l,r);
    int mid=(l+r)/2;
    int r_val = 0;
    if (mid<r0)
    {
        change_tag3(num*2+2,mid,r,l0,r0,d);
        r_val = query_sum(num*2+2,mid,r,l0,r0);
    }
    if (l0<mid)
    {
        change_tag1(num*2+1,l,mid,l0,r0,(long long)d*r_val);
        change_tag3(num*2+1,l,mid,l0,r0,d);
    }
    push_up(num,l,r);
}
void add_vertix(int i,int flag)
{
    int l_point = max(i-d, 1);
    int r_point = min(i+d+1, max_n);
    change_tag2(0,0,max_n,l_point,i,flag);
    change_tag3(0,0,max_n,i+1,r_point,flag);
    change(0,0,max_n,i,flag);
}
bool a[200005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d%d",&q,&d);
    int i;
    for (i=0;i<q;i++)
    {
        int x;
        scanf("%d",&x);
        a[x]^=1;
        if (a[x]==1)
        {
            add_vertix(x, 1);
        }
        else
        {
            add_vertix(x, -1);
        }
        printf("%lld\n",sum[0]);
    }
    return 0;
}