#include<bits/stdc++.h>
using namespace std;

const int nmax=5e5+42,mod=998244353;

int n;
vector<int> adj[nmax];

int outp;

int inv_2;

int free(int node,int par)//probability to be unmatched
{
    long long total=1;

    for(auto k:adj[node])
        if(k!=par)
        {
            long long help=free(k,node);

            help=(help*inv_2)%mod;

            help=(1-help+mod)%mod;

            total=total*help%mod;
        }

    outp=(outp+1LL*(1-total)*2)%mod;

    outp=(outp+mod)%mod;

    return total;
}
int main()
{
    scanf("%i",&n);

    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    inv_2=(mod+1)/2;

    free(1,0);

    for(int i=1;i<n;i++)outp=outp*2%mod;

    printf("%i\n",outp);
    return 0;
}