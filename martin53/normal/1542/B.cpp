#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    long long n,a,b;

    scanf("%lld%lld%lld",&n,&a,&b);

    if(a==1)return (n-1)%b==0;

    for(long long i=1;i<=n;i=i*a)
        if((n-i)%b==0)return 1;

    return 0;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        if(solve())printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}