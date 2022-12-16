#include<bits/stdc++.h>
using namespace std;

long long solve(long long val,long long st)
{
    if(st==1)return 0;

    long long help=st/4;

    if(val<help)return solve(val,st/4);

    if(val<2*help)return solve(val-help,st/4)+2*help;

    if(val<3*help)return solve(val-2*help,st/4)+3*help;

    return solve(val-3*help,st/4)+help;
}

long long solve_third(long long val,long long st)
{
    if(st==1)return 0;

    long long help=st/4;

    if(val<help)return solve_third(val,st/4);

    if(val<2*help)return solve_third(val-help,st/4)+3*help;

    if(val<3*help)return solve_third(val-2*help,st/4)+help;

    return solve_third(val-3*help,st/4)+2*help;
}

long long query(long long n)
{
    if(n%3==1)
    {
        long long mx=1;

        while(4*mx<=n)mx=mx*4;

        return mx+(n-mx)/3;
    }

    if(n%3==2)
    {
        long long mx=1;

        while(4*mx<=n)mx=mx*4;

        return 2*mx+solve((n-mx)/3,mx);
    }
    long long mx=1;

    while(4*mx<=n)mx=mx*4;

    return 3*mx+solve_third((n-mx)/3,mx);
}
int main()
{
    int t;
    scanf("%i",&t);

    for(int i=1;i<=t;i++)
    {
        long long n;
        scanf("%lld",&n);
        printf("%lld\n",query(n));
    }
    return 0;
}