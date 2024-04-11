#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,l,r,inp[nmax];

long long solve()
{
    scanf("%i%i%i",&n,&l,&r);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+n+1);

    long long outp=0;

    for(int i=1;i<=n;i++)
    {
        int lq=lower_bound(inp+1,inp+n+1,l-inp[i])-inp;

        int rq=upper_bound(inp+1,inp+n+1,r-inp[i])-inp-1;

        int on=rq-lq+1;

        if(lq<=i&&i<=rq)on--;

        outp+=on;
    }

    return outp/2;
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