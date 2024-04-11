#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,k,inp[nmax];

long long solve()
{
    scanf("%i%i",&n,&k);

    long long min_sum=1LL*(k+n-1)/k*k;

    return (min_sum+n-1)/n;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%i\n",solve());
    }

    return 0;
}