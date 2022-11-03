#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kcz=1000000007;
const int maxa=10000000;
const int maxn=500005;
int n,cnt[maxa+1],mu[maxa+1],p[maxa],tot,pow2[maxn],s[maxa+1];
bool vis[maxa+1];
int main()
{
    int i,j;
    ll ans;
    scanf("%d",&n);
    for(tot=0,i=0;i<=maxa;i++) cnt[i]=0,vis[i]=0;
    for(pow2[0]=1,i=1;i<=n;i++) pow2[i]=pow2[i-1]*2%kcz;
    for(i=0;i<n;i++) scanf("%d",&j),cnt[j]++;
    for(mu[1]=1,i=2;i<=maxa;i++)
    {
        if(!vis[i]) p[tot++]=i,mu[i]=-1;
        for(j=0;j<tot && i*p[j]<=maxa;j++)
        {
            vis[i*p[j]]=1;
            if(!(i%p[j])) { mu[i*p[j]]=0; break; }
            mu[i*p[j]]=-mu[i];
        }
    }
    for(i=0;i<tot;i++)
        for(j=maxa/p[i];j;j--)
            (cnt[j]+=cnt[j*p[i]])%=kcz;
    for(i=1;i<=maxa;i++) s[i]=pow2[cnt[i]]-1;
    for(ans=0,i=1;i<=maxa;i++) (ans+=(s[i]*mu[i]+kcz)%kcz)%=kcz;
    s[1]=(s[1]+kcz-ans)%kcz;
    for(ans=0,i=1;i<=maxa;i++) (ans+=(s[i]*(ll)cnt[i]%kcz*mu[i]+kcz)%kcz)%=kcz;
    printf("%lld\n",ans);
    return 0;
}