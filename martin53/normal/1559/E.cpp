#include<bits/stdc++.h>
using namespace std;

const int nmax=53,mod=998244353,MX=1e5+42;

int n,m;

pair<int,int> inp[nmax],new_inp[nmax];

int dvd[MX],exact[MX];

int dp[MX],help[MX],pref[MX];

int eval(int g)
{
    int upper=m/g;

    for(int i=1;i<=n;i++)
    {
        new_inp[i]={(inp[i].first+g-1)/g,inp[i].second/g};

        if(new_inp[i].first>new_inp[i].second)return 0;
    }

    for(int i=0;i<=upper;i++)dp[i]=0,help[i]=0,pref[i]=0;

    dp[0]=1;

    for(int i=1;i<=n;i++)
    {
        pref[0]=dp[0];

        for(int j=1;j<=upper;j++)
            pref[j]=(pref[j-1]+dp[j])%mod;

        for(int j=0;j<=upper;j++)
        {
            int from=max(0,j-new_inp[i].second);
            int to=j-new_inp[i].first;

            if(from<=to)help[j]=pref[to]-(from?pref[from-1]:0);
            else help[j]=0;

            help[j]=(help[j]+mod)%mod;
        }

        for(int j=0;j<=upper;j++)
            dp[j]=help[j];
    }

    int outp=0;

    for(int i=0;i<=upper;i++)
        outp=(outp+dp[i])%mod;

    return outp;
}
int main()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=n;i++)scanf("%i%i",&inp[i].first,&inp[i].second);

    for(int i=1;i<=m;i++)
        dvd[i]=eval(i);

    for(int i=m;i>=1;i--)
    {
        exact[i]=dvd[i];

        for(int j=2*i;j<=m;j=j+i)
            exact[i]=(exact[i]-exact[j]+mod)%mod;
    }

    printf("%i\n",exact[1]);

    return 0;
}