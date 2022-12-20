#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

bool prime[nmax];//0->prime
void prec()
{
    int p=2;

    while(p*p<nmax)
    {
        for(int i=p*p;i<nmax;i+=p)prime[i]=1;

        p++;

        while(prime[p])p++;
    }
}

int n,delta,inp[nmax];

long long solve()
{
    scanf("%i%i",&n,&delta);

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
        if(inp[i]==1)inp[i]=0;
        else if(prime[inp[i]]==0)inp[i]=1;
        else inp[i]=2;
    }

    long long outp=0;
    for(int i=1;i<=delta;i++)
    {
        map<int,int> seen={};
        seen[0]=1;

        int cur=0;

        for(int j=i;j<=n;j+=delta)
        {
            cur+=inp[j];
            outp+=seen[cur-1];
            seen[cur]++;

            if(inp[j]==1)outp--;
        }
    }

    return outp;
}

int main()
{
    prec();

    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        printf("%lld\n",solve());
    }

    return 0;
}