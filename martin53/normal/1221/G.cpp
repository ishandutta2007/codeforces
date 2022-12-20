#include<bits/stdc++.h>
using namespace std;
const int nmax=42;
int n,m;
vector<int> adj[nmax];
long long mask[nmax];

long long ways_0=1,ways_1=1,ways_2=1,ways_01,ways_12,ways_20=1;

int been[nmax];
void dfs(int node,int colour)
{
    if(been[node]!=-1)
    {
        if(been[node]!=colour)ways_1=0;
        return;
    }

    been[node]=colour;
    for(auto k:adj[node])
        dfs(k,!colour);
}

int dp[nmax/2][(1<<(nmax/2))+42];

int mask_mod;

int rec(int pos,int current_mask/*1-> can be both, 0-> must be zero*/)
{
    if(pos==0)return 1;

    if(dp[pos][current_mask]!=-1)return dp[pos][current_mask];

    int ret=rec(pos-1,current_mask);//choose 0
    if((current_mask&(1LL<<pos)))//choose 1
        ret=ret+rec(pos-1,current_mask&mask[pos]);

    dp[pos][current_mask]=ret;

    //cout<<pos<<" "<<current_mask<<" -> "<<ret<<endl;

    return ret;
}

long long anticliques(int pos,long long current_mask/*1-> can be both, 0-> must be zero*/)
{
    if(pos<=n/2)return rec(pos,current_mask&mask_mod);
    long long ret=anticliques(pos-1,current_mask);//choose 0
    if((current_mask&(1LL<<pos)))//choose 1
        ret=ret+anticliques(pos-1,current_mask&mask[pos]);

    return ret;
}
int main()
{
    scanf("%i%i",&n,&m);
    int u,v;

    for(int i=1;i<=n;i++)mask[i]=(1LL<<(n+1))-1;

    for(int i=1;i<=m;i++)
    {
        scanf("%i%i",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        mask[u]-=(1LL<<v);
        mask[v]-=(1LL<<u);
    }

    if(n==1||m==0)
    {
        printf("0\n");
        return 0;
    }

    for(int i=1;i<=n;i++)
        if(adj[i].size()==0)
        {
            ways_0=ways_0*2;
            ways_2=ways_2*2;
        }

    memset(been,-1,sizeof(been));
    for(int i=1;i<=n;i++)
    {
        if(been[i]==-1)
        {
            dfs(i,0);
            ways_1=ways_1*2;

            ways_20=ways_20*2;
        }
    }

    memset(dp,-1,sizeof(dp));

    mask_mod=(1<<(n/2))*2-1;

    ways_01=anticliques(n,(1LL<<n)*2-2);
    ways_12=ways_01;

    long long output=(1LL<<n)-ways_01-ways_12-ways_20+ways_0+ways_1+ways_2;

    //cout<<ways_0<<" "<<ways_1<<" "<<ways_2<<" "<<ways_01<<" "<<ways_12<<" "<<ways_20<<endl;

    printf("%lld\n",output);
    return 0;
}