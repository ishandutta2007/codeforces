#include<bits/stdc++.h>
using namespace std;

long long solve()
{
    long long n,k;
    scanf("%lld%lld",&n,&k);

    long long t=0,cur=1;

    while(cur<k)
    {
        cur=cur*2;
        t++;
    }

    if(cur>=n)return t;
    return t+(n-cur+k-1)/k;
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