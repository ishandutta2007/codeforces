#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

struct UnionFindTree{
    vector<int>par,sz;
    UnionFindTree(int n){
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
        if(sz[x]<sz[y])swap(x,y);
        sz[x]+=sz[y];
        par[y]=x;
    }
    bool areSame(int x,int y){
        return find(x)==find(y);
    }
    int size(int x){
        return sz[find(x)];
    }
};

int N;
int A[1111111];
vint G[1111111];

bool ex[1111111];

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);
    rep(i,N-1){
        int a,b;scanf("%lld%lld",&a,&b);a--;b--;
        G[a].pb(b);G[b].pb(a);
    }

    vpint ord;
    rep(i,N)ord.pb({A[i],i});sort(all(ord));


    UnionFindTree uf(N);
    int ans=0;
    rep(i,ord.size()){
        int v=ord[i].se;
        int tmp=0,sz=1;
        for(auto u:G[v]){
            if(!ex[u])continue;
            tmp+=uf.size(u)*uf.size(u);
            sz+=uf.size(u);
            uf.unite(v,u);
        }
        ans+=ord[i].fi*(sz*sz-tmp);
        ex[v]=true;
    }

    memset(ex,0,sizeof(ex));
    uf=UnionFindTree(N);
    for(int i=N-1;i>=0;i--){
        int v=ord[i].se;
        int tmp=0,sz=1;
        for(auto u:G[v]){
            if(!ex[u])continue;
            tmp+=uf.size(u)*uf.size(u);
            sz+=uf.size(u);
            uf.unite(v,u);
        }
        ans-=ord[i].fi*(sz*sz-tmp);
        ex[v]=true;
    }
    cout<<ans/2<<endl;
    return 0;
}