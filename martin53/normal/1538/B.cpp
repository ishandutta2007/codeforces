#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,inp[nmax];

int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    long long sum=0;
    for(int i=1;i<=n;i++)sum+=inp[i];

    if(sum%n)return -1;

    int outp=0;

    for(int i=1;i<=n;i++)
        if(sum/n<inp[i])outp++;

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