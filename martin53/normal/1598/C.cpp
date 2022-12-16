#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

map<long long,int> seen;

long long solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    long long sum=0;
    for(int i=1;i<=n;i++)sum+=inp[i];

    if(2*sum%n)return 0;

    long long need=sum-2*sum/n;

    long long diff=sum-need;

    seen={};

    long long outp=0;
    for(int i=1;i<=n;i++)
    {
        outp+=seen[diff-inp[i]];
        seen[inp[i]]++;
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