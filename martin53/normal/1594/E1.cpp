#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

long long pwr(long long a,long long b)
{
    long long ret=1;

    while(b)
    {
        if(b%2)ret=ret*a%mod;
        a=a*a%mod;
        b=b/2;
    }

    return ret;
}

int main()
{
    int k;
    scanf("%i",&k);

    long long outp=6*pwr(4,(1LL<<k)-2)%mod;

    printf("%lld\n",outp);

    return 0;
}