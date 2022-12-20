#include<bits/stdc++.h>
using namespace std;

long long p;

long long ask(long long me)
{
    if(p%me==0)return 0;

    return me-p%me;
}
long long solve()
{
    scanf("%lld",&p);

    long long outp=2e18;

    for(int i=1;i<=3;i++)
    {
        long long val;

        scanf("%lld",&val);

        outp=min(outp,ask(val));
    }

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