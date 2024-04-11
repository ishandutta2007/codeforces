#include<bits/stdc++.h>
using namespace std;

const int nmax=150000+42,mod=998244353;

long long my_pow(long long a,int b)
{
    long long ret=1;

    while(b)
    {
        if(b%2)ret=ret*a%mod;
        b=b/2;
        a=a*a%mod;
    }

    return ret;
}
long long inv(long long a)
{
    return my_pow(a,mod-2);
}

int n,q;

vector<int> adj[nmax];

int in[nmax],out[nmax],depth[nmax],t,SZ[nmax];

long long fenwick[nmax];

void upd(int pos,long long val)
{
    while(pos<=n)
    {
        fenwick[pos]+=val;
        pos=pos+(pos&(-pos));
    }
}
long long query(int pos)
{
    long long ret=0;
    while(pos)
    {
        ret+=fenwick[pos];
        pos=pos-(pos&(-pos));
    }
    return ret;
}
void update(int l,int r,long long val)
{
    upd(l,val);
    upd(r+1,-val);
}

int parent[nmax];
void dfs(int node,int par)
{
    t++;
    in[node]=t;

    SZ[node]=1;

    parent[node]=par;

    for(auto k:adj[node])
        if(k!=par)
        {
            dfs(k,node);
            SZ[node]+=SZ[k];
        }
    out[node]=t;
}

int hsh[nmax];
void dfs_renum(int node,int par)
{
    t++;

    hsh[node]=t;

    //cout<<"hsh "<<node<<" "<<par<<" "<<t<<endl;

    vector< pair<int,int> > go={};
    for(auto k:adj[node])
        if(k!=par)go.push_back({SZ[k],k});

    sort(go.begin(),go.end());
    reverse(go.begin(),go.end());

    for(auto k:go)
        dfs_renum(k.second,node);
}

vector< pair<int,int> > edges={};

void renum()
{
    t=0;
    dfs(1,1);

    t=0;
    dfs_renum(1,1);

    for(int i=1;i<=n;i++)
        for(auto j:adj[i])
            edges.push_back({hsh[i],hsh[j]});

    for(int i=1;i<=n;i++)adj[i]={};

    for(auto k:edges)adj[k.first].push_back(k.second);

    t=0;
}

vector< pair< pair<int/*left*/,int/*right*/>, int/*coefficient*/> > there[nmax];

int main()
{
    scanf("%i%i",&n,&q);

    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    renum();

    for(int i=1;i<=n;i++)
        sort(adj[i].begin(),adj[i].end());

    dfs(1,1);

    for(int i=1;i<=n;i++)
    {
        map<int, pair<int,int> > mem={};
        for(auto k:adj[i])
            if(SZ[i]>SZ[k])
            {
                //there[i].push_back({{in[k],out[k]},SZ[k]});

                if(mem.count(SZ[k])==0)mem[SZ[k]]={in[k],out[k]};
                else mem[SZ[k]]={min(mem[SZ[k]].first,in[k]),max(mem[SZ[k]].second,out[k])};
            }


        for(auto k:mem)
            there[i].push_back({k.second,k.first});
    }
    for(int i=1;i<=q;i++)
    {
        int type;
        scanf("%i",&type);

        if(type==1)
        {
            int node,val;

            scanf("%i%i",&node,&val);

            node=hsh[node];

            update(1,n,1LL*val*n);

            if(node!=1)
            {
                update(1,n,-1LL*(n-SZ[node])*val);
                update(in[node],out[node],1LL*(n-SZ[node])*val);
            }

            for(auto k:there[node])
                update(k.first.first,k.first.second,-1LL*k.second*val);
        }

        else
        {
            int node;
            scanf("%i",&node);

            node=hsh[node];

            printf("%lld\n",query(in[node])%mod*inv(n)%mod);
        }

        /*
        cout<<"query: ";
        for(int j=1;j<=n;j++)
            cout<<query(in[j])<<" ";
        cout<<endl;
        */
    }
    return 0;
}