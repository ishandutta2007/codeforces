#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=3e4+20;
vector<int>adj[maxn];
bool visited[maxn];
int t,n;
void dfs(int v)
{
    visited[v]=1;
    if(v == t)
    {
        cout<<"YES";
        exit(0);
    }
    for(int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if(!visited[u])
            dfs(u);
    }
}
int main()
{
    cin>>n>>t;
    int a;
    for(int i=1;i<n;i++)
    {
        cin>>a;
        adj[i].push_back(i+a);
    }
    dfs(1);
    cout<<"NO";
}