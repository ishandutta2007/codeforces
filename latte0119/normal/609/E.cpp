#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
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
        par[find(y)]=find(x);
    }
    bool same(int x,int y){
        return find(x)==find(y);
    }
};

struct ee{
    int u,v,c,t;
    ee(int u,int v,int c,int t):u(u),v(v),c(c),t(t){}
    bool operator<(const ee &e)const{
        return c<e.c;
    }
};

struct edge{
    int to,cost;
    edge(int to,int cost):to(to),cost(cost){}
};

const int INF=1001001001001001001ll;
const int SIZE=200000;
int N,M;
int A[SIZE],B[SIZE],C[SIZE];
vector<ee>vec;
vector<edge>G[SIZE];
int par[20][SIZE];
int ma[20][SIZE];
int dep[SIZE];
int ans[SIZE];
void dfs(int v,int p,int d){
    par[0][v]=p;
    dep[v]=d;
    rep(i,G[v].size()){
        edge &e=G[v][i];
        if(e.to==p){
            ma[0][v]=e.cost;
        }
        else{
            dfs(e.to,v,d+1);
        }
    }
}

void init(){
    dfs(0,-1,0);
    rep(i,19){
        rep(j,N){
            if(par[i][j]==-1){
                par[i+1][j]=-1;
            }
            else{
                par[i+1][j]=par[i][par[i][j]];
                ma[i+1][j]=max(ma[i][j],ma[i][par[i][j]]);
            }
        }
    }
}

int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    rep(i,20)if((dep[u]-dep[v])>>i&1)u=par[i][u];
    for(int i=19;i>=0;i--)if(par[i][u]!=par[i][v])u=par[i][u],v=par[i][v];
    return u==v?u:par[0][u];
}

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,M){
        int a,b,c;scanf("%lld%lld%lld",&a,&b,&c);a--;b--;
        vec.pb(ee(a,b,c,i));
        A[i]=a;B[i]=b;C[i]=c;
    }

    sort(all(vec));
    UF uf;uf.init(N);
    int sum=0;
    rep(i,M){
        ee &e=vec[i];
        if(uf.same(e.u,e.v))continue;
        uf.unite(e.u,e.v);
        sum+=e.c;
        G[e.u].pb(edge(e.v,e.c));
        G[e.v].pb(edge(e.u,e.c));
    }
    init();

    uf.init(N);
    rep(i,M){
        ee &e=vec[i];
        if(!uf.same(e.u,e.v)){
            uf.unite(e.u,e.v);
            ans[e.t]=sum;
            continue;
        }
        int p=lca(e.u,e.v);
        int tmp=0;
        int u=e.u,v=e.v;
        rep(j,20)if((dep[u]-dep[p])>>j&1){
            chmax(tmp,ma[j][u]);
            u=par[j][u];
        }
        rep(j,20)if((dep[v]-dep[p])>>j&1){
            chmax(tmp,ma[j][v]);
            v=par[j][v];
        }
        ans[e.t]=sum-tmp+e.c;
    }

    rep(i,M)printf("%lld\n",ans[i]);
    return 0;
}