#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=500010;
struct Node
{
    int x,w,a,b;
    friend bool operator<(const Node &p,const Node &q)
    {
        return p.x<q.x;
    }
}P[MAXN];
int BIT[MAXN],f[MAXN];
int n,a[MAXN],tot,ans;
inline int lowbit(int x){return x&(-x);}
void Change(int x,int tar)
{
    for(int i=x;i<=tot;i+=lowbit(i)) BIT[i]=max(BIT[i],tar);
}
int Query(int x)
{
    int con=0;
    for(int i=x;i>0;i^=lowbit(i))
        con=max(con,BIT[i]);
    return con;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&P[i].x,&P[i].w);
        P[i].a=P[i].x-P[i].w;
        P[i].b=P[i].x+P[i].w;
        a[++tot]=P[i].x-P[i].w;
        a[++tot]=P[i].x+P[i].w;
    }
    sort(a+1,a+tot+1);
    tot=unique(a+1,a+tot+1)-a-1;
    sort(P+1,P+n+1);
    for(int i=1;i<=n;i++) P[i].a=lower_bound(a+1,a+tot+1,P[i].a)-a,P[i].b=lower_bound(a+1,a+tot+1,P[i].b)-a;
    for(int i=1;i<=n;i++)
    {
        f[i]=Query(P[i].a)+1;
        Change(P[i].b,f[i]);
    }
    for(int i=1;i<=n;i++) ans=max(ans,f[i]);
    printf("%d\n",ans);
    return 0;
}