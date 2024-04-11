#include<bits/stdc++.h>
using namespace std;

const int nmax=2e3+42;

int n,k;
int inp[nmax];

int dp[nmax],help[nmax];

int solve()
{
    scanf("%i%i",&n,&k);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=0;i<=n;i++)dp[i]=-1;

    dp[0]=0;

    for(int i=1;i<=n;i++)
    {
        //delete
        for(int j=0;j<=n;j++)help[j]=dp[j];

        //take
        for(int j=1;j<=n;j++)help[j]=max(help[j],dp[j-1]);

        //take as fixed
        if(dp[inp[i]-1]!=-1)help[inp[i]]=max(help[inp[i]],dp[inp[i]-1]+1);

        for(int j=0;j<=n;j++)dp[j]=max(help[j],dp[j]);
    }

    int save=-1;

    for(int j=0;j<=n;j++)
        if(dp[j]>=k)save=n-j;

    return save;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%i\n",solve());
    }

    return 0;
}