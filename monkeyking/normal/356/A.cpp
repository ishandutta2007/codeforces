#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stdio.h>
using namespace std;
int f[300005],n,q;
int nxt[300005];
int pre[300005];
int d[300005];

void init()
{
    cin>>n>>q;
    for(int i=0;i<n+1;i++)
    {
        d[i]=-1;
        nxt[i]=i+1;
        pre[i]=i-1;
    }
}

int find(int x)
{
    // cout<<x<<' ';
    return (d[nxt[x]]==-1?nxt[x]:nxt[x]=find(nxt[x]));
}

void merge(int x,int y)
{
    x=find(x);
    y=find(y);
    if(rand()&1)
    {
        f[x]=y;
    }
    else
    {
        f[y]=x;
    }
}

int main()
{
    init();
    int l,r,x;
    while(q--)
    {
        scanf("%d%d%d",&l,&r,&x);
        l--;
        x--;
        for(int i=(d[l]==-1?l:find(l));i<r;i=find(i))
        {
            if(i==x) continue;
            d[i]=x;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",d[i]+1);
    }
    return 0;
}