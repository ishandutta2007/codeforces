#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,m,inp[nmax];

int cost[nmax];

int g[nmax];

void prec()
{
    for(int i=1;i<nmax;i++)g[i]=i;

    for(int i=2;i*i<nmax;i++)
        for(int j=i*i;j<nmax;j=j+i*i)
        {
            while(g[j]%(i*i)==0)
            {
                g[j]=g[j]/(i*i);
            }
        }
}

map<int,int> seen;

void solve()
{
    seen={};

    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)
    {
        //cout<<inp[i]<<" -> "<<g[inp[i]]<<endl;

        inp[i]=g[inp[i]];
    }

    int mem_0=0,other=0;

    int q;

    scanf("%i",&q);

    for(int i=1;i<=n;i++)
    {
        seen[inp[i]]++;

        mem_0=max(mem_0,seen[inp[i]]);
    }

    /*
    cout<<"seen: "<<endl;
    for(auto w:seen)cout<<w.first<<" "<<w.second<<"\n";
    */

    for(auto k:seen)
        if(k.second%2==0&&k.first!=1)seen[1]+=k.second;

    other=max(mem_0,seen[1]);

    for(int i=1;i<=q;i++)
    {
        long long w;
        scanf("%lld",&w);

        if(w==0)printf("%i\n",mem_0);
        else printf("%i\n",other);
    }
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