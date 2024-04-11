#include <bits/stdc++.h>

using namespace std;


/*
const long long mod = 998244353;

long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
        if(exp&1)
            exp^=1,rz=rz*1LL*a%mod;
        else
            exp>>=1,a=a*1LL*a%mod;
    return rz;
}
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=200000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
int t[1003];
int tata (int nod)
{
    if(t[nod]==nod || t[nod]==0)
        return nod;
    return t[nod]=tata(t[nod]);
}
int join (int a, int b)
{
    if(tata(a)==tata(b))
        return 1;
    t[tata(a)]=tata(b);
    return 0;
}
int a[1003],b[1003],cnt[1003];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long q,i,k,j,n;
    cin>>n>>k;
    for(i=1;i<=k;++i)
    {
        cin>>a[i]>>b[i];
    }
    for(int cur=1;cur<=k;++cur)
    {
        int cat=0;
        for(i=1;i<=n;++i)
            t[i]=0,cnt[i]=0;
        for(i=1;i<=cur;++i)
            cat+=join(a[i],b[i]);
        for(i=1;i<=n;++i)
            ++cnt[tata(i)];
        sort(cnt+1,cnt+n+1);
        int s=cnt[n]-1;
        for(i=n-1;i>=n-cat;--i)
            s+=cnt[i];
        cout<<s<<'\n';
    }
    return 0;
}