#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,k;
pair<int,int> inp[nmax];

int solve()
{
    scanf("%i%i",&n,&k);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i].first);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i].second);

    sort(inp+1,inp+n+1);

    for(int i=1;i<=n;i++)
        if(inp[i].first<=k)k+=inp[i].second;

    return k;
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