#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int outp=0,cnt=0;

    for(int i=1;i<=n;i++)
    {
        if(inp[i-1]==inp[i])cnt++;
        else cnt=1;
        outp=max(outp,cnt);
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