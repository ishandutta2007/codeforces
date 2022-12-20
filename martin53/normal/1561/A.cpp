#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42;

int n,inp[nmax];

bool check()
{
    for(int i=1;i<n;i++)
        if(inp[i]>inp[i+1])return 0;

    return 1;
}

int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int t=0;

    while(check()==0)
    {
        t++;

        for(int i=2-t%2;i<n;i=i+2)
            if(inp[i]>inp[i+1])swap(inp[i],inp[i+1]);
    }

    return t;
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