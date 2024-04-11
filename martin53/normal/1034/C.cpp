#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42,mod=1e9+7;

int n;
long long inp[nmax];
int parent[nmax];

int cnt[nmax],dp[nmax];

int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&inp[i]);

    for(int i=2;i<=n;i++)scanf("%i",&parent[i]);

    for(int i=n;i>=2;i--)inp[parent[i]]=inp[parent[i]]+inp[i];

    for(int i=1;i<=n;i++)
    {
        long long g=__gcd(inp[i],inp[1]);

        long long cur=inp[1]/g;

        if(cur<=n)cnt[cur]++;
    }

    for(int i=n;i>=1;i--)
        for(int j=i+i;j<=n;j=j+i)
            cnt[j]+=cnt[i];

    //for(int i=1;i<=n;i++)cout<<i<<" -> "<<cnt[i]<<endl;

    dp[1]=1;

    int outp=0;
    for(int i=1;i<=n;i++)
        if(cnt[i]==i)
        {
            for(int j=i+i;j<=n;j=j+i)
            {
                dp[j]=(dp[j]+dp[i])%mod;
            }

            outp=(outp+dp[i])%mod;
        }

    printf("%i\n",outp);
    return 0;
}