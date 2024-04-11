#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int parent[2][nmax];

int n;

int root(int j,int node)
{
    if(parent[j][node]==node)return node;

    parent[j][node]=root(j,parent[j][node]);

    return parent[j][node];
}

int m[2];

vector< pair<int,int> > outp;

mt19937 rng(42);

vector<int> active;

bool can_merge(int u,int v)
{
    if(root(0,u)!=root(0,v)&&root(1,u)!=root(1,v))
    {
        outp.push_back({u,v});

        parent[0][root(0,u)]=root(0,v);
        parent[1][root(1,u)]=root(1,v);

        m[0]++;
        m[1]++;

        return 1;
    }

    return 0;
}

void run()
{
    for(int i=1;i<=n;i++)
    {
        while(active.size()>=2)
        {
            int u=active[active.size()-1];
            int v=active[active.size()-2];

            if(root(0,u)==root(0,v)&&root(1,u)==root(1,v))active.pop_back();
            else break;
        }

        if(active.size()&&can_merge(active[active.size()-1],i))
        {
            active.pop_back();
            continue;
        }

        if(active.size()>=2&&can_merge(active[active.size()-2],i))
        {
            int u=active.back();

            active.pop_back();

            active.pop_back();

            active.push_back(u);

            continue;
        }

        active.push_back(i);
    }

    //cout<<"now: "<<outp.size()<<endl;
}

int main()
{
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

    while(m[0]<n-1&&m[1]<n-1)run();

    printf("%i\n",outp.size());
    for(auto w:outp)printf("%i %i\n",w.first,w.second);

    return 0;
}