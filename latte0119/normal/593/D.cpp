#include<bits/stdc++.h>
using namespace std;

#define int long long


typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

struct UF{
    int N;
    vint par;
    void init(int n){
        N=n;
        par.resize(N);
        rep(i,N)par[i]=i;
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return;
        par[y]=x;
    }
};

struct edge{
    int to,cost;
    edge(int to,int cost):to(to),cost(cost){}
};

const int MN=200000;

int N,Q;
int A[MN],B[MN],C[MN];
vector<edge>G[MN];

int par[20][MN],cost[MN],depth[MN];

int lca(int u,int v){
    if(depth[u]<depth[v])swap(u,v);
    rep(i,20)if((depth[u]-depth[v])>>i&1)u=par[i][u];
    for(int i=19;i>=0;i--)if(par[i][u]!=par[i][v]){
        u=par[i][u];
        v=par[i][v];
    }
    return u==v?u:par[0][u];
}

signed main(){
    scanf("%lld%lld",&N,&Q);
    rep(i,N-1){
        scanf("%lld%lld%lld",&A[i],&B[i],&C[i]);
        A[i]--;B[i]--;
        G[A[i]].pb(edge(B[i],C[i]));
        G[B[i]].pb(edge(A[i],C[i]));
    }

    queue<int>que;
    que.push(0);
    par[0][0]=-1;
    while(que.size()){
        int v=que.front();que.pop();
        rep(i,G[v].size()){
            edge &e=G[v][i];
            if(e.to==par[0][v])continue;
            par[0][e.to]=v;
            cost[e.to]=e.cost;
            depth[e.to]=depth[v]+1;
            que.push(e.to);
        }
    }


    UF uf;
    uf.init(N);
    rep(i,N){
        if(par[0][i]<0)continue;
        if(cost[i]==1)uf.unite(par[0][i],i);
    }

    rep(i,19){
        rep(j,N){
            if(par[i][j]==-1)par[i+1][j]=-1;
            else par[i+1][j]=par[i][par[i][j]];
        }
    }

    rep(i,N-1){
        if(depth[A[i]]<depth[B[i]])swap(A[i],B[i]);
    }


    while(Q--){
        int type;
        scanf("%lld",&type);
        if(type==1){
            int u,v,x;
            scanf("%lld%lld%lld",&u,&v,&x);
            u--;v--;
            int p=lca(u,v);
            for(int i=0;i<60;i++){
                int to=uf.find(u);
                if(depth[to]<=depth[p])break;
                u=to;
                x/=cost[u];
                u=par[0][u];
            }
            for(int i=0;i<60;i++){
                int to=uf.find(v);
                if(depth[to]<=depth[p])break;
                v=to;
                x/=cost[v];
                v=par[0][v];
            }
            printf("%lld\n",x);
        }
        else{
            int k,x;
            scanf("%lld%lld",&k,&x);
            k--;
            C[k]=x;
            cost[A[k]]=x;
            if(x==1){
                uf.unite(B[k],A[k]);
            }
        }
    }
    return 0;
}