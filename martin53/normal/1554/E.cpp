#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42,mod=998244353;

int n;
vector<int> adj[nmax];

int dvd[nmax],exact[nmax];

int k_now;

int eval(int node,int par)//-1 -> wrong, 0 -> blocked, 1 -> not blocked
{
    int sum=0;

    for(auto w:adj[node])
        if(w!=par)
        {
            int cur=eval(w,node);

            if(cur==-1)return -1;

            sum+=cur;
        }

    if(sum%k_now==0)return 1;

    if(sum%k_now==k_now-1)return 0;

    return -1;
}
int eval(int k)
{
    k_now=k;

    if((n-1)%k)return 0;

    if(eval(1,0)!=-1)return 1;

    return 0;
}
void solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)adj[i]={},dvd[i]=0;

    for(int i=1;i<n;i++)
    {
        int u,v;

        scanf("%i%i",&u,&v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dvd[1]=1;
    for(int i=2;i<=n;i++)dvd[1]=dvd[1]*2%mod;

    for(int k=2;k<=n;k++)
    {
        dvd[k]=eval(k);
    }

    for(int k=n;k>=1;k--)
    {
        exact[k]=dvd[k];

        for(int j=2*k;j<=n;j=j+k)
            exact[k]=(exact[k]-exact[j]+mod)%mod;
    }

    for(int k=1;k<=n;k++)printf("%i ",exact[k]);printf("\n");
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        solve();
    }

    return 0;
}