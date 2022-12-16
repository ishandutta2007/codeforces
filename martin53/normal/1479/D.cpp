#include<bits/stdc++.h>
using namespace std;

const int nmax=(1<<19)+42,MX=15e6;

int n,q;

mt19937 rng(42);

unsigned long long hsh_a[nmax],hsh_node[nmax];

int inp[nmax];

int in[nmax],out[nmax],t,depth[nmax];

int up[20][nmax];

vector<int> adj[nmax];

struct query
{
    int u,v,l,r;
    int mem_lca;
};
query all[nmax];

int outp[nmax];

void dfs(int node,int par)
{
    t++;
    in[node]=t;

    up[0][node]=par;
    for(int i=1;i<20;i++)
        up[i][node]=up[i-1][up[i-1][node]];

    depth[node]=depth[par]+1;

    for(auto k:adj[node])
        if(k!=par)dfs(k,node);

    out[node]=t;
}

int lca(int u,int v)
{
    if(depth[u]<depth[v])swap(u,v);

    for(int i=19;i>=0;i--)
        if(depth[u]-(1<<i)>=depth[v])u=up[i][u];

    if(u==v)return u;

    for(int i=19;i>=0;i--)
        if(up[i][u]!=up[i][v])u=up[i][u],v=up[i][v];

    return up[0][u];
}
vector<int> seen[nmax];

int leave[nmax];

int left_child[MX],right_child[MX];
unsigned long long tree[MX];

int last_active[4*nmax];















unsigned long long hsh_for_query[nmax],fenwick[nmax];

unsigned long long eval_fenwick(int pos)
{
    unsigned long long ret=0;

    while(pos)
    {
        ret=ret^fenwick[pos];
        pos=pos-(pos&(-pos));
    }
    return ret;
}
unsigned long long fenwick_precise(int u,int v,int mem_lca,int up_to)
{
    if(up_to==0)return 0;

    unsigned long long ret=0;
    ret=ret^eval_fenwick(in[u]);
    ret=ret^eval_fenwick(in[v]);
    if(inp[mem_lca]<=up_to)ret=ret^hsh_node[mem_lca];
    return ret;
}
void upd(int pos,unsigned long long val)
{
    while(pos<=n)
    {
        fenwick[pos]=fenwick[pos]^val;
        pos=pos+(pos&(-pos));
    }
}
vector< int > to_solve[nmax];

void update_fenwick(int node)
{
    upd(in[node],hsh_node[node]);

    upd(out[node]+1,hsh_node[node]);
}





void kill_fake()
{
        for(int i=1;i<=n;i++)
        {
            fenwick[i]=0;
            to_solve[i]={};
        }

        for(int i=1;i<=q;i++)
            hsh_for_query[i]=0;

        for(int i=1;i<=q;i++)
            {
                if(all[i].l-1)to_solve[all[i].l-1].push_back(i);
                to_solve[all[i].r].push_back(i);
                /*test ask(u,v,l,av)*/
            }

        for(int i=1;i<=n;i++)
        {
            for(auto w:seen[i])
                update_fenwick(w);

            for(auto w:to_solve[i])
                hsh_for_query[w]=hsh_for_query[w]^fenwick_precise(all[w].u,all[w].v,all[w].mem_lca,i);
        }

        for(int i=1;i<=q;i++)
            {
                if(hsh_for_query[i]==0)outp[i]=-1;
            }

}


int main()
{
    scanf("%i%i",&n,&q);

    //build(1,1,n);

    for(int i=1;i<=n;i++)
        for(int j=0;j<64;j++)
            hsh_a[i]=hsh_a[i]*2+rng()%2;
/*
    for(int i=1;i<=n;i++)
        cout<<i<<" -> "<<hsh_a[i]<<endl;
*/
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);

        hsh_node[i]=hsh_a[inp[i]];
    }

    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,1);

    //prec();

    for(int i=1;i<=n;i++)
        seen[inp[i]].push_back(i);

    for(int i=1;i<=q;i++)
    {
        scanf("%i%i%i%i",&all[i].u,&all[i].v,&all[i].l,&all[i].r);

        all[i].mem_lca=lca(all[i].u,all[i].v);
    }

    kill_fake();

    for(int t=0;t<20;t++)
    {
        for(int i=1;i<=n;i++)
        {
            fenwick[i]=0;
            to_solve[i]={};
        }

        for(int i=1;i<=q;i++)
            hsh_for_query[i]=0;

        for(int i=1;i<=q;i++)
            if(outp[i]==0)
            {
                if(all[i].l==all[i].r)
                {
                    outp[i]=all[i].l;
                    continue;
                }

                int av=(all[i].l+all[i].r)/2;

                if(all[i].l-1)to_solve[all[i].l-1].push_back(i);
                to_solve[av].push_back(i);
                /*test ask(u,v,l,av)*/
            }

        for(int i=1;i<=n;i++)
        {
            for(auto w:seen[i])
                update_fenwick(w);

            for(auto w:to_solve[i])
                hsh_for_query[w]=hsh_for_query[w]^fenwick_precise(all[w].u,all[w].v,all[w].mem_lca,i);
        }

        for(int i=1;i<=q;i++)
            if(outp[i]==0)
            {
                int av=(all[i].l+all[i].r)/2;

                if(hsh_for_query[i]==0)all[i].l=av+1;
                else all[i].r=av;
            }

    }

    for(int i=1;i<=q;i++)
        printf("%i\n",outp[i]);

    return 0;
}