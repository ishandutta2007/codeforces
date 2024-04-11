#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,inp[nmax];

double solve()
{
    scanf("%i",&n);

    long long sum=0;
    int MX=-1e9;

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
        sum+=inp[i];
        MX=max(MX,inp[i]);
    }

    return (sum-MX)*1.0/(n-1)+MX;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%.9f\n",solve());
    }

    return 0;
}