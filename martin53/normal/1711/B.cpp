#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,m;
int sub[nmax];

pair<int,int> inp[nmax];

int deg[nmax];

int solve()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&sub[i]);
        deg[i]=0;
    }

    for(int i=1;i<=m;i++)
    {
        scanf("%i%i",&inp[i].first,&inp[i].second);
        deg[inp[i].first]++;
        deg[inp[i].second]++;
    }

    if(m%2==0)return 0;

    int outp=1e9;

    for(int i=1;i<=n;i++)
        if(deg[i]%2==1)
            outp=min(outp,sub[i]);

    for(int i=1;i<=m;i++)
        if(deg[inp[i].first]%2==0&&deg[inp[i].second]%2==0)
            outp=min(outp,sub[inp[i].first]+sub[inp[i].second]);

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