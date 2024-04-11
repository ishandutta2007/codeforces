#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;

int n;

vector<int> adj[nmax];

int perm[nmax];

int score=0;
int outp[nmax];

int dp[2][nmax];

int dfs(int node,int par)
{
    vector<int> ret={};
    for(auto k:adj[node])
        if(k!=par)
        {
            int val=dfs(k,node);
            if(val!=-1)ret.push_back(val);
        }

    if(ret.size()==0)return node;

    score+=2*ret.size();
    ret.push_back(node);

    for(int i=0;i<ret.size();i++)
    {
        outp[ret[i]]=ret[(i+1)%ret.size()];
    }

    return -1;
}

void print()
{
    printf("%i\n",score);
    for(int j=1;j<=n;j++)printf("%i ",outp[j]);
    exit(0);
}

bool cmp(int a,int b)
{
    return adj[a].size()>adj[b].size();
}
int main()
{
    memset(dp,-1,sizeof(dp));

    scanf("%i",&n);

    int u,v;

    for(int i=1;i<n;i++)
    {
        scanf("%i%i",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> order={};

    for(int i=1;i<=n;i++)order.push_back(i);

    sort(order.begin(),order.end(),cmp);

    for(auto i:order)
    {
        score=0;
        if(dfs(i,i)==-1)
        {
            print();
        }
    }

    assert(0==1);
    return 0;
}