#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n;

long long k;

int inp[nmax];

int outp[nmax];

int mem[nmax];

long long ask(long long cur)
{
    long long k_now=0;
    for(int i=1;i<=n;i++)
    {
        //a-3x^2-3x-1>=cur, x+1<=inp[i].first
        long long ok=-1,not_ok=inp[i];

        while(not_ok-ok>1)
        {
            long long x=(ok+not_ok)/2;

            if(inp[i]-3*x*x-3*x-1>=cur)ok=x;
            else not_ok=x;
        }

        k_now=k_now+ok+1;
        outp[i]=ok+1;
    }

    return k_now;
}

int main()
{
    scanf("%i%lld",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%i",&inp[i]);

    long long not_ok=0;
    for(int i=1;i<=n;i++)
        not_ok=max(not_ok,1LL*inp[i]);

    not_ok++;

    long long ok=-3.2e18;

    while(not_ok-ok>1)
    {
        long long av=(ok+not_ok)/2;
        if(ask(av)<k)not_ok=av;
        else ok=av;
    }

    //cout<<not_ok<<" -> "<<ask(not_ok)<<endl;

    k=k-ask(not_ok);

    for(int i=1;i<=n;i++)mem[i]=outp[i];

    ask(ok);

    for(int i=1;i<=n;i++)
    {
        if(k&&mem[i]!=outp[i])mem[i]++,k--;

        printf("%i ",mem[i]);
    }

    return 0;
}