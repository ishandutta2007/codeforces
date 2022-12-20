#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,need;

int a[nmax],b[nmax];

int solve()
{
    scanf("%i%i",&n,&need);

    for(int i=1;i<=n;i++)scanf("%i",&a[i]);

    for(int i=1;i<n;i++)scanf("%i",&b[i]);

    b[n]=1;

    int money=0,day=0;

    int outp=need;

    for(int i=1;i<=n&&day<outp;i++)
    {
        outp=min(outp,day+(need-money+a[i]-1)/a[i]);

        int days_now=max(0,(b[i]-money+a[i]-1)/a[i]);

        money+=days_now*a[i];

        day+=days_now;

        money=money-b[i];

        day++;
    }

    return outp;
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