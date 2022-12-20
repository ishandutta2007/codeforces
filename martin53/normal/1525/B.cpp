#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,inp[nmax];

int solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int zero=1;
    for(int i=1;i<=n;i++)
        if(inp[i]!=i)zero=0;

    if(zero)return 0;

    if(inp[1]==1||inp[n]==n)return 1;

    if(inp[n]==1&&inp[1]==n)return 3;

    return 2;
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