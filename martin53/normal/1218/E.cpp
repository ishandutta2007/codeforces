#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;
const int nmax=2e4+42,mod=998244353;

int n,k,arr[nmax];

int help[nmax];

int dp[nmax];
int solve()
{
    dp[0]=1;
    for(int position=1;position<=n;position++)
    {
        dp[position]=0;

        int lower=1;
        lower=max(lower,k+position-n-1);

        for(int j=min(position,k);j>=lower;j--)
            dp[j]=(dp[j]+1LL*help[position]*dp[j-1])%mod;
    }
    return dp[k];
}
int main()
{
    scanf("%i%i",&n,&k);
    for(int i=1;i<=n;i++)scanf("%i",&arr[i]);
    int q;
    scanf("%i",&q);


    while(q)
    {
        for(int i=1;i<=n;i++)help[i]=arr[i];

        int type,rem;
        scanf("%i%i",&type,&rem);
        if(type==1)
        {
            int position,value;
            scanf("%i%i",&position,&value);
            help[position]=value;
        }
        else
        {
            int l,r,value;
            scanf("%i%i%i",&l,&r,&value);
            for(int j=l;j<=r;j++)
                help[j]=help[j]+value;
        }

        for(int j=1;j<=n;j++)
            help[j]=((rem-help[j])%mod+mod)%mod;
        printf("%i\n",solve());
        q--;
    }
    return 0;
}