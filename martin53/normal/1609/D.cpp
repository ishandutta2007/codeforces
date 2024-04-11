#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,m;

int parent[nmax],SZ[nmax];

int to_take=1,outp=0;

int root(int node)
{
    if(parent[node]==node)return parent[node];
    parent[node]=root(parent[node]);
    return parent[node];
}

void my_merge(int u,int v)
{
    u=root(u);
    v=root(v);

    if(u==v)
    {
        to_take++;
        return;
    }

    SZ[u]+=SZ[v];
    parent[v]=u;
}

bool cmp(int a,int b)
{
    return a>b;
}

int eval()
{
    vector<int> cur={};

    for(int i=1;i<=n;i++)
        if(i==root(i))cur.push_back(SZ[i]);

    sort(cur.begin(),cur.end(),cmp);

    outp=0;

    for(int i=0;i<to_take;i++)
        outp+=cur[i]-1;

    outp+=to_take-1;

    return outp;
}

int main()
{
    scanf("%i%i",&n,&m);
    for(int i=1;i<=n;i++)parent[i]=i,SZ[i]=1;

    outp=0;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);

        my_merge(u,v);
        printf("%i\n",eval());
    }

    return 0;
}