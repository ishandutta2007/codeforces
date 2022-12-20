#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

bool solve()
{
    scanf("%i",&n);

    int cnt=0;

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);

        if(inp[i]<0)cnt++,inp[i]=-inp[i];
    }

    for(int i=1;i<=cnt;i++)
        inp[i]=-inp[i];

    for(int i=1;i<n;i++)
        if(inp[i]>inp[i+1])return 0;

    return 1;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        if(solve())printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}