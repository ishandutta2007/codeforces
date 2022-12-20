#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

bool check(int l,int cur)
{
    for(int i=l;i<cur;i++)
        for(int j=i+1;j<cur;j++)
        {
            if(inp[i]>=inp[j]&&inp[j]>=inp[cur])return 0;
            if(inp[i]<=inp[j]&&inp[j]<=inp[cur])return 0;
        }
    return 1;
}
long long solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int ret=0;

    for(int i=1;i<=n;i++)
        for(int j=i;j<=n&&check(i,j);j++)ret++;

    return ret;
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