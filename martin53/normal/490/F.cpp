#include<bits/stdc++.h>
using namespace std;
const int nmax=6e3+42;
int n,r[nmax];
vector<int> adj[nmax];
int ans[nmax];
int outp=0;

void add_edge(int a,int b)
{
    adj[a].push_back(b);
}
void remove_edge(int a,int b)
{
    int SZ=adj[a].size();
    for(int i=0;i<SZ;i++)
        if(adj[a][i]==b)
        {
            adj[a].erase(adj[a].begin()+i,adj[a].begin()+i+1);
            break;
        }
}
int node_now;
void go(int node,int par)
{
    if(r[node_now]<r[node])
    {
        ans[node_now]=max(ans[node_now],ans[node]);
    }

    for(auto k:adj[node])
        if(k!=par)
            go(k,node);
}
void find_ans(int node,int par)
{
ans[node]=0;
node_now=node;
go(node,par);
ans[node]++;
outp=max(ans[node],outp);
//cout<<node<<" "<<par<<" -> "<<ans[node]<<endl;
}
void dfs(int node,int par)
{
    for(auto k:adj[node])
        if(k!=par)
        dfs(k,node);
    find_ans(node,par);
}
void solve(int node,int par)
{
    //cout<<node<<" : ";for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
    vector<int> help=adj[node];
    for(auto k:help)
        if(k!=par)
        {
            /*
            add_edge(k,node);
            remove_edge(node,k);
            */

            int a_node=ans[node],a_k=ans[k];

            ans[node]=0;
            ans[k]=0;
            find_ans(node,k);
            find_ans(k,k);

            solve(k,node);

            /*
            add_edge(node,k);
            remove_edge(k,node);
            */

            ans[k]=a_k;
            ans[node]=a_node;
        }
}
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)
    scanf("%i",&r[i]);
int a,b;
for(int i=1;i<n;i++)
{
    scanf("%i%i",&a,&b);
    add_edge(a,b);
    add_edge(b,a);
}

dfs(1,1);

solve(1,1);

printf("%i\n",outp);
return 0;
}