#include<bits/stdc++.h>
using namespace std;

const int MX=2e5+42;
int cnt[MX];

int dp[MX];

int solve()
{
    memset(cnt,0,sizeof(cnt));
    memset(dp,0,sizeof(dp));

    int n;
    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);
        cnt[cur]++;
    }

    for(int i=MX-1;i>=1;i--)
    {
        for(int j=2;i*j<MX;j++)
            dp[i]=max(dp[i],dp[i*j]);

        dp[i]+=cnt[i];
    }

    return n-dp[1];
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