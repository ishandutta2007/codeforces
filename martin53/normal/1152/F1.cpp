#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42,kmax=13,mmax=4,mod=1e9+7;

int dp[nmax][kmax][1<<mmax];

int n,k,m;

int bits[1<<mmax];

int main()
{
    scanf("%i%i%i",&n,&k,&m);

    for(int i=1;i<(1<<m);i++)
        bits[i]=bits[i/2]+i%2;

    dp[0][0][0]=1;

    int outp=0;

    for(int pos=0;pos<=n;pos++)
        for(int planets=0;planets<=k;planets++)
            for(int mask=0;mask<(1<<m);mask++)
            {
                int new_mask=(mask<<1)%(1<<m);

                //do not take
                dp[pos+1][planets][new_mask]=(dp[pos+1][planets][new_mask]+dp[pos][planets][mask])%mod;

                //take
                if(planets<k)
                {
                    new_mask=new_mask+1;
                    dp[pos+1][planets+1][new_mask]=(dp[pos+1][planets+1][new_mask]+1LL*dp[pos][planets][mask]*(bits[mask]+1))%mod;
                }

                //cout<<pos<<" "<<planets<<" "<<mask<<" -> "<<dp[pos][planets][mask]<<endl;

                if(pos==n&&planets==k)outp=(outp+dp[pos][planets][mask])%mod;
            }

    printf("%i\n",outp);

    return 0;
}