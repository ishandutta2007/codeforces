#include<bits/stdc++.h>
using namespace std;
const int nmax=2e3+42,mod=998244353;
int n,m,k;
long long dp[nmax][nmax];
int main()
{
cin>>n>>m>>k;
dp[1][0]=m;
for(int pos=2;pos<=n;pos++)
    for(int dif=0;dif<pos;dif++)
    {
    if(dif)dp[pos][dif]=(dp[pos-1][dif-1]*(m-1));
    dp[pos][dif]+=dp[pos-1][dif];
    dp[pos][dif]=dp[pos][dif]%mod;
    }
cout<<dp[n][k]<<endl;
return 0;
}