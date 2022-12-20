#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42,mod=1e9+7;

int n,inp[nmax];

int fact(int SZ)
{
    long long ret=1;
    for(int i=1;i<=SZ;i++)
        ret=ret*i%mod;
    return ret;
}

int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int an=inp[1];
    for(int i=1;i<=n;i++)an=an&inp[i];

    for(int i=1;i<=n;i++)inp[i]=inp[i]^an;

    int cnt_0=0;

    for(int i=1;i<=n;i++)
        if(inp[i]==0)cnt_0++;

    return 1LL*cnt_0*(cnt_0-1)%mod*fact(n-2)%mod;
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