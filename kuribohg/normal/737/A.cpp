#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
int n,k,s,t;
int gas[MAXN];
struct Node
{
    int c,v;
    friend bool operator<(const Node &p,const Node &q)
    {
        return p.c<q.c;
    }
}P[MAXN];
int pre[MAXN];
int check(int o)
{
    int tt=0;
    for(int i=1;i<=k;i++)
    {
        int x=gas[i]-gas[i-1];
        if(o<x) return 2147483647;
        tt+=max(x,2*x-(o-x));
    }
    return tt;
}
int main()
{
    scanf("%d%d%d%d",&n,&k,&s,&t);
    for(int i=1;i<=n;i++) scanf("%d%d",&P[i].c,&P[i].v);
    for(int i=1;i<=k;i++) scanf("%d",&gas[i]);
    sort(gas+1,gas+k+1);
    gas[++k]=s;
    int l=1,r=n;
    sort(P+1,P+n+1);
    for(int i=1;i<=n;i++) pre[i]=max(pre[i-1],P[i].v);
    while(l<r)
    {
        int mid=(l+r)>>1;
        int o=pre[mid];
        int tt=check(o);
        if(tt<=t) r=mid;
        else l=mid+1;
    }
    if(check(pre[l])>t) puts("-1");
    else printf("%d\n",P[l].c);
    return 0;
}