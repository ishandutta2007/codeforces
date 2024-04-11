#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

set<int> adj[nmax];
int n,m;

int active;

bool alive(int u)
{
    if(adj[u].size()==0)return 1;

    set<int>::iterator it=adj[u].end();
    it--;

    return (*it)<u;
}

void add(int u,int v)
{
    active=active-alive(u);
    active=active-alive(v);

    adj[u].insert(v);
    adj[v].insert(u);

    active=active+alive(u);
    active=active+alive(v);
}

void rem(int u,int v)
{
    active=active-alive(u);
    active=active-alive(v);

    adj[u].erase(v);
    adj[v].erase(u);

    active=active+alive(u);
    active=active+alive(v);
}

int main()
{
    scanf("%i%i",&n,&m);

    active=n;

    for(int i=1;i<=m;i++)
    {
        int u,v;

        scanf("%i%i",&u,&v);

        add(u,v);
    }

    int q;
    scanf("%i",&q);

    for(int i=1;i<=q;i++)
    {
        int type;

        scanf("%i",&type);

        if(type==3)printf("%i\n",active);
        else
        {
            int u,v;
            scanf("%i%i",&u,&v);

            if(type==1)add(u,v);
            else rem(u,v);
        }
    }

    return 0;
}