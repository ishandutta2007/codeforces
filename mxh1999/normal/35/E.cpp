//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

#define maxn 100010
struct Building
{
    int l,r,h;
    void read()
    {
        scanf("%d%d%d",&h,&l,&r);
    }
    bool operator<(const Building &rhs) const
    {
        return h<rhs.h;
    }
}   gui[maxn];
int n,len;
int key[maxn<<1];
int ans[maxn<<1],sum;

bool cmp(const Building &a,const Building &b)
{
    return a.l<b.l;
};
priority_queue<Building>    Q;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        gui[i].read();
    for (int i=1;i<=n;i++)  key[2*i-1]=gui[i].l,key[2*i]=gui[i].r;
    sort(key+1,key+2*n+1);
    len=1,key[1];
    for (int i=2;i<=2*n;i++)
    if (key[i]!=key[len])
        key[++len]=key[i];
    sort(gui+1,gui+n+1,cmp);
    int h=1;
    for (int i=1;i<=len;i++)
    {
        while (h<=n && gui[h].l<=key[i])    Q.push(gui[h]),h++;
        while (!Q.empty() && Q.top().r<=key[i]) Q.pop();
        if (!Q.empty()) ans[i]=Q.top().h;else ans[i]=0;
    }
    int tmp=0;
    for (int i=1;i<=len;i++)
    {
        if (ans[i]!=tmp)
        {
            //printf("%d %d\n",key[i],tmp);
            //printf("%d %d\n",key[i],ans[i]);
            sum+=2;
            tmp=ans[i];
        }
    }
    printf("%d\n",sum);
    tmp=0;
    for (int i=1;i<=len;i++)
    {
        if (ans[i]!=tmp)
        {
            printf("%d %d\n",key[i],tmp);
            printf("%d %d\n",key[i],ans[i]);
            //sum+=2;
            tmp=ans[i];
        }
    }
    return 0;
}