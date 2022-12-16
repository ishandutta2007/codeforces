#include<bits/stdc++.h>
using namespace std;

long long solve()
{
    long long n;

    scanf("%lld",&n);

    long long pwr=1;

    while(n%2==0)
    {
        pwr=pwr*2;
        n=n/2;
    }

    if(n==1)return -1;

    if(n>=pwr*2+1)return pwr*2;

    return n;
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