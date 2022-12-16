#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

int solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    set<int> seen={};

    int j=n;

    while(j>0)
    {
        if(seen.count(inp[j]))break;

        seen.insert(inp[j]);

        j--;
    }

    return j;
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