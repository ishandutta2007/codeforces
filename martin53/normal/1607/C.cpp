#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+n+1);

    int outp=inp[1];
    for(int i=2;i<=n;i++)outp=max(outp,inp[i]-inp[i-1]);

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