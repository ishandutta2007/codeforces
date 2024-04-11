#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

struct info
{
    int type,u,v;
};
info inp[nmax];

int mem[nmax];

int parent[nmax];

void eval_proper(int i)
{
    if(inp[i].type==0)
    {
        eval_proper(inp[i].u);
        eval_proper(inp[i].v);

        mem[i]=mem[inp[i].u]&mem[inp[i].v];
    }

    if(inp[i].type==1)
    {
        eval_proper(inp[i].u);
        eval_proper(inp[i].v);

        mem[i]=mem[inp[i].u]^mem[inp[i].v];
    }

    if(inp[i].type==2)
    {
        eval_proper(inp[i].u);
        eval_proper(inp[i].v);

        mem[i]=mem[inp[i].u]|mem[inp[i].v];
    }

    if(inp[i].type==3)
    {
        eval_proper(inp[i].u);

        mem[i]=!mem[inp[i].u];
    }

    if(inp[i].type==4)mem[i]=inp[i].u;
}

int dp[nmax][2];

int eval_wrong(int node,int wrong_child,int new_val)
{
    if(dp[wrong_child][new_val]!=-1)return dp[wrong_child][new_val];

    if(node==0)return new_val;

    if(inp[node].type==0)
    {
        int val_u=(inp[node].u==wrong_child?new_val:mem[inp[node].u]);
        int val_v=(inp[node].v==wrong_child?new_val:mem[inp[node].v]);

        dp[wrong_child][new_val]=eval_wrong(parent[node],node,val_u&val_v);
    }

    if(inp[node].type==1)
    {
        int val_u=(inp[node].u==wrong_child?new_val:mem[inp[node].u]);
        int val_v=(inp[node].v==wrong_child?new_val:mem[inp[node].v]);

        dp[wrong_child][new_val]=eval_wrong(parent[node],node,val_u^val_v);
    }

    if(inp[node].type==2)
    {
        int val_u=(inp[node].u==wrong_child?new_val:mem[inp[node].u]);
        int val_v=(inp[node].v==wrong_child?new_val:mem[inp[node].v]);

        dp[wrong_child][new_val]=eval_wrong(parent[node],node,val_u|val_v);
    }

    if(inp[node].type==3)
    {
        dp[wrong_child][new_val]=eval_wrong(parent[node],node,!new_val);
    }

    return dp[wrong_child][new_val];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n;

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string cur;

        cin>>cur;

        if(cur=="AND")inp[i].type=0;
        else if(cur=="XOR")inp[i].type=1;
        else if(cur=="OR")inp[i].type=2;
        else if(cur=="NOT")inp[i].type=3;
        else inp[i].type=4;

        if(inp[i].type<=2)cin>>inp[i].u>>inp[i].v;
        else cin>>inp[i].u;

        if(inp[i].type!=4)
        {
            parent[inp[i].u]=i;
            parent[inp[i].v]=i;
        }
    }

    eval_proper(1);

    memset(dp,-1,sizeof(dp));

    for(int i=1;i<=n;i++)
        if(inp[i].type==4)
        {
            cout<<eval_wrong(parent[i],i,!inp[i].u);
        }

    cout<<endl;

    return 0;
}