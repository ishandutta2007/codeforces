#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,inp[nmax];

bool check(int i,int j)
{
    return 1<=i&&i<j&&1LL*inp[i]*inp[j]==i+j;
}
long long solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    long long outp=0;

    for(int j=1;j<=n;j++)
    {
        for(int i=(-j%inp[j])+inp[j];i<j;i+=inp[j])
            outp+=check(i,j);
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