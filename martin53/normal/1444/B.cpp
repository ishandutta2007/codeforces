#include<bits/stdc++.h>
using namespace std;

const int nmax=3e5+42,mod=998244353;

int n,inp[nmax];

long long my_pow(long long a,int b)
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

long long inv(long long a)
{
    return my_pow(a,mod-2);
}
long long fact(int to)
{
    long long ret=1;

    for(int i=1;i<=to;i++)ret=ret*i%mod;

    return ret;
}
int main()
{
    scanf("%i",&n);

    for(int i=1;i<=2*n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+2*n+1);

    long long sum_low=0,sum_high=0;
    for(int i=1;i<=n;i++)
        sum_low+=inp[i];

    for(int i=n+1;i<=2*n;i++)
        sum_high+=inp[i];

    long long outp=(sum_high-sum_low)%mod;

    outp=outp*fact(2*n)%mod;
    outp=outp*inv(fact(n))%mod;
    outp=outp*inv(fact(n))%mod;

    printf("%lld\n",outp);
    return 0;
}