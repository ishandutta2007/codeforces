#include <bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int p[maxn],tot,phi[maxn],b[maxn];
bool vis[maxn];
inline void sieve(int n)
{
    int i,j;
    for(i=2;i<=n;i++) vis[i]=0;
    for(i=2,tot=0;i<=n;i++)
    {
        if(!vis[i]) p[tot++]=i,phi[i]=i-1;
        for(j=0;j<tot && i*(long long)p[j]<=n;j++)
        {
            vis[i*p[j]]=1;
            if(!(i%p[j])) { phi[i*p[j]]=phi[i]*p[j]; break; }
            phi[i*p[j]]=phi[i]*(p[j]-1);
        }
    }
}
int main()
{
    int i,n,k,m;
    long long ans=1;
    scanf("%d%d",&n,&k);
    sieve(n);
    for(i=3,m=0;i<=n;i++)
        b[m++]=phi[i];
    sort(b,b+m);
    for(i=0;i<k;i++) ans+=b[i];
    printf("%lld\n",ans+(k>1));
    return 0;
}