#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
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

inline int topbit(unsigned long long x){
    return x?63-__builtin_clzll(x):-1;
}

inline int popcount(unsigned long long x){
    return __builtin_popcountll(x);
}

inline int parity(unsigned long long x){
    return __builtin_parity(x);
}

struct UnionFindTree{
    vector<int32_t>par,sz;
    UnionFindTree(int32_t n=0):par(n),sz(n){
        for(int32_t i=0;i<n;i++){
            par[i]=i;
            sz[i]=1;
        }
    }
    int32_t find(int32_t x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    void unite(int32_t x,int32_t y){
        x=find(x);y=find(y);
        if(x==y)return;
        if(sz[x]<sz[y])swap(x,y);
        sz[x]+=sz[y];
        par[y]=x;
    }
    bool same(int32_t x,int32_t y){
        return find(x)==find(y);
    }
    int32_t size(int32_t x){
        return sz[find(x)];
    }
};
int N,M;
int A[111111],B[111111],C[111111];
vpint G[111111];
const int LIM=300;

gp_hash_table<int,int>com[111111];
vector<pint>es[111111];
signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,M){
        scanf("%lld%lld%lld",&A[i],&B[i],&C[i]);
        A[i]--;
        B[i]--;
        C[i]--;
        es[C[i]].eb(A[i],B[i]);
        G[A[i]].eb(B[i],C[i]);
        G[B[i]].eb(A[i],C[i]);
    }

    UnionFindTree uf(N);
    for(int i=0;i<M;i++){
        for(auto &e:es[i]){
            uf.unite(e.fi,e.se);
        }
        vector<int>rs;
        vector<int>ps;
        for(auto &e:es[i]){
            rs.pb(uf.find(e.fi));
            rs.eb(uf.find(e.se));

            ps.pb(e.fi);
            ps.pb(e.se);
        }
        sort(all(rs));
        rs.erase(unique(all(rs)),rs.end());
    

        sort(all(ps));
        ps.erase(unique(all(ps)),ps.end());
        for(auto x:ps){
            int c=lower_bound(all(rs),uf.find(x))-rs.begin();
            com[i][x]=c;
        }
        for(auto x:ps){
            uf.par[x]=x;
            uf.sz[x]=1;
        }
    }
    int Q;scanf("%lld",&Q);

    vector<int>used(M);
    map<pint,int>mem;
    while(Q--){
        int u,v;
        scanf("%lld%lld",&u,&v);
        u--;v--;
        if(G[u].size()>G[v].size())swap(u,v);
        if(G[u].size()==G[v].size()&&u>v)swap(u,v);
        if(mem.find(pint(u,v))!=mem.end()){
            printf("%lld\n",mem[{u,v}]);
            continue;
        }
        int ans=0;
        for(auto &e:G[u]){
            if(used[e.se])continue;
            used[e.se]=true;
            if(com[e.se].find(v)!=com[e.se].end()&&com[e.se][u]==com[e.se][v])ans++;
            // if(uf[e.se].exists(v)&&uf[e.se].find(u)==uf[e.se].find(v))ans++;
        }
        for(auto &e:G[u]){
            used[e.se]=0;
        }
        mem[{u,v}]=ans;
        printf("%lld\n",ans);
        continue;
    }
    return 0;
}