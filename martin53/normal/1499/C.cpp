#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+5,inf=1e9+42;

int n;

long long inp[nmax];

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&inp[i]);

    long long outp=1e18;

    long long mini[2]={inf,inf},sum[2]={0,0},free[2]={n,n};

    for(int i=1;i<=n;i++)
    {
        mini[i%2]=min(mini[i%2],inp[i]);
        sum[i%2]+=inp[i];

        free[i%2]--;

        long long cur=sum[0]+free[0]*mini[0];
        cur+=sum[1]+free[1]*mini[1];

        outp=min(outp,cur);
    }

    printf("%lld\n",outp);
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}