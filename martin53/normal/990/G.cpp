#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
long long ans[nmax];
int n;
vector<int> adj[nmax];
bool been[nmax],done[nmax];
int arr[nmax];
int SZ[nmax];
vector<int> visited;
void dfs(int node,int parent)
{
    SZ[node]=1;
    for(auto k:adj[node])
        if(k!=parent&&done[k]==0)
        {
        dfs(k,node);
        SZ[node]=SZ[node]+SZ[k];
        }
    //cout<<node<<" -> "<<SZ[node]<<endl;
}
int centroid(int node)
{
    visited={};
    dfs(node,0);
    int comp=SZ[node],parent=0;
    while(1)
    {
        bool stop=1;
        for(auto k:adj[node])
            if(done[k]==0&&k!=parent&&SZ[k]*2>comp)
            {
                stop=0;
                parent=node;
                node=k;
                break;
            }
        if(stop)break;
    }
    return node;
}
set<int> seen;
int mem[nmax];
void dfs_2(int node,int parent,int g_)
{
    if(done[node])return;
    ans[g_]++;
    if(parent)
    {
    seen.insert(g_);
    mem[g_]++;
    }
    for(auto k:adj[node])
        if(k!=parent)dfs_2(k,node,__gcd(g_,arr[k]));
}
set<int> seen_other;
int mem_other[nmax];
void dfs_3(int node,int parent,int g_)
{
    if(done[node])return;
    seen_other.insert(g_);
    mem_other[g_]++;
    for(auto k:adj[node])
        if(k!=parent)dfs_3(k,node,__gcd(g_,arr[k]));
}
void solve(int node)
{
    if(done[node])return;
    node=centroid(node);
    //cout<<"node= "<<node<<endl;
    seen={};
    dfs_2(node,0,arr[node]);

    for(auto k:adj[node])
        if(done[k]==0)
        {
            seen_other={};
            dfs_3(k,node,__gcd(arr[node],arr[k]));
            for(auto p:seen)
                for(auto q:seen_other)
                {
                ans[__gcd(p,q)]+=1LL*mem_other[q]*(mem[p]-mem_other[p]);
                //cout<<p<<" "<<q<<" -> "<<mem_other[q]<<" "<<mem[p]<<" "<<mem_other[p]<<endl;
                }
            for(auto q:seen_other)
                mem[q]=mem[q]-mem_other[q],mem_other[q]=0;
        }
    for(auto p:seen)
        mem[p]=0;

    done[node]=1;
    for(auto k:adj[node])
        solve(k);

}
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)scanf("%i",&arr[i]);
int x,y;
for(int i=1;i<n;i++)
{
    scanf("%i%i",&x,&y);
    adj[x].push_back(y);
    adj[y].push_back(x);
}
solve(1);
for(int i=1;i<nmax;i++)
    if(ans[i])printf("%i %lld\n",i,ans[i]);
return 0;
}
/*
4
6 2 3 1
1 2
1 3
3 4
*/