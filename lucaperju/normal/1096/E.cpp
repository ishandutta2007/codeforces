#include <bits/stdc++.h>

using namespace std;


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
long long getways (int n, int s, int mx)
{
    /// number of ways to write s as a sum of n players with all values < mx
    if(n==0 && s==0)
        return 1;
    if(n==0)
        return 0;
    long long ans=cmb(n+s-1,n-1);
    for(int cnt=1;cnt<=n;++cnt)
    {
        if(cnt&1)
        {
            ans=(ans-cmb(n+s-(mx*cnt)-1,n-1)*1LL*cmb(n,cnt)%mod+mod)%mod;
        }
        else
        {
            ans=(ans+cmb(n+s-(mx*cnt)-1,n-1)*1LL*cmb(n,cnt)%mod+mod)%mod;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,n,m,r,s,j,q;
    init();
    cin>>n>>s>>r;
    long long ans=0;
    for(int mxc=r;mxc<=s;++mxc) /// max value
        for(int cnt=1;cnt<=n && mxc*cnt<=s;++cnt) /// number of ppl with max value
        {
            long long vlc=getways(n-cnt,s-cnt*mxc,mxc);
            ans=(ans+vlc*1LL*inv[cnt]%mod*1LL*cmb(n-1,cnt-1)%mod*1LL*lgput(cmb(n+s-r-1,n-1),mod-2)%mod)%mod;
        }

    cout<<ans;
    return 0;
}