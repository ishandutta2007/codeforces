#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

struct UF{
    vector<int>par,sz;
    void init(int n){
        par.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            sz[i]=1;
        }
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return;
        sz[x]+=sz[y];
        par[y]=x;
    }
    bool same(int x,int y){
        return find(x)==find(y);
    }
    int size(int x){
        return sz[find(x)];
    }
};

int N,M,S;
int W[222222],C[222222];
int A[222222],B[222222];

vpint G[222222];
bool used[222222];

const int INF=1001001001001001001ll;
int par[20][222222],dep[222222];
pint ma[20][222222];
void dfs(int v,int p,int d,pint c){
    par[0][v]=p;
    ma[0][v]=c;
    dep[v]=d;
    for(auto &e:G[v]){
        if(e.fi==p)continue;
        dfs(e.fi,v,d+1,pint(W[e.se],e.se));
    }
}

pint func(int u,int v){
    pint ret(-INF,-INF);
    if(dep[u]<dep[v])swap(u,v);
    rep(i,20)if((dep[u]-dep[v])>>i&1){
        chmax(ret,ma[i][u]);
        u=par[i][u];
    }
    if(u==v)return ret;
    for(int i=19;i>=0;i--){
        if(par[i][u]==par[i][v])continue;
        chmax(ret,ma[i][u]);
        chmax(ret,ma[i][v]);
        u=par[i][u];
        v=par[i][v];
    }
    chmax(ret,ma[0][u]);
    chmax(ret,ma[0][v]);
    return ret;
}

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,M)scanf("%lld",&W[i]);
    rep(i,M)scanf("%lld",&C[i]);
    rep(i,M)scanf("%lld%lld",&A[i],&B[i]),A[i]--,B[i]--;
    scanf("%lld",&S);

    vpint es;
    rep(i,M)es.pb({W[i],i});
    sort(all(es));
    UF uf;uf.init(N);
    int sum=0;
    rep(i,M){
        int a=A[es[i].se];
        int b=B[es[i].se];
        if(uf.same(a,b))continue;
        used[es[i].se]=true;
        sum+=es[i].fi;
        uf.unite(a,b);
        G[a].pb({b,es[i].se});
        G[b].pb({a,es[i].se});
    }



    dfs(0,-1,0,pint(-INF,-INF));
    for(int i=0;i<19;i++){
        for(int j=0;j<N;j++){
            if(par[i][j]==-1){
                par[i+1][j]=-1;
                ma[i+1][j]=ma[i][j];
            }
            else{
                par[i+1][j]=par[i][par[i][j]];
                ma[i+1][j]=max(ma[i][j],ma[i][par[i][j]]);
            }
        }
    }


    int mi=INF;
    pint ans(-1,-1);
    rep(i,M){
        int val;
        pint p;
        if(used[i]){
            val=sum-S/C[i];
            p={i,i};
        }
        else{
            pint f=func(A[i],B[i]);
            val=sum-f.fi+W[i]-S/C[i];
            p={i,f.se};
        }
        if(mi>val){
            mi=val;
            ans=p;
        }
    }

    used[ans.se]=false;
    used[ans.fi]=true;
    W[ans.fi]-=S/C[ans.fi];
    printf("%lld\n",mi);
    rep(i,M){
        if(!used[i])continue;
        printf("%lld %lld\n",i+1,W[i]);
    }

    return 0;
}