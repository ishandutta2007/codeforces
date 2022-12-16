#include<bits/stdc++.h>
using namespace std;

const int nmax=18,mod=998244353;

int n,m;

pair<int,int> inp[nmax*nmax];

int in[nmax];

long long ret=0;

int dir[nmax][nmax];

int adj[nmax];

bool edges[1<<nmax];

int bits[1<<nmax];

int dp[1<<nmax];

int main()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=m;i++)
    {
        scanf("%i%i",&inp[i].first,&inp[i].second);
        inp[i].first--;
        inp[i].second--;

        dir[inp[i].first][inp[i].second]=1;
        dir[inp[i].second][inp[i].first]=-1;

        adj[inp[i].first]+=(1<<inp[i].second);
        adj[inp[i].second]+=(1<<inp[i].first);
    }

    for(int i=0;i<(1<<n);i++)
        bits[i]=bits[i>>1]+(i&1);

    for(int state=1;state<(1<<n);state++)
    {
        for(int j=0;j<n;j++)
            if((state&(1<<j))&&(state&adj[j]))
                edges[state]=1;
        //cout<<state<<" -> "<<edges[state]<<endl;
    }

    dp[0]=1;
    for(int mask=1;mask<(1<<n);mask++)
    {
        for(int submask=mask;submask;submask=mask&(submask-1))//every vertex in submask has zero out-degree
            if(edges[submask]==0)
            {
                if((bits[submask]&1))dp[mask]=dp[mask]+dp[mask^submask];
                else dp[mask]=dp[mask]-dp[mask^submask]+mod;

                if(dp[mask]>=mod)dp[mask]=dp[mask]-mod;
            }
        //cout<<mask<<" -> "<<dp[mask]<<endl;
    }

    //cout<<dp[(1<<n)-1]<<endl;

    long long ret=(mod+1)/2;

    ret=ret*m%mod;

    ret=ret*dp[(1<<n)-1]%mod;

    printf("%lld\n",ret);
    return 0;
}