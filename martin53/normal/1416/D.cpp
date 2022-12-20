#include<bits/stdc++.h>
using namespace std;

const int nmax=5e5+42;

struct query
{
    int type,node;
};
query inp[nmax];

int n,m,q;

pair<int,int> edges[nmax];

int p[nmax];

bool blocked[nmax];

vector<int> comp[nmax];
int root[nmax];

vector<int> cut_into[nmax];

void my_merge(int u,int v)
{
    u=root[u];
    v=root[v];

    if(u==v)return;

    if(comp[u].size()<comp[v].size())swap(u,v);

    //cout<<"my merge "<<u<<" "<<v<<endl;

    root[v]=u;

    for(auto w:comp[v])
    {
        comp[u].push_back(w);
        root[w]=u;
    }

    /*
    for(int i=1;i<=n;i++)cout<<i<<" -> "<<root[i]<<endl;

    for(int i=1;i<=n;i++)
    {
        cout<<"comp "<<i<<" -> ";for(auto w:comp[i])cout<<w<<" ";cout<<endl;
    }
    */

}

set< pair<int/*p[node]*/,int/*node*/> > active[nmax*2];

int main()
{
    scanf("%i%i%i",&n,&m,&q);

    for(int i=1;i<=n;i++)scanf("%i",&p[i]);

    for(int i=1;i<=m;i++)
        scanf("%i%i",&edges[i].first,&edges[i].second);

    for(int i=1;i<=q;i++)
    {
        scanf("%i%i",&inp[i].type,&inp[i].node);

        if(inp[i].type==2)blocked[inp[i].node]=1;
    }

    for(int i=1;i<=n;i++)
    {
        root[i]=i;
        comp[i]={i};
    }

    for(int i=1;i<=m;i++)
        if(blocked[i]==0)
            my_merge(edges[i].first,edges[i].second);

    /*
    for(int i=1;i<=n;i++)
        cout<<i<<" with root "<<root[i]<<endl;
    */

    for(int i=q;i>=1;i--)
    {
        if(inp[i].type==1)continue;

        int u=edges[inp[i].node].first;
        int v=edges[inp[i].node].second;

        //cout<<u<<" "<<root[u]<<" and "<<v<<" "<<root[v]<<endl;

        if(root[u]==root[v])continue;

        if(comp[root[u]].size()<comp[root[v]].size())swap(u,v);

        for(auto w:comp[root[v]])
        {
            cut_into[i].push_back(w);
            //cout<<"at "<<i<<" cut "<<w<<endl;
        }


        my_merge(u,v);
    }

    for(int i=1;i<=n;i++)
    {
        active[root[i]].insert({p[i],i});

        //cout<<i<<" -> "<<root[i]<<" "<<p[i]<<" "<<i<<endl;
    }

    int pointer=n;

    for(int i=1;i<=q;i++)
        if(inp[i].type==1)
        {
            set< pair<int,int> >::iterator it=active[root[inp[i].node]].end();

            it--;

            int node=(*it).second;

            printf("%i\n",p[node]);

            active[root[inp[i].node]].erase(it);

            p[node]=0;

            active[root[inp[i].node]].insert({p[node],node});
        }
        else
        {
            if(cut_into[i].size()==0)continue;

            int root_now=root[edges[inp[i].node].first];

            pointer++;

            for(auto w:cut_into[i])
                active[root_now].erase({p[w],w});

            for(auto w:cut_into[i])
            {
                active[pointer].insert({p[w],w});
                root[w]=pointer;
                comp[pointer].push_back(w);
            }

            //for(int i=1;i<=n;i++)cout<<i<<" root= "<<root[i]<<" \t ";cout<<endl;
        }
    return 0;
}