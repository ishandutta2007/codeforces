
#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,m;

struct edges
{
    int u,v,c;
    int id;
};

edges inp[nmax];
bool cmp(edges a,edges b)
{
    return a.c<b.c;
}
pair<int,int> original_edges[nmax];

int parent[nmax],parent_group[nmax];
int root_group(int node)
{
    if(node==parent_group[node])return node;
    parent_group[node]=root_group(parent_group[node]);
    return parent_group[node];
}

int root(int node)
{
    if(node==parent[node])return node;
    parent[node]=root(parent[node]);
    return parent[node];
}

vector<int> in_root[nmax];

vector<int> roots[nmax];

vector<int> to_solve[nmax];

vector<int> adj[nmax];
bool is_edge(int u,int v)
{
    int pos=lower_bound(adj[u].begin(),adj[u].end(),v)-adj[u].begin();

    if(pos<adj[u].size()&&adj[u][pos]==v)return 1;
    return 0;
}

int outp[nmax];

void hand_merge(int big,int small,int cost)
{
    big=root(big);
    small=root(small);

    if(big==small)return;

    if(in_root[big].size()+to_solve[big].size()<in_root[small].size()+to_solve[small].size())swap(big,small);

    /*
    cout<<"\thand_merge "<<big<<" "<<small<<" "<<cost<<endl;

    cout<<"small in_root: ";for(auto w:in_root[small])cout<<w<<" ";cout<<endl;
    cout<<"small to_solve: ";for(auto w:to_solve[small])cout<<w<<" ";cout<<endl;

    cout<<"big in_root: ";for(auto w:in_root[big])cout<<w<<" ";cout<<endl;
    cout<<"big to_solve: ";for(auto w:to_solve[big])cout<<w<<" ";cout<<endl;
    */

    for(auto w:in_root[small])
        parent[w]=big;

    //for(int i=1;i<=n;i++)cout<<i<<" with "<<root(i)<<"\t";cout<<endl;

    for(auto w:in_root[small])
        in_root[big].push_back(w);

    for(auto w:to_solve[small])
        if(root(original_edges[w].first)==root(original_edges[w].second))
        {
            //cout<<"solved "<<w<<endl;

            if(outp[w]==0)outp[w]=cost;
        }
        else to_solve[big].push_back(w);

    //cout<<"---"<<endl;
}

void my_merge(int u,int v,int id)
{
    u=root_group(u);
    v=root_group(v);

    //cout<<"my_merge "<<u<<" "<<v<<" "<<id<<endl;

    if(u==v)
    {
        return;
    }

    vector< pair<int,int> > to_merge={};

    for(auto s:roots[u])
        for(auto t:roots[v])
            if(root(s)!=root(t))
            {
                //cout<<"test_merge "<<u<<" "<<v<<endl;

                bool gaz=1;

                for(int id_p=0;id_p<in_root[s].size()&&gaz;id_p++)
                    for(int id_q=0;id_q<in_root[t].size()&&gaz;id_q++)
                    {
                        int p=in_root[s][id_p];
                        int q=in_root[t][id_q];

                        if(is_edge(p,q)==0)
                        {
                            gaz=0;

                            to_merge.push_back({s,t});
                            //hand_merge(p,q,inp[id].c);
                        }
                    }
            }

    for(auto w:to_merge)
        hand_merge(w.first,w.second,inp[id].c);

    set<int> new_roots={};

    for(auto s:roots[u])
        new_roots.insert(root(s));

    for(auto t:roots[v])
        new_roots.insert(root(t));

    parent_group[v]=u;
    roots[u]={};

    for(auto w:new_roots)
        roots[u].push_back(w);

    //cout<<"group "<<u<<" has roots ";for(auto w:roots[u])cout<<w<<" ";cout<<endl;
}

void solve()
{
    scanf("%i%i",&n,&m);

    /*
    n=1e4;
    m=n-1;
    mt19937 rng(42);
    */

    //cout<<"n= "<<n<<" m= "<<m<<endl;

    for(int i=1;i<=n;i++)
    {
        adj[i]={};

        in_root[i]={i};

        roots[i]={i};

        to_solve[i]={};
    }

    for(int i=1;i<=m;i++)
    {
        scanf("%i%i%i",&inp[i].u,&inp[i].v,&inp[i].c);

        original_edges[i]={inp[i].u,inp[i].v};

        /*
        inp[i].u=1;
        inp[i].v=i+1;
        inp[i].c=rng()%2+1;
        if(i==m)inp[i].u=2;
        */

        adj[inp[i].u].push_back(inp[i].v);
        adj[inp[i].v].push_back(inp[i].u);

        to_solve[inp[i].u].push_back(i);
        to_solve[inp[i].v].push_back(i);

        inp[i].id=i;
    }

    for(int i=1;i<=n;i++)
        sort(adj[i].begin(),adj[i].end());

    for(int i=1;i<=m;i++)outp[i]=0;

    for(int i=1;i<=n;i++)parent[i]=i;
    for(int i=1;i<=n;i++)parent_group[i]=i;

    sort(inp+1,inp+m+1,cmp);

    for(int i=1;i<=m;i++)
    {
        my_merge(inp[i].u,inp[i].v,i);
    }

    //cout<<"outp: ";

    for(int i=1;i<=m;i++)
        printf("%i ",outp[i]);
    printf("\n");
}

int main()
{
    int t;

    scanf("%i",&t);

    while(t)
    {
        t--;

        solve();
    }

    return 0;
}