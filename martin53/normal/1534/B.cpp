#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    inp[0]=0;
    inp[n+1]=0;

    long long outp=0;
    for(int i=1;i<=n+1;i++)
        outp+=abs(inp[i-1]-inp[i]);

    for(int i=1;i<=n;i++)
        if(inp[i]>inp[i-1]&&inp[i]>inp[i+1])
        {
            int nw=max(inp[i-1],inp[i+1]);

            outp=outp-(inp[i]-nw);

            inp[i]=nw;
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