#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,x,inp[nmax];

bool solve()
{
    scanf("%i%i",&n,&x);

    for(int i=1;i<=2*n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+2*n+1);

    for(int i=1;i<=n;i++)
        if(inp[i+n]-inp[i]<x)return 0;

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