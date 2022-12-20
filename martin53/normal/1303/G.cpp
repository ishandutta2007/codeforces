#include<bits/stdc++.h>
using namespace std;

const int nmax=150000+42;

vector<int> adj[nmax];

int n,inp[nmax];
bool been[nmax];

vector< pair< pair<long long/*prefix sum*/,int/*count*/>,long long/*sum*/> > mem_up,mem_down;

long long outp=0;

void dfs_up(int node,int par,long long sum_all,int cnt,long long sum)
{
    //cout<<"mem_up "<<node<<" "<<sum_all<<" "<<cnt<<" "<<sum<<endl;

    mem_up.push_back({{sum_all,cnt},sum});

    outp=max(outp,sum_all);

    for(auto k:adj[node])
        if(been[k]==0&&k!=par)
            dfs_up(k,node,sum_all+1LL*(cnt+1)*inp[k],cnt+1,sum+inp[k]);
}

void dfs_down(int node,int par,long long sum_all,int cnt,long long sum)
{
    //cout<<"mem_down "<<node<<" "<<sum_all<<" "<<cnt<<" "<<sum<<endl;

    mem_down.push_back({{sum_all,cnt},sum});

    outp=max(outp,sum_all);

    for(auto k:adj[node])
        if(been[k]==0&&k!=par)
            dfs_down(k,node,sum_all+sum+inp[k],cnt+1,sum+inp[k]);
}

int SZ[nmax];

void dfs_SZ(int node,int par)
{
    SZ[node]=1;
    for(auto k:adj[node])
        if(been[k]==0&&k!=par)
        {
            dfs_SZ(k,node);
            SZ[node]+=SZ[k];
        }
}

int centroid(int node)
{
    dfs_SZ(node,node);

    int low=SZ[node]/2;

    while(SZ[node]>low)
    {
        bool go=0;

        for(auto k:adj[node])
            if(SZ[k]<SZ[node]&&SZ[k]>low)
            {
                go=1;
                node=k;
            }
        if(go==0)break;
    }
    return node;
}

vector< pair<long long,long long> > lines[nmax];//a*x+b

vector< pair<long long,long long> > my_merge(vector< pair<long long,long long> > given,vector< pair<long long,long long> > other)
{
    for(auto k:other)
        given.push_back(k);

    sort(given.begin(),given.end());

    vector< pair<long long,long long> > ret={};

    for(auto k:given)
    {
        while(ret.size()&&ret.back().first<=k.first&&ret.back().second<=k.second)ret.pop_back();
        ret.push_back(k);
    }
    return ret;
}
void init()
{
    for(int i=0;i<20;i++)lines[i]={};
}

void push(int id,vector< pair<long long,long long> > cur)
{
    if(lines[id].size()==0)
    {
        lines[id]=cur;
        return;
    }

    push(id+1,my_merge(cur,lines[id]));

    lines[id]={};
}

long long eval(long long a,long long b)
{
    long long ret=0;

    for(int i=0;i<=20;i++)
        for(auto w:lines[i])
        ret=max(ret,a*w.first+w.second+b);

    return ret;
}
void solve(int node)
{
    node=centroid(node);

    if(inp[node]>outp)outp=inp[node];

    //cout<<"go "<<node<<endl;

    vector< vector< pair< pair<long long/*prefix sum*/,int/*count*/>,long long/*sum*/> > > up={},down={};

    for(auto k:adj[node])
        if(been[k]==0)
        {
            mem_up={};
            mem_down={};

            dfs_up(k,node,inp[node]+2*inp[k],2,inp[node]+inp[k]);

            dfs_down(k,node,inp[k],1,inp[k]);

            outp=max(outp,2LL*inp[node]+inp[k]);

            up.push_back(mem_up);
            down.push_back(mem_down);
        }

    init();

    for(int i=0;i<up.size();i++)
    {
        for(auto q:down[i])
            outp=max(outp,eval(q.first.second,q.first.first));

        for(auto p:up[i])
            push(0,{{p.second,p.first.first}});
    }

    reverse(up.begin(),up.end());
    reverse(down.begin(),down.end());

    init();

    for(int i=0;i<up.size();i++)
    {
        for(auto q:down[i])
            outp=max(outp,eval(q.first.second,q.first.first));

        for(auto p:up[i])
            push(0,{{p.second,p.first.first}});
    }

    been[node]=1;
    for(auto k:adj[node])
        if(been[k]==0)solve(k);
}
int main()
{
    scanf("%i",&n);
    for(int i=2;i<=n;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    solve(1);

    printf("%lld\n",outp);
    return 0;
}