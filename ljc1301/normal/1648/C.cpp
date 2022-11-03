#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kcz=998244353;
const int maxn=200005;
const int maxk=200005;
int n,m,s[maxn],t[maxn],tr[maxk],k,cnt[maxk];
ll temp,fac[maxn],inv[maxn],invfac[maxn];
#define lowbit(x) ((x)&-(x))
inline void update(int x,ll z)
{
    for(;x<=k;x+=lowbit(x))
        (tr[x]+=z)%=kcz;
}
inline ll query(int x)
{
    ll res=0;
    for(;x;x-=lowbit(x))
        (res+=tr[x])%=kcz;
    return res;
}
int main()
{
    int i;
    ll ans=0,cur=1;
    scanf("%d%d",&n,&m),k=0;
    for(i=0;i<n;i++) scanf("%d",&s[i]),k=max(k,s[i]);
    for(i=0;i<m;i++) scanf("%d",&t[i]),k=max(k,t[i]);
    for(inv[1]=fac[0]=fac[1]=invfac[0]=invfac[1]=1,i=2;i<=n;i++)
        inv[i]=kcz-(kcz/i)*inv[kcz%i]%kcz,
        fac[i]=fac[i-1]*i%kcz,
        invfac[i]=invfac[i-1]*inv[i]%kcz;
    t[m]=1;
    for(i=1;i<=n;i++) tr[i]=0,cnt[i]=0;
    for(i=0;i<n;i++) cnt[s[i]]++;
    for(i=1;i<=k;i++) update(i,cnt[i]),(cur*=invfac[cnt[i]])%=kcz;
    for(i=0;i<=m && i<=n;i++)
    {
        if(i==n && n<m) { (ans+=1)%=kcz; break; }
        if(i==n) break;
        (ans+=cur*query(t[i]-1)%kcz*fac[n-1-i])%=kcz;
        // printf("%lld\n",cur*query(t[i]-1)%kcz*fac[n-1-i]%kcz);
        if(!cnt[t[i]]) break;
        (cur*=cnt[t[i]])%=kcz,cnt[t[i]]--,update(t[i],kcz-1);
    }
    printf("%lld\n",ans);
    return 0;
}