#include<bits/stdc++.h>
using namespace std;

const int nmax=101;

int n,a[nmax],b[nmax];

int dp[nmax][nmax*nmax];

int rec(int pos,int sum_a,int sum_b)
{
    if(pos>n)return 0;

    if(dp[pos][sum_a]!=-1)return dp[pos][sum_a];

    dp[pos][sum_a]=min(rec(pos+1,sum_a+a[pos],sum_b+b[pos])+2*sum_a*a[pos]+2*sum_b*b[pos],rec(pos+1,sum_a+b[pos],sum_b+a[pos])+2*sum_a*b[pos]+2*sum_b*a[pos]);

    return dp[pos][sum_a];
}

int solve()
{
    memset(dp,-1,sizeof(dp));

    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&a[i]);

    for(int i=1;i<=n;i++)scanf("%i",&b[i]);

    int ret=0;

    for(int i=1;i<=n;i++)ret+=(n-1)*(a[i]*a[i]+b[i]*b[i]);

    return ret+rec(1,0,0);
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