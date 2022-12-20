#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;

int n,inp[nmax];

long long r1,r2,r3,dist;

long long dp[2][nmax];//is there a boss in the previous level, level

int main()
{
    scanf("%i%i%i%i%i",&n,&r1,&r2,&r3,&dist);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    dp[1][n+1]=1e18;

    for(int i=n;i>=1;i--)
        for(int type=0;type<2;type++)
        {
            if(type==0)
            {
                dp[0][i]=r1*inp[i]+r3+dist+dp[0][i+1];

                dp[0][i]=min(dp[0][i],r1*inp[i]+r1+dist+dp[1][i+1]);

                dp[0][i]=min(dp[0][i],r2+dist+dp[1][i+1]);
            }
            else
            {
                dp[1][i]=dist+r1+dist+dp[0][i];

                dp[1][i]=min(dp[1][i],r1*inp[i]+r3+dist+r1+dist+dist+dp[0][i+1]);

                dp[1][i]=min(dp[1][i],r1*inp[i]+r1+dist+r1+dist+min(r1+dist+dp[0][i+1],dist+dp[1][i+1]));

                dp[1][i]=min(dp[1][i],r2+dist+r1+dist+min(r1+dist+dp[0][i+1],dist+dp[1][i+1]));
            }

            if(i==n)dp[type][i]=dp[type][i]-dist;

            //cout<<i<<" "<<type<<" -> "<<dp[type][i]<<endl;
        }

    printf("%lld\n",dp[0][1]);
    return 0;
}