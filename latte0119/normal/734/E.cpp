#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
typedef vector<int>vint;
typedef pair<int,int>pint;

struct UF{
    vint par;
    void init(int n){
        par.resize(n);
        rep(i,n)par[i]=i;
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    void unite(int a,int b){
        par[find(b)]=find(a);
    }
};

int N;
int A[222222],B[222222];
int C[222222];

int idx[222222];

vint G[222222];
int dist[222222];
void dfs(int v,int p,int d){
    dist[v]=d;
    for(auto u:G[v]){
        if(u!=p)dfs(u,v,d+1);
    }
}

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&C[i]);
    UF uf;uf.init(N);
    rep(i,N-1){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        if(C[a]==C[b])uf.unite(a,b);
        A[i]=a;B[i]=b;
    }

    int K=0;
    rep(i,N)if(uf.find(i)==i)idx[i]=K++;
    rep(i,N-1){
        if(C[A[i]]==C[B[i]])continue;
        int x=idx[uf.find(A[i])];
        int y=idx[uf.find(B[i])];
        G[x].pb(y);G[y].pb(x);
    }

    dfs(0,-1,0);
    int v=0;
    rep(i,K)if(dist[v]<dist[i])v=i;
    dfs(v,-1,0);
    cout<<(*max_element(dist,dist+K)+1)/2<<endl;
    return 0;
}