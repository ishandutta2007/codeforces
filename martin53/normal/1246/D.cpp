#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n;

int parent[nmax];
vector<int> adj[nmax];

int height[nmax],max_height[nmax];
void dfs(int node,int par,int h)
{
    height[node]=h;
    max_height[node]=h;

    for(auto k:adj[node])
        if(k!=par)
        {
        dfs(k,node,h+1);
        max_height[node]=max(max_height[node],max_height[k]);
        }
}

vector<int> order;

vector<int> moves;

bool cmp(int a,int b)
{
    return max_height[a]<max_height[b];
}
void solve(int node,int par)
{
    order.push_back(node);
    vector<int> children={};
    for(auto k:adj[node])
        if(k!=par)children.push_back(k);

    sort(children.begin(),children.end(),cmp);

    int SZ=children.size();

    int prev=-1;
    for(int i=0;i<SZ;i++)
    {
        solve(children[i],node);

        if(prev!=-1)
        {
            while(prev!=node)
            {
                moves.push_back(children[i]);
                prev=parent[prev];
            }
        }

        prev=order.back();
    }
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%i",&parent[i]);
        adj[parent[i]].push_back(i);
    }

    dfs(0,0,0);

    solve(0,0);

    for(auto k:order)printf("%i ",k);printf("\n");

    printf("%i\n",moves.size());

    for(auto k:moves)printf("%i ",k);printf("\n");

    return 0;
}