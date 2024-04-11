#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

long long solve()
{
    long long n,k;

    scanf("%lld%lld",&n,&k);

    swap(n,k);

    long long ret=0,coeff=1;

    while(n)
    {
        ret=(ret+(n%2)*coeff)%mod;;
        coeff=coeff*k%mod;
        n=n/2;
    }

    return ret;
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