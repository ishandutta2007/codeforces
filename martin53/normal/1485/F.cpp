#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42,mod=1e9+7;

int n,inp[nmax];

long long suff[nmax];

map<long long,int> seen;

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    suff[n+1]=0;
    suff[n]=inp[n];
    for(int i=n-1;i>=1;i--)suff[i]=suff[i+1]+inp[i];

    seen={};

    seen[suff[1]]=1;

    long long sum=1;

    for(int i=1;i<=n;i++)
    {
        long long add=sum-seen[suff[i]];

        add=(add+mod)%mod;

        seen[suff[i]]=(seen[suff[i]]+add)%mod;

        sum=(sum+add)%mod;
    }

    printf("%lld\n",sum);
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}