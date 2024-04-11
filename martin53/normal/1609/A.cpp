#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

long long solve()
{
    scanf("%i",&n);

    int v2=0;

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);

        while(inp[i]%2==0)
        {
            inp[i]=inp[i]/2;
            v2++;
        }
    }

    long long outp=0;
    int mx=0;

    for(int i=1;i<=n;i++)
    {
        outp+=inp[i];
        mx=max(mx,inp[i]);
    }

    outp=outp-mx+1LL*mx*(1LL<<v2);

    return outp;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%lld\n",solve());
    }

    return 0;
}