#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,d,inp[nmax];

bool solve()
{
    scanf("%i%i",&n,&d);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+n+1);

    return min(inp[n],inp[1]+inp[2])<=d;
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