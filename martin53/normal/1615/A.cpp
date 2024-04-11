#include<bits/stdc++.h>
using namespace std;

int solve()
{
    long long n,sum=0;
    scanf("%lld",&n);

    for(int i=1;i<=n;i++)
    {
        long long cur;
        scanf("%lld",&cur);
        sum+=cur;
    }

    if(sum%n)return 1;
    return 0;
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