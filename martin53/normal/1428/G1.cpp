#include<bits/stdc++.h>
using namespace std;

const int MX=1e6+42;

int k;

int f[6];

long long dp[MX];

long long eval(int val)
{
    //cout<<val<<" -> ";

    long long ret=0;

    for(int dig=0;dig<6;dig++)
    {
        int d=val%10;

        if(d%3==0)ret=ret+1LL*d/3*f[dig];
        val=val/10;
    }

    //cout<<"ret= "<<ret<<endl;

    return ret;
}

void push(long long object,long long gain)
{
    if(object>=MX)return;

    for(int i=MX-1;i>=object;i--)
        dp[i]=max(dp[i],dp[i-object]+gain);
}
void prec()
{
    for(int i=0;i<MX;i++)dp[i]=-1e18;
    dp[0]=0;

    for(int dig=0;dig<6;dig++)
    {
        int mult=1;

        for(int t=0;t<dig;t++)mult=mult*10;

        mult=mult*3;

        long long remain=3*(k-1),object=mult,gain=f[dig];

        while(remain)
        {
            if(remain%2==0)
            {
                push(object,gain);
                remain--;
            }

            if(remain%2==1)
            {
                push(object,gain);
                remain--;
            }

            object=object*2;
            gain=gain*2;
            remain=remain/2;
        }
    }
    /*
    for(int i=0;i<MX;i++)
        if(dp[i]>=0)
            cout<<i<<" -> "<<dp[i]<<endl;
    */
}

long long solve(int cur)
{
    long long ret=0;
    for(int i=0;i<=cur;i++)
        ret=max(ret,dp[i]+eval(cur-i));

    return ret;
}
int main()
{
    scanf("%i",&k);
    for(int i=0;i<6;i++)scanf("%i",&f[i]);

    prec();

    int q;
    scanf("%i",&q);

    for(int i=1;i<=q;i++)
    {
        int val;
        scanf("%i",&val);
        printf("%lld\n",solve(val));
    }
    return 0;
}