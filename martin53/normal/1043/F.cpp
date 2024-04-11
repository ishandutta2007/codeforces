#include<bits/stdc++.h>
using namespace std;

const int nmax=3e5+42,mod=1e9+7;

int n,inp[nmax];

int my_pow(long long a,int b)
{
    long long ret=1;

    while(b)
    {
        if(b%2)ret=ret*a%mod;

        b=b/2;

        a=a*a%mod;
    }
    return ret;
}

int mem_inv[nmax];

int cnt[nmax];

int dp[20][nmax];

set<int> seen;

int choose(int n_,int k_)
{
    if(n_<k_)return 0;

    long long ret=1;

    for(int i=1;i<=k_;i++)
    {
        ret=ret*(n_+1-i)%mod;
        ret=ret*mem_inv[i]%mod;
    }

    //cout<<"choose "<<n_<<" "<<k_<<" -> "<<ret<<endl;

    return ret;
}
int main()
{
    scanf("%i",&n);

    int g=0;

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);

        g=__gcd(g,inp[i]);

        if(seen.count(inp[i]))
        {
            n--;
            i--;
            continue;
        }

        seen.insert(inp[i]);
    }

    if(g!=1)
    {
        printf("-1\n");
        return 0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j*j<=inp[i];j++)
            if(inp[i]%j==0)
            {
                cnt[j]++;

                if(j!=inp[i]/j)cnt[inp[i]/j]++;
            }
    }

    for(int i=1;i<nmax;i++)mem_inv[i]=my_pow(i,mod-2);

    for(int groups=1;true;groups++)
    {
        for(int i=nmax-1;i>=1;i--)
        {
            dp[groups][i]=choose(cnt[i],groups);

            for(int j=2*i;j<nmax;j=j+i)
            {
                dp[groups][i]=(dp[groups][i]-dp[groups][j]+mod)%mod;
            }

            //if(dp[groups][i])cout<<groups<<" "<<i<<" -> "<<dp[groups][i]<<endl;
        }

        if(dp[groups][1])
        {
            printf("%i\n",groups);
            exit(0);
        }
    }
    return 0;
}