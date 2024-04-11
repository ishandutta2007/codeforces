#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,inp[nmax];

bool solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    if(n%2==0)return 1;

    for(int i=2;i<=n;i++)
        if(inp[i-1]>=inp[i])return 1;

    return 0;
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