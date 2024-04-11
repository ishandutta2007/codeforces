#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,k,inp[nmax];

bool check(int l,int r)
{
    for(int i=1;i<=n;i++)
    {
        int low=(inp[i]+1+r+1-1)/(r+1);
        int high=k;

        if(l)high=min(high,inp[i]/l);

        if(low>high)return 0;
    }

    return 1;
}

bool test(int SZ)
{
    for(int l=0;l+SZ<=inp[n];l++)
        if(check(l,l+SZ))return 1;

    return 0;
}

int solve()
{
    scanf("%i%i",&n,&k);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    if(inp[n]<k)return 0;

    int ok=inp[n],not_ok=-1;

    while(ok-not_ok>1)
    {
        int av=(ok+not_ok)/2;

        if(test(av))ok=av;
        else not_ok=av;
    }

    return ok;
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