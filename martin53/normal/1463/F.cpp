#include<bits/stdc++.h>
using namespace std;

const int nmax=22;

int n,x,y;

int coeff[2*nmax+52];

int dp[2][1<<nmax];

int main()
{
    scanf("%i%i%i",&n,&x,&y);

    int sum=x+y;

    for(int i=1;i<=sum;i++)
        coeff[i]=(n-i+x+y)/(x+y);

    int modulo=1<<max(x,y);
    modulo--;

    int outp=0;

    for(int i=1;i<=x+y;i++)
    {
        for(int mask=0;mask<=modulo;mask++)
            dp[i&1][mask]=0;

        for(int mask=0;mask<=modulo;mask++)
        {
            for(int now=0;now<2;now++)
            {
                int mask_now=mask*2+now;
                mask_now=mask_now&modulo;

                if(now==1)
                {
                    if((mask&(1<<(x-1)))||(mask&(1<<(y-1))))
                    {
                        continue;
                    }
                }

                dp[i&1][mask_now]=max(dp[i&1][mask_now],dp[!(i&1)][mask]+coeff[i]*now);
            }

            //cout<<i<<" "<<mask<<" -> "<<dp[i&1][mask]<<endl;

            outp=max(outp,dp[i&1][mask]);
        }
    }

    printf("%i\n",outp);
    return 0;
}