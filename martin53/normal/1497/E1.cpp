#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42,MX=1e7+42;

int n,k,inp[nmax];

int least[MX];

void prec()
{
    for(int i=1;i<MX;i++)
        least[i]=i;

    for(int p=MX;p;p--)
        if(1LL*p*p<MX)
        {
            for(int j=p*p;j<MX;j+=p*p)
                if(least[j]%(p*p)==0)least[j]=least[j]/p/p;
        }
}

set< int > active;

void solve()
{

    scanf("%i%i",&n,&k);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)inp[i]=least[inp[i]];

    active={};

    int ret=1;

    for(int i=1;i<=n;i++)
    {
        if(active.count(inp[i]))
        {
            active={};
            ret++;
        }
        active.insert(inp[i]);
    }

    printf("%i\n",ret);
}

int main()
{
    prec();

    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}