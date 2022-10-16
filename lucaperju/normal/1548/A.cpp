#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;
long long fct[200005],invfct[200005],inv[200005];
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
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=1;
    for(long long i=2;i<=200000;++i)
        inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
int cnt[200005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,j,k,m,n;
    cin>>n>>m;
    int cat=0;
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        cnt[min(a,b)]++;
    }
    for(i=1;i<=n;++i)
        if(cnt[i]==0)
            ++cat;
    int q;
    cin>>q;
    for(i=1;i<=q;++i)
    {
        int a,b,c;
        cin>>a;
        if(a==3)
        {
            cout<<cat<<'\n';
            continue;
        }
        cin>>b>>c;
        if(a==1)
        {
            if(cnt[min(b,c)]==0)
                --cat;
            ++cnt[min(b,c)];
        }
        else
        {
            if(cnt[min(b,c)]==1)
                ++cat;
            --cnt[min(b,c)];
        }
    }
    return 0;
}