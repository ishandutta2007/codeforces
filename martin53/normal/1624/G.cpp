#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,m;

struct edge
{
    int u,v,c;
};
edge inp[nmax];

int parent[nmax];
int root(int node)
{
    if(node==parent[node])return node;
    parent[node]=root(parent[node]);
    return parent[node];
}

bool can(int cur)
{
    for(int i=1;i<=n;i++)parent[i]=i;

    for(int i=1;i<=m;i++)
        if((inp[i].c|cur)==cur)
        {
            parent[root(inp[i].u)]=root(inp[i].v);
        }

    for(int i=1;i<=n;i++)
        if(root(1)!=root(i))return 0;

    return 1;
}

int solve()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=m;i++)scanf("%i%i%i",&inp[i].u,&inp[i].v,&inp[i].c);

    int outp=0;

    for(int bit=29;bit>=0;bit--)
        if(can(outp+(1LL<<bit)-1)==0)outp+=(1LL<<bit);

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