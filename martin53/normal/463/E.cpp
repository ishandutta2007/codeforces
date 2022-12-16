#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,LIM=2e6+42;
int n,q;
vector<int> adj[nmax];
bool prime[LIM];//0-> prime
vector<int> good[LIM];
int a[nmax];
vector<int> divisors[LIM];
void precompute()
{
    prime[0]=1;
    prime[1]=1;
    int p=2;
    int sum=0;
    while(p<LIM)
    {
        if(1LL*p*p<LIM)for(int j=p*p;j<LIM;j=j+p)prime[j]=1;
        for(int j=p;j<LIM;j=j+p)divisors[j].push_back(p);
        sum=sum+LIM/p;
        p++;
        while(prime[p])p++;
    }

//cout<<sum<<endl;

}
int output[nmax];
int depth[nmax];
void normal_dfs(int node,int parent)
{
    for(auto k:adj[node])
        if(k!=parent)
        {
        depth[k]=depth[node]+1;
        normal_dfs(k,node);
        }
}
void add_node(int node,int value)
{
    for(auto k:divisors[value])
        good[k].push_back(node);
}
void remove_node(int node,int value)
{
    for(auto k:divisors[value])
        good[k].pop_back();
}

void dfs(int node,int parent)
{
    int ans=-1;
    for(auto k:divisors[a[node]])
    {
        if(good[k].size())
        {
            if(ans==-1)ans=good[k].back();
            else
            {
                if(depth[good[k].back()]>depth[ans])ans=good[k].back();
            }
        }
    }

    output[node]=ans;
    add_node(node,a[node]);
    for(auto k:adj[node])
        if(k!=parent)
        {
        dfs(k,node);
        }
    remove_node(node,a[node]);
}
void evaluate()
{
dfs(1,0);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
precompute();
cin>>n>>q;
for(int i=1;i<=n;i++)cin>>a[i];
int x,y;
for(int i=1;i<n;i++)
{
cin>>x>>y;
adj[x].push_back(y);
adj[y].push_back(x);
}
normal_dfs(1,0);

evaluate();

int type,v,w;
for(int i=1;i<=q;i++)
{
    cin>>type;
    if(type==1)
    {
    cin>>v;
    cout<</*"output= "<<*/output[v]<<endl;
    }
    else
    {
    cin>>v>>w;
    a[v]=w;
    evaluate();
    }
}
return 0;
}