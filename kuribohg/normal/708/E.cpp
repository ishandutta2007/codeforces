#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MOD=1000000007;
typedef long long LL;
LL qpow(LL x,LL n,LL MOD)
{
    LL p=x,con=1;
    while(n)
    {
        if(n&1) con=(con*p)%MOD;
        p=(p*p)%MOD;
        n>>=1;
    }
    return con;
}
int n,m;
LL a,b,k,P,fac[100010],inv[100010],p[100010];
LL f[1510][1510];
LL C(int n,int k)
{
    return ((fac[n]*inv[k])%MOD*inv[n-k])%MOD;
}
LL ans;
int main()
{
    cin>>n>>m>>a>>b>>k;
    P=(a*qpow(b,MOD-2,MOD))%MOD;
    fac[0]=1;
    for(int i=1;i<=k;i++) fac[i]=(fac[i-1]*i)%MOD;
    inv[k]=qpow(fac[k],MOD-2,MOD);
    for(int i=k-1;i>=0;i--) inv[i]=(inv[i+1]*(i+1))%MOD;
    for(int i=0;i<=k;i++) p[i]=((C(k,i)*qpow(P,i,MOD))%MOD*qpow((1-P+MOD)%MOD,k-i,MOD))%MOD;
    LL tmp=0;
    for(int i=1;i<=m;i++)
    {
        tmp=(tmp+p[i-1])%MOD;
        f[1][i]=(tmp*p[m-i])%MOD;
    }
    for(int i=2;i<=n;i++)
    {
        LL sp=0,sps=0,sr=0,srl=0,sm=0;
        for(int j=1;j<=m;j++)
            sr=(sr+f[i-1][j])%MOD;
        sm=sr;
        for(int j=1;j<=m;j++)
        {
            sr=(sr-f[i-1][m-j+1]+MOD)%MOD;
            sp=(sp+p[j-1])%MOD;
            srl=(srl+f[i-1][j-1])%MOD;
            sps=(sps+p[j-1]*srl)%MOD;
            LL Sp=(sp*p[m-j])%MOD;
            f[i][j]=(Sp*sm)%MOD;
            f[i][j]=(f[i][j]-(Sp*sr)%MOD+MOD)%MOD;
            f[i][j]=(f[i][j]-(sps*p[m-j])%MOD+MOD)%MOD;
        }
    }
    for(int i=1;i<=m;i++) ans=(ans+f[n][i])%MOD;
    cout<<ans<<endl;
    return 0;
}