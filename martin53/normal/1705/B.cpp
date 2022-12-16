#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

long long solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int pos=1;

    while(pos<n&&inp[pos]==0)pos++;

    long long output=0;

    for(int i=pos;i<n;i++)
        output+=max(inp[i],1);

    return output;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%lld\n",solve());
    }

    return 0;
}