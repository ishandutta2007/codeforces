#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,k;
int inp[nmax];

long long solve()
{
    scanf("%i%i",&n,&k);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    long long s=inp[1],outp=0;

    for(int i=2;i<=n;i++)
    {
        long long s_new=max(s,(100LL*inp[i]+k-1)/k);
        outp+=s_new-s;
        s=s_new+inp[i];
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