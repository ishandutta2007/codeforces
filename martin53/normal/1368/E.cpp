#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

struct info
{
    int i,j,k;
};

int n,m;

vector<int> adj[nmax];

bool keep[nmax];

bool cmp(info a,info b)
{
    if(a.k!=b.k)return a.k<b.k;
    if(a.j!=b.j)return a.j<b.j;
    return a.i<b.i;
}
void solve()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=n;i++)adj[i]={};

    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);
        adj[u].push_back(v);
    }

    for(int i=1;i<=n;i++)keep[i]=1;

    vector<info> seen={};

    for(int i=1;i<=n;i++)
        for(auto j:adj[i])
            for(auto k:adj[j])
            {
                info cur;

                cur.i=i;
                cur.j=j;
                cur.k=k;

                seen.push_back(cur);
            }

    sort(seen.begin(),seen.end(),cmp);

    for(auto w:seen)
        if(keep[w.i]&&keep[w.j]&&keep[w.k])keep[w.k]=0;

    vector<int> outp={};

    for(int i=1;i<=n;i++)
        if(keep[i]==0)outp.push_back(i);

    printf("%i\n",outp.size());
    for(auto k:outp)printf("%i ",k);printf("\n");
}

int main()
{
    int t;
    scanf("%i",&t);
    while(t)
    {
        t--;
        solve();
    }
    return 0;
}