#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42,mod=998244353;

long long pwr(long long a,int b)
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

int lowest[nmax];
int inv[nmax];

void init()
{
    inv[0]=1;
    inv[1]=1;

    for(int i=2;i<nmax;i++)
        inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;

    for(int i=1;i<nmax;i++)
        lowest[i]=i;

    for(int i=2;i<nmax;i++)
        if(lowest[i]==i)
        {
            for(int j=i;j<nmax;j+=i)
                lowest[j]=min(lowest[j],i);
        }
}

int n;
vector< pair<int, pair<int,int> > > adj[nmax];

int active[nmax];

int mini[nmax];

set<int> non_zero;

long long output;

void apply(int val,int coeff)
{
    while(val>1)
    {
        active[lowest[val]]+=coeff;
        mini[lowest[val]]=min(active[lowest[val]],mini[lowest[val]]);

        non_zero.insert(lowest[val]);

        val/=lowest[val];
    }
}

void dfs(int node,int parent,long long val)
{
    output=(output+val)%mod;

    for(auto w:adj[node])
        if(w.first!=parent)
        {
            apply(w.second.second,1);
            apply(w.second.first,-1);

            dfs(w.first,node,val*w.second.second%mod*inv[w.second.first]%mod);

            apply(w.second.first,1);
            apply(w.second.second,-1);
        }
}

int solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)adj[i]={};

    for(int t=1;t<n;t++)
    {
        int i,j,x,y;
        scanf("%i%i%i%i",&i,&j,&x,&y);

        adj[i].push_back({j,{x,y}});
        adj[j].push_back({i,{y,x}});
    }

    output=0;

    non_zero={};

    dfs(1,1,1);

    for(auto w:non_zero)
    {
        output=output*pwr(w,-mini[w])%mod;

        mini[w]=0;

        active[w]=0;
    }

    return output;
}

int main()
{
    init();

    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%i\n",solve());
    }

    return 0;
}