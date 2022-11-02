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
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

const int SIZE=333333;

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

namespace foo{
    vector<vint>TT;
    vector<pint>bk;
    vector<pint>brdg;
    int dep[SIZE];
    bool used[SIZE];
    int sum[SIZE];
    UF uf;
    void dfs(int v,int p,int d,vector<vint>&G){
        used[v]=true;
        dep[v]=d;

        for(int to:G[v]){
            if(to==p)continue;
            if(used[to]){
                if(dep[to]>dep[v])bk.pb(pint(v,to));
            }
            else{
                TT[v].pb(to);TT[to].pb(v);
                dfs(to,v,d+1,G);
            }
        }
    }
    void dfs2(int v,int p){
        for(int to:TT[v]){
            if(to==p)continue;
            dfs2(to,v);
            if(!sum[to])brdg.pb(pint(v,to));
            else{
                uf.unite(v,to);
                sum[v]+=sum[to];
            }
        }
    }

    void hogepiyo(vector<vint>&G,vector<vint>&T,vint &comp){
        TT.resize(G.size());
        uf.init(G.size());
        dfs(0,-1,0,G);
        for(auto p:bk){
            if(dep[p.fi]>dep[p.se])swap(p.fi,p.se);
            sum[p.fi]--;sum[p.se]++;
        }
        dfs2(0,-1);
        vint v;
        rep(i,G.size())if(uf.find(i)==i)v.pb(i);
        T.resize(v.size());
        for(auto p:brdg){
            p.fi=lower_bound(all(v),uf.find(p.fi))-v.begin();
            p.se=lower_bound(all(v),uf.find(p.se))-v.begin();
            T[p.fi].pb(p.se);
            T[p.se].pb(p.fi);
        }
        comp.resize(G.size());
        rep(i,G.size()){
            int t=uf.find(i);
            t=lower_bound(all(v),t)-v.begin();
            comp[i]=t;
        }
    }
}

int N,M;
int A[SIZE],B[SIZE],C[SIZE];
vector<vint>T;
vint comp;
int par[20][SIZE],dep[SIZE];
void dfs(int v,int p,int d,vector<vint>&T){
    par[0][v]=p;
    dep[v]=d;
    for(int to:T[v]){
        if(to==p)continue;
        dfs(to,v,d+1,T);
    }
}


int sum[SIZE];
int po[SIZE];
void dfs2(int v,int p){
    for(int to:T[v]){
        if(to==p)continue;
        sum[to]+=sum[v];
        dfs2(to,v);
    }
}


void init(vector<vint>&G){
    foo::hogepiyo(G,T,comp);
    dfs(0,-1,0,T);
    rep(i,19){
        rep(j,T.size()){
            if(par[i][j]==-1)par[i+1][j]=-1;
            else par[i+1][j]=par[i][par[i][j]];
        }
    }
    rep(i,M){
        if(C[i]==0)continue;
        int a=comp[A[i]],b=comp[B[i]];
        if(a==b){
            po[a]++;
        }
        else{
            if(dep[a]<dep[b])swap(a,b);
        }
        sum[a]++;
    }
    dfs2(0,-1);
}

int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    rep(i,20)if((dep[u]-dep[v])>>i&1)u=par[i][u];
    for(int i=19;i>=0;i--)if(par[i][u]!=par[i][v])u=par[i][u],v=par[i][v];
    return u==v?u:par[0][u];
}

int get(int u,int v){
    int p=lca(u,v);
    return sum[u]+sum[v]-2*sum[p]+po[p];
}

signed main(){
    scanf("%lld%lld",&N,&M);
    vector<vint>G(N);
    rep(i,M){
        scanf("%lld%lld%lld",&A[i],&B[i],&C[i]);
        A[i]--;B[i]--;
        G[A[i]].pb(B[i]);
        G[B[i]].pb(A[i]);
    }

    init(G);


    int a,b;
    scanf("%lld%lld",&a,&b);
    a--;b--;a=comp[a];b=comp[b];
    if(get(a,b))puts("YES");
    else puts("NO");
    return 0;
}