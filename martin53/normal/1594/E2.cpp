#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7,nmax=62;

/*
a white node can not be neighboring with white and yellow nodes;
a yellow node can not be neighboring with white and yellow nodes;
a green node can not be neighboring with green and blue nodes;
a blue node can not be neighboring with green and blue nodes;
a red node can not be neighboring with red and orange nodes;
an orange node can not be neighboring with red and orange nodes;
*/

map<string,int> help;

map<long long,int> seen;

long long pwr(long long a,long long b)
{
    long long ret=1;

    while(b)
    {
        if(b%2)ret=ret*a%mod;
        a=a*a%mod;
        b=b/2;
    }

    return ret;
}

map< pair<long long,int> ,int> mem;

long long idle[nmax];

set<long long> PARENTS;

bool can(long long node,int col,int col_parent)
{
    if(col==col_parent||abs(col-col_parent)==3)return 0;

    if(seen.count(node))
    {
        if(seen[node]!=col)return 0;
    }

    return 1;
}

long long rec(long long node,int col_parent,int lvl)
{
    if(lvl==0)return 1;

    if(mem.count({node,col_parent}))return mem[{node,col_parent}];

    if(PARENTS.count(node)==0)return idle[lvl];

    long long ret=0;
    for(int col=0;col<6;col++)
        if(can(node,col,col_parent))
        {
            ret=(ret+rec(node*2,col,lvl-1)*rec(node*2+1,col,lvl-1))%mod;
        }

    //cout<<node<<" "<<col_parent<<" "<<lvl<<" -> "<<ret<<endl;

    mem[{node,col_parent}]=ret;
    return ret;
}

int main()
{
    help["white"]=0;
    help["yellow"]=3;

    help["green"]=1;
    help["blue"]=4;

    help["red"]=2;
    help["orange"]=5;

    for(int k=1;k<=60;k++)
        idle[k]=pwr(4,(1LL<<k)-1)%mod;

    int k;
    cin>>k;

    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        long long node;
        string msg;

        cin>>node>>msg;

        seen[node]=help[msg];

        while(node)
        {
            PARENTS.insert(node);
            node=node/2;
        }
    }

    printf("%lld\n",rec(1,1e9,k));

    return 0;
}