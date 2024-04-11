#include<bits/stdc++.h>
using namespace std;

const int nmax=15,mod=1e9+7;

int inv(long long a)
{
    int b=mod-2;

    long long ret=1;

    while(b)
    {
        if(b%2)ret=ret*a%mod;
        a=a*a%mod;
        b=b/2;
    }

    return ret;
}

int n,inp[nmax];

int prob[nmax][nmax];

int mask_2_bits[nmax],pointer=0;

int direct(int mask_1,int mask_2)
{
    pointer=0;

    for(int i=0;i<n;i++)
        if((mask_2&(1<<i)))
        {
            mask_2_bits[pointer]=i;
            pointer++;
        }

    long long ret=1;

    for(int i=0;i<n;i++)
        if((mask_1&(1<<i)))
            for(int p=0;p<pointer;p++)
                ret=ret*prob[i][mask_2_bits[p]]%mod;

    return ret;
}

int dp[1<<nmax];

int prob_scc(int mask)
{
    if(dp[mask]!=-1)return dp[mask];

    int ret=1;

    for(int submask=(mask-1)&mask;submask;submask=(submask-1)&mask)
        ret=(ret-1LL*direct(submask,mask-submask)*prob_scc(submask))%mod;

    ret=(ret+mod)%mod;

    dp[mask]=ret;
    return ret;
}

int main()
{
    memset(dp,-1,sizeof(dp));

    scanf("%i",&n);
    for(int i=0;i<n;i++)scanf("%i",&inp[i]);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            prob[i][j]=1LL*inp[i]*inv(inp[i]+inp[j])%mod;

    int outp=0;

    for(int mask=1;mask<(1<<n);mask++)
    {
        long long cur=0;

        int mask_help=mask;

        while(mask_help)
        {
            cur+=mask_help%2;
            mask_help=mask_help/2;
        }

        cur=cur*direct(mask,(1<<n)-1-mask)%mod;

        cur=cur*prob_scc(mask)%mod;

        outp=(outp+cur)%mod;
    }

    printf("%i\n",outp);

    return 0;
}