#include<bits/stdc++.h>
using namespace std;

const int nmax=3e5+42,mod=998244353,MX=20;

int n,k;

vector<int> adj[nmax];
int inp[nmax];

int t,in[nmax],out[nmax],up[MX][nmax],depth[nmax];

int lca(int u,int v)
{
    if(depth[u]<depth[v])swap(u,v);

    for(int i=MX-1;i>=0;i--)
        if(depth[u]-(1<<i)>=depth[v])u=up[i][u];

    if(u==v)return u;

    for(int i=MX-1;i>=0;i--)
        if(up[i][u]!=up[i][v])u=up[i][u],v=up[i][v];

    return up[0][u];
}
void dfs(int node,int par)
{
    t++;
    in[node]=t;
    depth[node]=depth[par]+1;

    up[0][node]=par;
    for(int j=1;j<MX;j++)
        up[j][node]=up[j-1][up[j-1][node]];

    for(auto k:adj[node])
        if(k!=par)dfs(k,node);

    out[node]=t;
}

vector<int> there[nmax];

bool cmp(int a,int b)
{
    return in[a]<in[b];
}

vector<int> make_virtual(vector<int> cur)
{
    sort(cur.begin(),cur.end(),cmp);

    set<int> in={};
        for(auto w:cur)
            in.insert(w);

    for(int i=1;i<cur.size();i++)
        in.insert(lca(cur[i-1],cur[i]));

    cur={};
    for(auto w:in)
        cur.push_back(w);

    sort(cur.begin(),cur.end(),cmp);
    return cur;
}

void my_fill(int to,int from,int colour)
{
    //cout<<"my_fill "<<to<<" "<<from<<" "<<colour<<endl;

    while(1)
    {
        //cout<<"go "<<from<<endl;

        if(inp[from]!=0&&inp[from]!=colour)
        {
            printf("0\n");
            exit(0);
        }

        inp[from]=colour;

        if(from==to)break;

        from=up[0][from];
    }
}

vector<int> new_adj[nmax];

int root_of[nmax];

void compress()
{
    dfs(1,1);

    //for(int i=1;i<=n;i++)cout<<i<<" -> "<<in[i]<<" "<<out[i]<<endl;

    for(int i=1;i<=k;i++)
    {
        vector<int> cur=make_virtual(there[i]);

        //cout<<"found "<<i<<" -> ";for(auto w:cur)cout<<" "<<w;cout<<endl;

        vector<int> active={cur[0]};

        for(int pos=1;pos<cur.size();pos++)
        {
            int node=cur[pos];

            while(active.size()&&out[active.back()]<out[node])active.pop_back();

            assert(active.size());

            my_fill(active.back(),node,i);

            active.push_back(node);
        }
    }

    //for(int i=1;i<=n;i++)cout<<i<<" -> "<<inp[i]<<" ; ";cout<<endl;

    for(int i=n;i>=1;i--)
        if(inp[i])root_of[inp[i]]=i;

    for(int i=1;i<=n;i++)
        for(auto j:adj[i])
            if(inp[i]&&inp[j]&&inp[i]==inp[j])continue;
            else
            {
                int u=i,v=j;
                if(inp[i])u=root_of[inp[i]];
                if(inp[j])v=root_of[inp[j]];

                new_adj[u].push_back(v);
                //new_adj[v].push_back(u);
            }
    /*
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" -> ";for(auto j:new_adj[i])cout<<j<<" ";cout<<endl;
    }
    */
}

int dp[2][nmax];

int rec(int take,int node,int parent)
{
    //cout<<"eval "<<take<<" "<<node<<" "<<parent<<endl;

    if(dp[take][node]!=-1)return dp[take][node];

    int children=0;
    for(auto k:new_adj[node])
        if(k!=parent)children++;

    if(children==0)
    {
        //cout<<"go "<<take<<" "<<node<<endl;

        if(inp[node]==0&&take==0)return 1;
        if(inp[node]&&take)return 1;
        if(inp[node]&&take==0)return 1;
        return 0;
    }

    if(take==0&&inp[node])
    {
        dp[take][node]=rec(1,node,parent);

        //cout<<take<<" "<<node<<" "<<parent<<" -> "<<dp[take][node]<<endl;

        return dp[take][node];
    }
    int ret=0;

    if(take==0)//inp[node]=0
    {
        ret=rec(1,node,parent);//cut the parent edge

        long long prod=1;

        for(auto k:new_adj[node])
            if(k!=parent)prod=prod*rec(0,k,node)%mod;

        ret=(ret+prod)%mod;
    }
    else//take=1
    {
        if(inp[node])
        {
            long long prod=1;

            for(auto k:new_adj[node])
                if(k!=parent)prod=prod*rec(0,k,node)%mod;

            ret=prod;
        }
        else//inp[node]=0
        {
            vector<int> other={};
            vector<int> mem={};

            vector<long long> pref_prod={},suff_prod={};

            for(auto k:new_adj[node])
                if(k!=parent)
                {
                    other.push_back(k);
                    mem.push_back(rec(0,k,node));
                }

            long long prod=1;
            for(int i=0;i<other.size();i++)
            {
                prod=prod*mem[i]%mod;
                pref_prod.push_back(prod);
            }

            prod=1;
            for(int i=other.size()-1;i>=0;i--)
            {
                prod=prod*mem[i]%mod;
                suff_prod.push_back(prod);
            }

            reverse(suff_prod.begin(),suff_prod.end());

            //cout<<take<<" "<<node<<", mem: ";for(auto w:mem)cout<<w<<" ";cout<<endl;

            for(int i=0;i<other.size();i++)
            {
                long long cur=rec(1,other[i],node);

                //cout<<other[i]<<" -> "<<"given: "<<cur;

                if(i)cur=cur*pref_prod[i-1]%mod;
                if(i+1<other.size())cur=cur*suff_prod[i+1]%mod;

                //cout<<" final "<<cur<<endl;

                ret=(ret+cur)%mod;
            }
        }
    }

    dp[take][node]=ret;

    //cout<<take<<" "<<node<<" "<<parent<<" -> "<<ret<<endl;

    return ret;
}
int main()
{
    scanf("%i%i",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
        there[inp[i]].push_back(i);
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    compress();

    memset(dp,-1,sizeof(dp));

    printf("%i\n",rec(1,1,1));
    return 0;
}