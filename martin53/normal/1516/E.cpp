#include<bits/stdc++.h>
using namespace std;

const int kmax=500+42,mod=1e9+7;

int n,k;

int dp[kmax][kmax];

int outp[kmax];

long long inv[kmax];

long long normal(long long val)
{
    //cout<<"normal "<<val<<endl;

    val=val%mod;
    return val;
}
int main()
{
    inv[1]=1;
    for(int i=2;i<kmax;i++)inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;

    scanf("%i%i",&n,&k);

    dp[0][0]=1;

    for(int cur=2;cur<=k+1;cur++)
    {
        for(int sum_all=min(2*k,n);sum_all>=0;sum_all--)
            for(int sum_cost=min(k,n);sum_cost>=0;sum_cost--)
            {
                if(dp[sum_all][sum_cost]==0)continue;

                long long coeff=1;

                //cout<<"gaz "<<sum_all<<" "<<sum_cost<<endl;

                for(int now=1;sum_cost+now*(cur-1)<=k;now++)
                {
                    //cout<<"? "<<now<<endl;

                    if(sum_all+now*cur>n)break;

                    coeff=coeff*inv[cur]%mod;

                    coeff=coeff*inv[now]%mod;

                    int nums=n-sum_all-cur*(now-1);

                    for(int t=0;t<cur;t++)
                        coeff=coeff*(nums-t)%mod;

                    //cout<<sum_all<<" "<<sum_cost<<" "<<now<<" -> coeff= "<<coeff<<endl;

                    dp[sum_all+now*cur][sum_cost+now*(cur-1)]=normal(dp[sum_all+now*cur][sum_cost+now*(cur-1)]+dp[sum_all][sum_cost]*coeff%mod);
                }
            }

        /*
        cout<<"cur= "<<cur<<endl;
        for(int sum_all=min(2*k,n);sum_all>=0;sum_all--)
            for(int sum_cost=min(k,n);sum_cost>=0;sum_cost--)
            {
                if(dp[sum_all][sum_cost]==0)continue;
                cout<<sum_all<<" "<<sum_cost<<" -> "<<dp[sum_all][sum_cost]<<endl;
            }
        */
    }

    for(int i=0;i<=2*k;i++)
        for(int j=0;j<=k;j++)
            outp[j]=(outp[j]+dp[i][j])%mod;

    for(int i=2;i<=k;i++)
        outp[i]=(outp[i-2]+outp[i])%mod;

    for(int i=1;i<=k;i++)printf("%i ",outp[i]);
    printf("\n");

    return 0;
}