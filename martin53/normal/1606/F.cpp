#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42,C=300;

const int SZ=nmax/C+42;

int outp[nmax],n,q;

vector<int> adj[nmax];

vector< pair<int/*k*/,int/*id*/> > queries[nmax];

vector<int> ret={};
void push(int pos,int coeff)
{
    while(ret.size()<=pos)ret.push_back(-1e9);
    ret[pos]=max(ret[pos],coeff);
}

vector<int> ok_p={0},ok_q={0};

vector<int> dfs(int node,int parent)
{
    vector<int> cur={0};

    for(auto w:adj[node])
        if(w!=parent)
        {
            vector<int> active=dfs(w,node);

            ret={};
            ret.shrink_to_fit();

            ok_p={0};
            ok_p.shrink_to_fit();
            for(int p=1;p<cur.size();p++)
                if(cur[p]!=cur[p-1])ok_p.push_back(p);

            ok_q={0};
            ok_q.shrink_to_fit();
            for(int q=1;q<active.size();q++)
                if(active[q]!=active[q-1])ok_q.push_back(q);

            for(auto p:ok_p)
            {
                push(p,cur[p]+1);//do not cut

                for(auto q:ok_q)
                {
                    if(p+q+1>=SZ)break;

                    push(p+q+1,cur[p]+active[q]);
                    //ret[p+q+1]=max(ret[p+q+1],cur[p]+active[q]);
                }
            }

            cur=ret;
            for(int i=1;i<cur.size();i++)
                cur[i]=max(cur[i],cur[i-1]);
        }

    for(auto w:queries[node])
    {
        for(int i=0;i<cur.size();i++)
            outp[w.second]=max(outp[w.second],cur[i]-i*w.first);
    }

    //cout<<node<<" -> ";for(auto w:cur)cout<<w<<" ";cout<<endl;

    return cur;
}

int g[nmax],K_FIXED;

pair<int,int> edge[nmax];
int pointer=0;

void order_edges(int node,int parent)
{
    for(auto w:adj[node])
        if(w!=parent)
        {
            order_edges(w,node);

            pointer++;

            edge[pointer]={node,w};
        }
}

mt19937 rng(42);

vector< pair<int/*node*/,int/*id*/> > small_queries[nmax];

int main()
{
    scanf("%i",&n);

    for(int i=1;i<n;i++)
    {
        int u,v;

        scanf("%i%i",&u,&v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    scanf("%i",&q);

    for(int i=1;i<=q;i++)
    {
        int v,k;

        scanf("%i%i",&v,&k);

        if(k<=C)small_queries[k].push_back({v,i});
        else queries[v].push_back({k,i});
    }

    dfs(1,1);

    order_edges(1,1);

    for(K_FIXED=0;K_FIXED<=C;K_FIXED++)
    {
        memset(g,0,sizeof(g));

        for(int i=1;i<=pointer;i++)
            g[edge[i].first]+=max(g[edge[i].second]-K_FIXED,1);

        for(auto w:small_queries[K_FIXED])
            outp[w.second]=max(outp[w.second],g[w.first]);
    }

    for(int i=1;i<=q;i++)printf("%i\n",outp[i]);

    return 0;
}