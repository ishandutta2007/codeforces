#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const LL INF=4000000000000000000LL;
struct Node
{
    LL x;
    int k,S;
    friend bool operator<(const Node &p,const Node &q)
    {
        return p.k<q.k;
    }
}A[110];
int n,m;
LL B,f[2][2000010],ans=INF;
int main()
{
    scanf("%d%d%I64d",&n,&m,&B);
    for(int i=1,x,y;i<=n;i++)
    {
        scanf("%I64d%d%d",&A[i].x,&A[i].k,&x);
        for(int j=1;j<=x;j++) scanf("%d",&y),A[i].S|=(1<<(y-1));
    }
    for(int i=1;i<(1<<m);i++) f[0][i]=INF;
    sort(A+1,A+n+1);
    for(int i=1;i<=n;i++)
    {
        int now=i&1,pre=now^1;
        for(int j=0;j<(1<<m);j++) f[now][j]=f[pre][j];
        for(int j=0;j<(1<<m);j++)
            f[now][j|A[i].S]=min(f[now][j|A[i].S],f[pre][j]+A[i].x);
        ans=min(ans,f[now][(1<<m)-1]+A[i].k*B);
    }
    if(ans==INF) puts("-1");
    else printf("%I64d\n",ans);
    return 0;
}