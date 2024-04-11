#include<bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
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
}*/
const int mod=998244353;
int l[51],r[51];
int ans[100003];
int dp[100005];
int sp[100005];
void add (int &a, int &b)
{
    a+=b;
    if(a>=mod)
        a-=mod;
}
void rem (int &a, int &b)
{
    a-=b;
    if(a<0)
        a+=mod;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,a,b,j,k,m,n;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>l[i]>>r[i];
    for(int vlc=1;vlc*n<=m;++vlc)
    {
        int lst=0;
        for(i=0;i<=m;i+=vlc)
            dp[i]=0,lst=i,sp[i]=0;
        dp[0]=1;
        for(i=1;i<=n;++i)
        {
            sp[0]=dp[0];
            for(int idk=vlc;idk<=m;idk+=vlc)
                sp[idk]=(sp[idk-vlc]+dp[idk])%mod;
            for(int pzc=lst;pzc>=(i-1)*vlc;pzc-=vlc)
            {
                int x;
                x=l[i]-l[i]%vlc;
                if(x<l[i])
                    x+=vlc;
                int y=r[i]-r[i]%vlc;
                if(pzc-x<0 || y<x)
                    dp[pzc]=0;
                else if(pzc-y-vlc<0)
                    dp[pzc]=sp[pzc-x];
                else
                    dp[pzc]=(sp[pzc-x]-sp[max(0,pzc-(r[i]-r[i]%vlc)-vlc)]+mod)%mod;
                //for(;x<=r[i] && x<=pzc;x+=vlc)
                //    add(dp[pzc],dp[pzc-x]);
            }
        }
        for(i=0;i<=m;i+=vlc)
            add(ans[vlc],dp[i]);
    }
    for(i=m;i>=1;--i)
    {
        for(j=i+i;j<=m;j+=i)
            rem(ans[i],ans[j]);
    }
    cout<<ans[1];
    return 0;
}