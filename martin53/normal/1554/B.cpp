#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,k,inp[nmax];

long long solve()
{
    scanf("%i%i",&n,&k);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    long long outp=-1e9;

    for(int i=n;i>=1;i--)
        for(int j=i-1;j>=1&&1LL*i*j>=outp;j--)
        {
            long long cur=(1LL*i*j)-k*(inp[i]|inp[j]);

            outp=max(outp,cur);
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