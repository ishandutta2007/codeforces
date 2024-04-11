#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,k,inp[nmax];

long long solve()
{
    scanf("%i%i",&n,&k);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+n+1);

    long long outp=0;
    for(int i=1;i<=k;i++)outp+=inp[n-2*k+i]/inp[n-k+i];

    for(int i=n-2*k;i>=1;i--)outp+=inp[i];

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