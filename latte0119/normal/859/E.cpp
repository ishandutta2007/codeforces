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

const int mod=1000000007;

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
vint G[222222];

bool isroot[222222];

int dfs(int v){
    int ret=1;
    for(auto u:G[v]){
        ret=(ret+dfs(u))%mod;
    }
    return ret;
}

signed main(){
    scanf("%lld",&N);
    fill_n(isroot,222222,true);
    UnionFindTree uf(2*N);

    int L=0;
    rep(i,N){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[b].pb(a);
        isroot[a]=false;
        uf.unite(a,b);
        if(a==b)L--;
    }
    rep(i,2*N)if(uf.find(i)==i)L++;
    rep(i,2*N)if(isroot[i])L--;

    int ans=1;
    rep(i,L)ans=ans*2%mod;

    rep(i,2*N)if(isroot[i]){
        ans=ans*dfs(i)%mod;
    }

    cout<<ans<<endl;
    return 0;
}