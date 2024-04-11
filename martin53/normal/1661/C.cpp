#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n;

long long inp[nmax];

bool can(long long turns,long long value)
{
    long long one=(turns+1)/2;
    long long two=turns-one;

    for(int i=1;i<=n;i++)
    {
        long long diff=value-inp[i];

        long long take_2=min(two,1LL*diff/2);

        two=two-take_2;
        diff=diff-2*take_2;

        if(one<diff)return 0;

        one=one-diff;
    }

    return 1;
}

bool test(long long av)
{
    return can(av,inp[n])||can(av,inp[n]+1);
}

long long solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%lld",&inp[i]);

    sort(inp+1,inp+n+1);

    long long ok=2*inp[n]*n,not_ok=-1;

    while(ok-not_ok>1)
    {
        long long av=(ok+not_ok)/2;

        if(test(av))ok=av;
        else not_ok=av;
    }

    return ok;
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