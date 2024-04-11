#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=200010;
int n;
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
LL w[MAXN],d[MAXN],ans,sum;
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
LL gcd(LL a,LL b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
LL lcm(LL a,LL b)
{
    return a/gcd(a,b)*b;
}
void DFS(int x,int fa)
{
    LL M=1000000000000000000LL,tot=0;
    d[x]=1;
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa)
        {
            DFS(to[i],x);
            if(d[to[i]]>sum) {printf("%I64d\n",sum);exit(0);}
            d[x]=lcm(d[x],d[to[i]]),w[x]+=w[to[i]],M=min(M,w[to[i]]),++tot;
        }
    if(tot==0) return;
    M=(M/d[x])*d[x];
    ans+=w[x]-M*tot;
    w[x]=M*tot;
    d[x]*=tot;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%I64d",&w[i]),sum+=w[i];
    for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),adde(x,y);
    DFS(1,-1);
    printf("%I64d\n",ans);
    return 0;
}