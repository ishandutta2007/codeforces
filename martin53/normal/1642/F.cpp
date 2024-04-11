#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42,mmax=5,inf=1e9+42,T=15;

int n,m;
pair< vector<int>, int> inp[nmax];

double start=clock();

vector<int> given;

mt19937 rng(42);

int hsh[nmax*mmax];

int dp[1<<T];

int main()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int cur;
            scanf("%i",&cur);
            inp[i].first.push_back(cur);

            given.push_back(cur);
        }

        scanf("%i",&inp[i].second);
    }

    sort(given.begin(),given.end());

    for(int i=1;i<=n;i++)
        for(auto &w:inp[i].first)
        {
            w=lower_bound(given.begin(),given.end(),w)-given.begin();
        }

    int output=2*inf;

    while(1.0*(clock()-start)/CLOCKS_PER_SEC<2.9)
    {
        for(int i=0;i<=n*m;i++)
            hsh[i]=rng()%T;

        for(int i=0;i<(1<<T);i++)
            dp[i]=inf;

        for(int i=1;i<=n;i++)
        {
            int mask=0;

            for(auto w:inp[i].first)
                mask=(mask|(1<<hsh[w]));

            dp[mask]=min(dp[mask],inp[i].second);
        }

        for(int i=0;i<(1<<T);i++)
            for(int j=0;j<T;j++)
                if((i&(1<<j))==0)
                {
                    dp[i+(1<<j)]=min(dp[i+(1<<j)],dp[i]);
                }

        for(int i=1;i<=n;i++)
        {
            int mask=0;

            for(auto w:inp[i].first)
                mask=(mask|(1<<hsh[w]));

            if(dp[(1<<T)-1-mask]!=inf)
                output=min(output,inp[i].second+dp[(1<<T)-1-mask]);
        }
    }

    if(output==2*inf)printf("-1\n");
    else printf("%i\n",output);

    return 0;
}