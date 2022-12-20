#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,m;

char outp[nmax];

vector<int> adj[nmax],trav[nmax];

int in[nmax];

queue<int> q;

int order[nmax];

int go_up[nmax],go_down[nmax];

int main()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=n;i++)outp[i]='E';

    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);
        adj[u].push_back(v);

        trav[v].push_back(u);

        in[v]++;
    }

    for(int i=1;i<=n;i++)
        if(in[i]==0)q.push(i);

    for(int i=1;i<=n;i++)
    {
        if(q.size()==0)
        {
            printf("-1\n");
            return 0;
        }

        int tp=q.front();
        q.pop();

        order[i]=tp;

        //cout<<"tp= "<<tp<<endl;

        for(auto k:adj[tp])
        {
            in[k]--;
            if(in[k]==0)
            {
                q.push(k);
            }
        }
    }

    for(int i=n;i>=1;i--)
    {
        int cur=order[i];

        go_up[cur]=cur;
        for(auto k:adj[cur])
            go_up[cur]=min(go_up[cur],go_up[k]);
    }

    for(int i=1;i<=n;i++)
    {
        int cur=order[i];

        go_down[cur]=cur;
        for(auto k:trav[cur])
            go_down[cur]=min(go_down[cur],go_down[k]);
    }

    for(int i=1;i<=n;i++)
        if(go_up[i]==i&&go_down[i]==i)outp[i]='A';

    int out=0;
    for(int i=1;i<=n;i++)
        if(outp[i]=='A')out++;

    printf("%i\n",out);
    for(int i=1;i<=n;i++)printf("%c",outp[i]);
    return 0;
}