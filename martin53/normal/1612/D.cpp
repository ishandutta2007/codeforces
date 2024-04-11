#include<bits/stdc++.h>
using namespace std;

bool can(long long a,long long b,long long x)
{
    if(a<b)swap(a,b);

    if(a==x||b==x)return 1;

    if(a==0||b==0)return 0;

    if(a<x&&b<x)return 0;

    if(a%b==x%b)return 1;

    return can(a%b,b,x);
}

bool solve()
{
    long long a,b,x;

    scanf("%lld%lld%lld",&a,&b,&x);

    if(a<b)swap(a,b);

    return can(a,b,x);
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