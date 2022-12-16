#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,k,inp[nmax];

int help[nmax];

int pref[nmax],pref_min[nmax];

bool test(int cur)
{
    for(int i=1;i<=n;i++)
        if(inp[i]>=cur)help[i]=1;
        else help[i]=-1;

    for(int i=1;i<=n;i++)
    {
        pref[i]=pref[i-1]+help[i];

        pref_min[i]=min(pref_min[i-1],pref[i]);
    }

    for(int i=k;i<=n;i++)
        if(pref_min[i-k]<pref[i])return 1;

    return 0;
}

int main()
{
    scanf("%i%i",&n,&k);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int ok=1,not_ok=n+1;

    while(not_ok-ok>1)
    {
        int av=(ok+not_ok)/2;

        if(test(av))ok=av;
        else not_ok=av;
    }

    printf("%i\n",ok);

    return 0;
}