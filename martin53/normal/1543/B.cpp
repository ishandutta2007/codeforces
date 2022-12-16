#include<bits/stdc++.h>
using namespace std;

long long solve()
{
    int n;

    long long sum=0;

    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);

        sum+=cur;
    }

    long long zero=sum%n;

    return zero*(n-zero);
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