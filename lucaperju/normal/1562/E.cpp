#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 998244353;
long long fct[400005],invfct[400005],inv[400005];
long long put2[400005];
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
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=400000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
long long putbz[5005];
char v[5005];
long long hsh[5005];
const int mod=1000000223;
const int bz=99;
long long gethsh (int l, int r)
{
    if(r<l)
        return 0;
    --l;
    return (hsh[r]-hsh[l]*1LL*putbz[r-l]%mod+mod)%mod;
}
map<int,int>mp;
int cc[5005][5005];
int dp[5005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,j,k,m,n,q;
    cin>>t;
  /*  ciur[0]=ciur[1]=1;
    for(i=2;i*i<=1000;++i)
    {
        if(!ciur[i])
        for(j=i*i;j<=1000;j+=i)
                ciur[j]=1;
    }*/
    putbz[0]=1;
    for(i=1;i<=5000;++i)
        putbz[i]=putbz[i-1]*1LL*bz%mod;
    while(t--)
    {
        cin>>n;
        cin>>(v+1);
        v[n+1]='.';
        cc[n+1][n+1]=0;
        for(i=n+1;i>=1;--i)
            for(j=n+1;j>=1;--j)
            {
                if(i==j && i==n+1)
                    continue;
                if(v[i]!=v[j])
                    cc[i][j]=0;
                else
                    cc[i][j]=1+cc[i+1][j+1];
            }
        int mx=n;
        dp[1]=n;
        for(i=2;i<=n;++i)
        {
            dp[i]=n-i+1;
            for(j=1;j<i;++j)
            {
                int vlc=cc[j][i];
                int ci=i,cj=j;
                ci+=vlc;
                cj+=vlc;
                if(v[cj]<v[ci])
                    dp[i]=max(dp[i],dp[j]+n-ci+1);
            }
            mx=max(mx,dp[i]);
        }
        mp.clear();
        cout<<mx<<'\n';
    }
    return 0;
}