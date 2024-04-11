#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int mod=998244353;
long long dp[5003][5003];
long long lgput (long long val)
{
    long long exp=mod-2;
    long long rez=1;
    while(exp)
    {
        if(exp&1)
        {
            rez=(rez*1LL*val)%mod;
            exp^=1;
        }
        else
        {
            val=(val*1LL*val)%mod;
            exp>>=1;
        }
    }
    return rez;
}
int main()
{
    long long n,m,k,i,j,s=0,a=0,b=0,rz=0;
    cin>>n>>m>>k;
    dp[0][0]=1;
    for(i=1;i<=k;++i)
        for(j=1;j<=k;++j)
            dp[i][j]=((dp[i-1][j]*1LL*j)%mod+(dp[i-1][j-1]*(n-(j-1)))%mod)%mod;
    long long cur=m;
    for(i=1;i<=k;++i)
    {
        rz=(rz+(dp[k][i]*1LL*lgput(cur))%mod)%mod;
        cur=(cur*1LL*m)%mod;
    }
    cout<<rz;
    return 0;
}