#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+n+1);

    if(inp[1]==0)
    {
        int pos=1;

        while(inp[pos]==0&&pos<=n)pos++;

        pos--;

        return n-pos;
    }

    for(int i=2;i<=n;i++)
        if(inp[i-1]==inp[i])return n;

    return n+1;
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