#include<bits/stdc++.h>
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

namespace SCC{
    void visit(const vector<vector<int>>&G,vector<int>&vs,vector<int>&used,int v){
        used[v]=true;
        for(auto u:G[v]){
            if(!used[u])visit(G,vs,used,u);
        }
        vs.push_back(v);
    }

    void visit2(const vector<vector<int>>&T,vector<int>&used,vector<int>&comp,vector<int>&vec,int k,int v){
        comp[v]=k;
        used[v]=true;
        vec.push_back(v);

        for(auto u:T[v]){
            if(!used[u])visit2(T,used,comp,vec,k,u);
        }
    }

    //G:AOt
    //H:A1_kOt
    //comp:Ge_AH_
    void decompose(const vector<vector<int>>&G,vector<vector<int>>&H,vector<int>&comp){
        vector<vector<int>>T(G.size());
        for(int i=0;i<G.size();i++){
            for(auto v:G[i]){
                T[v].push_back(i);
            }
        }
        comp.resize(G.size());

        vector<int>vs(G.size());
        vector<int>used(G.size());
        for(int i=0;i<G.size();i++){
            if(!used[i])visit(G,vs,used,i);
        }
        reverse(vs.begin(),vs.end());
        fill(used.begin(),used.end(),0);

        int K=0;
        vector<vector<int>>S;
        for(auto v:vs){
            if(!used[v]){
                S.push_back(vector<int>());
                visit2(T,used,comp,S.back(),K++,v);
            }
        }

        H.resize(K);
        fill(used.begin(),used.end(),0);
        for(int i=0;i<K;i++){
            for(auto v:S[i]){
                for(auto u:G[v]){
                    if(used[comp[u]]||comp[v]==comp[u])continue;
                    used[comp[u]]=true;
                    H[comp[v]].push_back(comp[u]);
                }
            }
            for(auto v:H[i])used[v]=false;
        }

    }
}

struct UnionFindTree{
    vector<int32_t>par,sz;
    vector<int>cy;
    UnionFindTree(int32_t n=0):par(n),sz(n),cy(n){
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
        cy[x]|=cy[y];
        par[y]=x;
    }
    bool same(int32_t x,int32_t y){
        return find(x)==find(y);
    }
    int32_t size(int32_t x){
        return sz[find(x)];
    }
};

signed main(){
    int N,M;
    cin>>N>>M;
    vector<vint>G(N);
    rep(i,M){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a].eb(b);
    }
    vector<vint>H;
    vint comp;

    SCC::decompose(G,H,comp);
    vint cnt(H.size());
    rep(i,N)cnt[comp[i]]++;

    UnionFindTree uf(H.size());
    rep(i,N)for(auto j:G[i])uf.unite(comp[i],comp[j]);
    rep(i,H.size())if(cnt[i]>1)uf.cy[uf.find(i)]=1;

    int ans=N;
    rep(i,H.size())if(uf.find(i)==i&&uf.cy[i]==0)ans--;
    cout<<ans<<endl;
    return 0;
}