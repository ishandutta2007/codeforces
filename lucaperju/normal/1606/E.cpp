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
long long dp[505][505];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long m,q,t,s=0,n,d,i,k;
    cin>>n>>k;
    init();
    for(i=1;i<=k;++i)
    {
        dp[0][i]=0;
        dp[1][i]=i;
    }
    for(int j=1;j<=k;++j)
        for(i=2;i<=n;++i)
        {
            if(j<=(i-1))
            {
                dp[i][j]=0;
                continue;
            }
            for(int x=0;x<=i;++x)
            {
                /** dp(n,k)
                    toti isi iau n-1 dmg
                    pp ca o sa moara x => vin din dp[n-x][k-(n-1)] cu coef cmb(n,x)*(n-1)^x
                */
                dp[i][j]=(dp[i][j]+dp[i-x][j-(i-1)]*1LL*cmb(i,x)%mod*1LL*lgput(i-1,x)%mod)%mod;
            }
        }
    cout<<(lgput(k,n)-dp[n][k]+mod)%mod;
    return 0;
}