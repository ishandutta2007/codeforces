#include<bits/stdc++.h>
using namespace std;

const int nmax=2e6+42;

vector<int> adj[nmax],trav[nmax];//2*i-1 -> person, 2*i -> cat

int n,m;

bool been[nmax];

stack<int> active;

void dfs(int node)
{
    if(been[node])return;
    been[node]=1;

    for(auto k:adj[node])
        dfs(k);

    active.push(node);
}

int comp[nmax],pointer_comp;

void dfs_trav(int node)
{
    if(comp[node])return;

    comp[node]=pointer_comp;

    for(auto k:trav[node])
        dfs_trav(k);
}

vector<int> adj_comp[nmax];
int in[nmax];

queue<int> q;
int topological_id[nmax];

void solve()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=2*n;i++)adj[i]={};

    for(int i=1;i<=m;i++)
    {
        int u,v;

        scanf("%i%i",&u,&v);

        adj[2*u-1].push_back(2*v-1);
        adj[2*v].push_back(2*u);
    }
    /*
    for(int i=1;i<=2*n;i++)
    {
        cout<<"adj "<<i<<" -> ";for(auto w:adj[i])cout<<w<<" ";cout<<endl;
    }
    */
    for(int i=1;i<=2*n;i++)been[i]=0;

    for(int i=1;i<=2*n;i++)
        if(been[i]==0)
        {
            dfs(i);
        }

    for(int i=1;i<=2*n;i++)trav[i]={};

    for(int i=1;i<=2*n;i++)
    {
        for(auto j:adj[i])
            trav[j].push_back(i);
    }

    for(int i=1;i<=2*n;i++)comp[i]=0;

    pointer_comp=0;

    for(int i=1;i<=2*n;i++)
    {
        int tp=active.top();
        active.pop();

        if(comp[tp]==0)
        {
            pointer_comp++;
            dfs_trav(tp);
        }
    }
    /*
    for(int i=1;i<=2*n;i++)
        cout<<i<<" -> "<<comp[i]<<endl;
    */
    bool broken[2]={1,1};

    for(int i=1;i<=2*n;i=i+2)
        if(comp[i]!=comp[1])broken[0]=0;

    for(int i=2;i<=2*n;i=i+2)
        if(comp[i]!=comp[2])broken[1]=0;

    if(broken[0]||broken[1])
    {
        printf("No\n");
        return;
    }

    for(int i=1;i<=pointer_comp;i++)
    {
        adj_comp[i]={};
        in[i]=0;
    }

    for(int i=1;i<=2*n;i++)
        for(auto j:adj[i])
            if(comp[i]!=comp[j])
            {
                in[comp[j]]++;
                adj_comp[comp[i]].push_back(comp[j]);
            }

    set<int> taken={};

    bool prv=0;

    for(int i=1;i<=2*n;i=i+2)
    {
        if(taken.count(comp[i])||taken.count(comp[i+1])||in[comp[i]]||in[comp[i+1]])
        {
            if(taken.count(comp[i])==0&&in[comp[i]]==0)
            {
                taken.insert(comp[i]);
                q.push(comp[i]);
            }

            if(taken.count(comp[i+1])==0&&in[comp[i+1]]==0)
            {
                taken.insert(comp[i+1]);
                q.push(comp[i+1]);
            }
            continue;
        }

        if(prv)
        {
            taken.insert(comp[i]);
            q.push(comp[i]);

            taken.insert(comp[i+1]);
            q.push(comp[i+1]);
        }
        else
        {
            taken.insert(comp[i+1]);
            q.push(comp[i+1]);

            taken.insert(comp[i]);
            q.push(comp[i]);
        }

        prv=!prv;

    }

    for(int t=1;t<=pointer_comp;t++)
    {
        int tp=q.front();

        q.pop();

        topological_id[tp]=t;

        for(auto k:adj_comp[t])
        {
            in[k]--;

            if(in[k]==0)q.push(k);
        }
    }

    vector<int> people={},cats={};

    for(int i=1;i<=2*n;i=i+2)
        if(topological_id[comp[i]]<topological_id[comp[i+1]])cats.push_back((i+1)/2);
        else people.push_back((i+1)/2);

    printf("Yes\n");

    if(people.size()&&cats.size())
    {
        printf("%i %i\n",people.size(),cats.size());
        for(auto k:people)printf("%i ",k);printf("\n");
        for(auto k:cats)printf("%i ",k);printf("\n");
        return;
    }

    assert(0==1);
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