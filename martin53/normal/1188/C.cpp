#include<bits/stdc++.h>
using namespace std;
const int nmax=1e3+42,mod=998244353;

int n,k,inp[nmax];

int dp[2][nmax],sums[2][nmax];

void make_pref(int id)
{
    sums[id&1][0]=dp[id&1][0];
    for(int i=1;i<=n;i++)
        sums[id&1][i]=(sums[id&1][i-1]+dp[id&1][i])%mod;
}
long long eval(int mini)
{
    //cout<<"mini= "<<mini<<endl;

    memset(dp,0,sizeof(dp));
    memset(sums,0,sizeof(sums));

    dp[0][0]=1;
    make_pref(0);

    for(int nums=1;nums<=k;nums++)
    {
        dp[nums&1][0]=0;
        int j=1;
        for(int pos=1;pos<=n;pos++)
        {
            while(j<=pos&&inp[pos]-inp[j]>=mini)j++;
            //j is the first invalid
            dp[nums&1][pos]=sums[!(nums&1)][j-1];
            //cout<<nums<<" "<<pos<<" -> "<<dp[nums&1][pos]<<endl;
        }
        make_pref(nums&1);
    }

    int ret=0;
    for(int i=1;i<=n;i++)
        ret=(ret+dp[k&1][i])%mod;
    //cout<<mini<<" -> "<<ret<<endl;
    return ret;
}
int main()
{
    scanf("%i%i",&n,&k);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+n+1);

    long long output=0;
    long long prev=0;
    for(int i=(inp[n]-inp[1])/(k-1);i>=1;i--)
    {
        long long now=eval(i);
        output=output+(now-prev)*i%mod;
        output=output%mod;
        output=(output+mod)%mod;

        prev=now;
    }
    printf("%i\n",output);
    return 0;
}