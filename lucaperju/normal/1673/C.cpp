#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;

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
const int mod=1000000007;
int dp[40004];
bool is_palindrome (int x)
{
    int cx=x;
    int s=0;
    while(cx)
    {
        s=s*10+cx%10;
        cx/=10;
    }
    if(x==s)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,k,m,j=0,tt,p,n;
    dp[0]=1;
    for(int val=1;val<=40000;++val)
    {
        if(is_palindrome(val))
        {
            for(i=val;i<=40000;++i)
                dp[i]=(dp[i]+dp[i-val])%mod;
        }
    }
    cin>>t;
    while(t--)
    {
        int a;
        cin>>a;
        cout<<dp[a]<<'\n';
    }
    return 0;
}