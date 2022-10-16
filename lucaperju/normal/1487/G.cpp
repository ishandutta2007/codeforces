#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 998244353;
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
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=200000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
int v[27];
long long dp1[403][403][2]; ///         poz; count;     is lastch == current
long long dp2[2][403][403][2][2]; /// poz; count(x2); --------||-------- x2
const int mod = 998244353;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,a,b,j,k,m,n;
    cin>>n;
    for(i=1;i<=26;++i)
        cin>>v[i];
    long long total=1;
    for(i=1;i<=n;++i)
    {
        if(i<=2)
            total=total*26LL%mod;
        else
            total=total*25LL%mod;
    }
    /// dp1 ---v
    dp1[0][0][0]=1;
    for(i=1;i<=n/2;++i)
        for(j=0;j<=n/2+1;++j)
        {
            dp1[i][j][0]=(dp1[i-1][j][0]*(long long)(24+(i==1))%mod+dp1[i-1][j][1]*25LL%mod)%mod;
            if(j)
                dp1[i][j][1]=dp1[i-1][j-1][0];
        }
    for(j=0;j<=n/2+1;++j)
    {
        dp1[i][j][0]=(dp1[i-1][j][0]+dp1[i-1][j][1])%mod*25LL%mod;
        if(j)
            dp1[i][j][1]=(dp1[i-1][j-1][0]+dp1[i-1][j-1][1])%mod;
    }
    for(++i;i<=n;++i)
        for(j=0;j<=n/2+1;++j)
        {
            dp1[i][j][0]=(dp1[i-1][j][0]*24LL%mod+dp1[i-1][j][1]*25LL%mod)%mod;
            if(j)
                dp1[i][j][1]=dp1[i-1][j-1][0];
        }
    for(j=n;j>=1;--j)
        dp1[n][j][0]=((dp1[n][j][0]+dp1[n][j][1])%mod+dp1[n][j+1][0])%mod;
    /// dp1 ---^
    /// dp2 ---v
    dp2[0][0][0][0][0]=1;
    int c1,c2;
    for(i=1;i<=n/2;++i)
        for(c1=0;c1<=n/2+1;++c1)
            for(c2=0;c2<=n/2+1;++c2)
            {
                dp2[i&1][c1][c2][0][0]=(dp2[1^(i&1)][c1][c2][0][0]*(long long)(23+(i==1))%mod+dp2[1^(i&1)][c1][c2][1][0]*24LL%mod+dp2[1^(i&1)][c1][c2][0][1]*24LL%mod)%mod;
                if(c1)
                    dp2[i&1][c1][c2][1][0]=(dp2[1^(i&1)][c1-1][c2][0][0]+dp2[1^(i&1)][c1-1][c2][0][1])%mod;
                if(c2)
                    dp2[i&1][c1][c2][0][1]=(dp2[1^(i&1)][c1][c2-1][0][0]+dp2[1^(i&1)][c1][c2-1][1][0])%mod;
            }
    for(c1=0;c1<=n/2+1;++c1)
        for(c2=0;c2<=n/2+1;++c2)
        {
            dp2[i&1][c1][c2][0][0]=(dp2[1^(i&1)][c1][c2][0][0]+dp2[1^(i&1)][c1][c2][1][0]+dp2[1^(i&1)][c1][c2][0][1])%mod*24LL%mod;
            if(c1)
                dp2[i&1][c1][c2][1][0]=(dp2[1^(i&1)][c1-1][c2][0][0]+dp2[1^(i&1)][c1-1][c2][0][1]+dp2[1^(i&1)][c1-1][c2][1][0])%mod;
            if(c2)
                dp2[i&1][c1][c2][0][1]=(dp2[1^(i&1)][c1][c2-1][0][0]+dp2[1^(i&1)][c1][c2-1][1][0]+dp2[1^(i&1)][c1][c2-1][0][1])%mod;
        }
    for(++i;i<=n;++i)
        for(c1=0;c1<=n/2+1;++c1)
            for(c2=0;c2<=n/2+1;++c2)
            {
                dp2[i&1][c1][c2][0][0]=(dp2[1^(i&1)][c1][c2][0][0]*23LL%mod+dp2[1^(i&1)][c1][c2][1][0]*24LL%mod+dp2[1^(i&1)][c1][c2][0][1]*24LL%mod)%mod;
                if(c1)
                    dp2[i&1][c1][c2][1][0]=(dp2[1^(i&1)][c1-1][c2][0][0]+dp2[1^(i&1)][c1-1][c2][0][1])%mod;
                if(c2)
                    dp2[i&1][c1][c2][0][1]=(dp2[1^(i&1)][c1][c2-1][0][0]+dp2[1^(i&1)][c1][c2-1][1][0])%mod;
            }
    for(c1=n;c1>=1;--c1)
        for(c2=n;c2>=1;--c2)
        {
            dp2[n&1][c1][c2][0][0]=(dp2[n&1][c1][c2][0][0]+dp2[n&1][c1][c2][1][0]+dp2[n&1][c1][c2][0][1])%mod;
            dp2[n&1][c1][c2][0][0]=(dp2[n&1][c1][c2][0][0]+dp2[n&1][c1+1][c2][0][0]+dp2[n&1][c1][c2+1][0][0]-dp2[n&1][c1+1][c2+1][0][0]+mod)%mod;
        }
    /// dp2 ---^
    for(a=1;a<=26;++a)
        total=(total-dp1[n][v[a]+1][0]+mod)%mod;
    for(a=1;a<=26;++a)
        for(b=a+1;b<=26;++b)
            total=(total+dp2[n&1][v[a]+1][v[b]+1][0][0])%mod;
    cout<<total;
    return 0;
}