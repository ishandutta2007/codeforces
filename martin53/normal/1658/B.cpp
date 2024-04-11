#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;

long long fact(int n_now)
{
    long long ret=1;

    for(int j=1;j<=n_now;j++)
        ret=ret*j%mod;

    return ret;
}

long long solve()
{
    int n;
    scanf("%i",&n);

    if(n%2)return 0;

    long long ret=fact(n/2);

    ret=ret*ret%mod;

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