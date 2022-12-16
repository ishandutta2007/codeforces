#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42,mod=1e9+7;

int n,m;

int fib[nmax];

int main()
{
    scanf("%i%i",&n,&m);

    fib[0]=1;
    fib[1]=1;

    for(int i=2;i<=max(n,m);i++)
    {
        fib[i]=(fib[i-1]+fib[i-2])%mod;
    }

    long long outp=fib[n]+fib[m];

    outp=outp*2;

    outp=outp-2;

    printf("%lld\n",outp%mod);

    return 0;
}