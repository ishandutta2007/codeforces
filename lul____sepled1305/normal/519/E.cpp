/** First LCA problem! **/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int M = 20;
int n,q,i,j,vis = 0;
int dp[N][M];
int depth[N];
int siz[N];
vector<int> G[N];

void dfs(int node,int par,int de)
{
    int ori = vis;
    vis++;
    depth[node] = de;
    int q = 1,w = 2;
    if(par != -1)
        dp[node][0] = par;
    while(w <= depth[node])
    {
        dp[node][q] = dp[dp[node][q-1]][q-1];
        q++;
        w*=2;
    }
    for(auto it: G[node])
    {
        if(it != par)
            dfs(it,node,de+1);
    }
    siz[node] = vis - ori;
}

int find_par(int node, int ran)
{
    int i;
    if(ran == 0)
        return node;
    int w = 1;
    for(i=0;i<20;i++)
    {
        if(w&ran)
        {
            node = dp[node][i];
        }
        w*=2;
    }
    return node;
}

int lca(int a, int b)
{
    int i;
    if(depth[a] < depth[b])
        swap(a,b);
    int diff = depth[a] - depth[b];
    a = find_par(a,diff);
    if(a == b)
        return a;
    for(i=19;i>=0;i--)
    {
        if(dp[a][i]!=dp[b][i])
        {
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}

int main()
{
    for(i=0;i<N;i++)
    for(j=0;j<M;j++)
        dp[i][j] = -1;
    cin>>n;
    for(i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0,-1,0);
    cin>>q;
    for(i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        if(depth[a]%2!=depth[b]%2)
            cout<<"0\n";
        else
        {
            int comm = lca(a,b);
            if(a == b)
                cout<<n<<"\n";
            else if(depth[a] == depth[b])
            {
                int he = depth[comm] - depth[a];
                he*=-1;
                cout<< n - siz[find_par(a,he-1)] - siz[find_par(b,he-1)]<<"\n";
            }
            else
            {
                int he = 2*depth[comm] - depth[a] - depth[b];
                he/=2;
                he*=-1;
                if(depth[a] < depth[b])
                    swap(a,b);
                int des = find_par(a,he);
                cout<<siz[des] - siz[find_par(a,he-1)]<<"\n";
            }
        }
    }
    return 0;
}