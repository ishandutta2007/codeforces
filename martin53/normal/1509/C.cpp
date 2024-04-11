#include<bits/stdc++.h>
using namespace std;

const int nmax=2e3+42;

int n,inp[nmax];

long long dp[nmax][nmax];

long long rec(int l,int r)
{
    if(l>r)return 0;

    if(dp[l][r]!=-1)return dp[l][r];

    long long ret=inp[r]-inp[l]+min(rec(l+1,r),rec(l,r-1));

    dp[l][r]=ret;
    return ret;
}

int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+n+1);

    memset(dp,-1,sizeof(dp));

    printf("%lld\n",rec(1,n));

    return 0;
}