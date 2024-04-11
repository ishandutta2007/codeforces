#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42,inf=2e9;

int n,inp[nmax];

int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+n+1);

    int outp=0;
    int mini=inf;

    for(int i=1;i<=n;i++)
        if(inp[i]<=0)
        {
            outp++;
            if(i>=2)mini=min(mini,inp[i]-inp[i-1]);
        }
        else
        {
            if(inp[i]<=mini)outp++;
            return outp;
        }

    return outp;
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