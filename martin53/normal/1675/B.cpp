#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

int solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int outp=0;

    for(int i=n-1;i>=1;i--)
    {
        if(inp[i+1]==0)return -1;

        while(inp[i]>=inp[i+1])
        {
            inp[i]=inp[i]/2;
            outp++;
        }
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