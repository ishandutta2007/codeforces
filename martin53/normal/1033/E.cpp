#include<bits/stdc++.h>
using namespace std;

const int nmax=6e2+42;

vector<int> adj[nmax];
int n;

int ask(vector<int> cur)
{
    if(cur.size()<=1)return 0;

    cout<<"? "<<cur.size()<<endl;
    for(auto w:cur)cout<<w<<" ";cout<<endl;
    cout.flush();

    int ret;
    cin>>ret;
    return ret;
}

int parent[nmax];
int root(int node)
{
    if(node==parent[node])return node;
    parent[node]=root(parent[node]);
    return parent[node];
}
bool is_edge(int node,vector<int> LHS)
{
    int mem=ask(LHS);

    LHS.push_back(node);

    if(mem==ask(LHS))return 0;
    return 1;
}
bool find_edge(int node,vector<int> LHS)
{
    if(is_edge(node,LHS)==0)return 0;

    while(LHS.size()>1)
    {
        vector<int> groups[2]={{},{}};

        for(int i=0;i<LHS.size();i++)
            groups[i%2].push_back(LHS[i]);

        if(is_edge(node,groups[0]))LHS=groups[0];
        else LHS=groups[1];
    }

    adj[node].push_back(LHS[0]);
    adj[LHS[0]].push_back(node);

    //cout<<"found "<<node<<" "<<LHS[0]<<endl;

    parent[root(LHS[0])]=root(node);
    return 1;
}

int colour[nmax];

void dfs(int node,int col)
{
    if(colour[node]!=-1)return;

    colour[node]=col;

    for(auto k:adj[node])
        dfs(k,!col);
}

bool been[nmax];

vector<int> path={};

void dfs_path(int node,int to)
{
    path.push_back(node);

    if(been[node])
    {
        path.pop_back();
        return;
    }
    been[node]=1;

    if(node==to)
    {
        cout<<"N "<<path.size()<<endl;
        for(auto w:path)cout<<w<<" ";cout<<endl;
        exit(0);
    }

    for(auto k:adj[node])
    {
        dfs_path(k,to);
    }
    path.pop_back();
}
void find_wrong(vector<int> comp)
{
    //we want to find an edge between comp and comp

    while(comp.size())
    {
        int mem=comp.back();

        comp.pop_back();

        if(is_edge(mem,comp)==0)continue;

        for(auto w:comp)
            if(ask({mem,w}))
            {
                dfs_path(mem,w);
            }
    }
}

int main()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        parent[i]=i;

        while(1)
        {
            vector<int> to_check={};

            for(int j=1;j<i;j++)
                if(root(j)!=root(i))to_check.push_back(j);

            if(to_check.size()==0)break;

            if(find_edge(i,to_check)==0)break;
        }
    }

    memset(colour,-1,sizeof(colour));

    dfs(1,0);

    vector<int> groups[2]={{},{}};

    for(int i=1;i<=n;i++)
        groups[colour[i]].push_back(i);

    if(ask(groups[0]))find_wrong(groups[0]);
    else if(ask(groups[1]))find_wrong(groups[1]);
    else
    {
        cout<<"Y "<<groups[0].size()<<endl;
        for(auto w:groups[0])cout<<w<<" ";cout<<endl;
    }
    return 0;
}