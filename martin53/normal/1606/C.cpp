#include<bits/stdc++.h>
using namespace std;

const int nmax=100;

int n,inp[nmax];
long long pwr[nmax];

long long solve()
{
    int k;

    scanf("%i%i",&n,&k);
    k++;

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    inp[n+1]=inp[n]+10;

    long long outp=0;

    for(int i=1;i<=n;i++)
    {
        int cur=min(pwr[inp[i+1]-inp[i]]-1,1LL*k);

        outp+=1LL*cur*pwr[inp[i]];

        k=k-cur;
    }

    return outp;
}

int main()
{
    pwr[0]=1;
    for(int i=1;i<=10;i++)pwr[i]=pwr[i-1]*10;

    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        printf("%lld\n",solve());
    }


    return 0;
}