#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42;

int n,inp[nmax];

int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int g=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int cur=abs(inp[i]-inp[j]);
            g=__gcd(g,cur);
        }

    if(g==0)return -1;
    return g;
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
}