#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;
int n,inp[nmax];

bool check(int x)
{
    for(int i=1;i<=n;i++)
        if(abs(inp[i]-(x+i-1))>1)return 0;

    return 1;
}

bool solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+n+1);

    return check(inp[1]-1)||check(inp[1])||check(inp[1]+1);
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