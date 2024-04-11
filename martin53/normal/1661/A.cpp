#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,a[nmax],b[nmax];

long long solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    for(int i=1;i<=n;i++)scanf("%i",&b[i]);

    long long outp=0;

    for(int i=2;i<=n;i++)
    {
        int case_1=abs(a[i-1]-a[i])+abs(b[i-1]-b[i]);
        int case_2=abs(a[i-1]-b[i])+abs(b[i-1]-a[i]);

        outp+=min(case_1,case_2);
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

        printf("%lld\n",solve());
    }

    return 0;
}