#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
    ost<<"{"<<p.first<<","<<p.second<<"}";
    return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
    ost<<"{";
    for(int i=0;i<v.size();i++){
        if(i)ost<<",";
        ost<<v[i];
    }
    ost<<"}";
    return ost;
}

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


void solve(){
    int N,M,A,B;
    scanf("%lld%lld%lld%lld",&N,&M,&A,&B);
    A--;B--;
    vector<vint>G(N);

    vint x(M),y(M);
    rep(i,M)scanf("%lld%lld",&x[i],&y[i]),x[i]--,y[i]--;

    UnionFindTree uf(N);
    rep(i,M){
        if(x[i]==A||y[i]==A||x[i]==B||y[i]==B)continue;
        uf.unite(x[i],y[i]);
    }

    rep(i,M){
        G[x[i]].pb(y[i]);
        G[y[i]].pb(x[i]);
    }

    vint flagA(N),flagB(N);
    rep(t,2){
        for(auto u:G[A]){
            flagA[uf.find(u)]=true;
        }
        swap(flagA,flagB);
        swap(A,B);
    }

    int sumA=0,sumB=0;
    rep(i,N){
        if(i==A||i==B)continue;
        if(flagA[i]&&flagB[i])continue;
        if(flagA[i])sumA+=uf.size(i);
        else if(flagB[i])sumB+=uf.size(i);
    }

    printf("%lld\n",sumA*sumB);
}

signed main(){
    int t;scanf("%lld",&t);
    while(t--)solve();
    return 0;
}