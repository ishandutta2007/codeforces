#include<bits/stdc++.h>
using namespace std;

long long solve()
{
    long long n;
    scanf("%lld",&n);

    if(n%2)n++;

    n=n/2;

    return 5*max(n,3LL);
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
}