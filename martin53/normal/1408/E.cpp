#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int m,MX;

int a[nmax],b[nmax];

vector<int> inp[nmax];

struct edge
{
    int u,v,cost;
};

vector< edge > edges;

edge make_edge(int u,int v,int cost)
{
    edge cur;
    cur.u=u;
    cur.v=v;
    cur.cost=cost;
    return cur;
}
int parent[nmax];

bool cmp(edge a,edge b)
{
    return a.cost>b.cost;
}

int root(int node)
{
    if(node==parent[node])return node;
    parent[node]=root(parent[node]);
    return parent[node];
}

long long outp=0;

int main()
{
    scanf("%i%i",&m,&MX);

    for(int i=1;i<nmax;i++)
        parent[i]=i;

    for(int i=1;i<=m;i++)scanf("%i",&a[i]);

    for(int i=1;i<=MX;i++)scanf("%i",&b[i]);

    for(int i=1;i<=m;i++)
    {
        int sz,val;
        scanf("%i",&sz);

        for(int j=1;j<=sz;j++)
        {
            scanf("%i",&val);

            int add=a[i]+b[val];

            edges.push_back(make_edge(i+MX,val,add));

            outp+=add;
        }
    }

    sort(edges.begin(),edges.end(),cmp);

    for(auto k:edges)
        if(root(k.u)!=root(k.v))
        {
            outp=outp-k.cost;
            parent[root(k.u)]=root(k.v);
        }

    printf("%lld\n",outp);
    return 0;
}