#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42;

int parent[2][nmax];

int n;

int root(int j,int node)
{
    if(parent[j][node]==node)return node;

    parent[j][node]=root(j,parent[j][node]);

    return parent[j][node];
}
int main()
{
    int m[2];

    scanf("%i%i%i",&n,&m[0],&m[1]);

    for(int i=1;i<=n;i++)parent[0][i]=i,parent[1][i]=i;

    for(int j=0;j<2;j++)
    {
        for(int i=1;i<=m[j];i++)
        {
            int u,v;

            scanf("%i%i",&u,&v);

            parent[j][root(j,u)]=root(j,v);
        }
    }

    vector< pair<int,int> > outp={};

    for(int u=1;u<=n;u++)
        for(int v=u+1;v<=n;v++)
        {
            if(root(0,u)!=root(0,v)&&root(1,u)!=root(1,v))
            {
                outp.push_back({u,v});

                parent[0][root(0,u)]=root(0,v);
                parent[1][root(1,u)]=root(1,v);
            }
        }

    printf("%i\n",outp.size());
    for(auto w:outp)printf("%i %i\n",w.first,w.second);

    return 0;
}