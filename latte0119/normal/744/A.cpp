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

signed main(){
    int N,M,K;
    scanf("%lld%lld%lld",&N,&M,&K);
    vint C(K);rep(i,K)scanf("%lld",&C[i]),C[i]--;
    UF uf;uf.init(N);
    rep(i,M){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        uf.unite(a,b);
    }

    vint X(K);
    set<int>rs;
    rep(i,K){
        X[i]=uf.size(C[i]);
        rs.insert(uf.find(C[i]));
    }
    int ma=0;
    rep(i,K)if(X[i]>X[ma])ma=i;
    rep(i,N){
        if(uf.find(i)!=i)continue;
        if(rs.find(i)!=rs.end())continue;
        X[ma]+=uf.size(i);
    }

    int ans=0;
    rep(i,K)ans+=X[i]*(X[i]-1)/2;
    cout<<ans-M<<endl;
    return 0;
}