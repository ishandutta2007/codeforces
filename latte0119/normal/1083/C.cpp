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

struct FastLCA{
    template<class T>
    struct SparseTable{
        vector<vector<T>>st;
        void init(const vector<T>&vec){
            int32_t b;
            for(b=0;(1<<b)<=vec.size();b++);
            st.assign(b,vector<T>(1<<b));
            for(int32_t i=0;i<vec.size();i++)st[0][i]=vec[i];

            for(int32_t i=1;i<b;i++){
                for(int32_t j=0;j+(1<<i)<=(1<<b);j++){
                    st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
                }
            }
        }
        T getMin(int32_t l,int32_t r){
            assert(l<r);
            int32_t b=32-__builtin_clz(r-l)-1;
            return min(st[b][l],st[b][r-(1<<b)]);
        }
    };
    SparseTable<pair<int32_t,int32_t>>st;

    vector<vector<int32_t>>G;
    int32_t V;
    int32_t root;
    vector<int32_t>ord;
    FastLCA(int32_t v=0,int32_t r=0):V(v),root(r),G(v),ord(v){}

    void set(int32_t v){
        *this=FastLCA(v);
    }

    void addEdge(int32_t a,int32_t b){
        G[a].push_back(b);
        G[b].push_back(a);
    }

    void dfs(int32_t v,int32_t p,int32_t d,vector<pair<int32_t,int32_t>>&vs){
        ord[v]=vs.size();
        vs.emplace_back(d,v);

        for(auto u:G[v]){
            if(u==p)continue;
            dfs(u,v,d+1,vs);
            vs.emplace_back(d,v);
        }
    }

    void init(){
        vector<pair<int32_t,int32_t>>vs;
        dfs(root,-1,0,vs);
        st.init(vs);
    }

    inline int32_t operator()(int32_t a,int32_t b){
        if(ord[a]>ord[b])swap(a,b);
        return st.getMin(ord[a],ord[b]+1).second;
    }
};
FastLCA lca;

template<class W>
struct WeightedTree{
    struct Edge{
        int to;
        W cost;
        Edge(int to,W cost):to(to),cost(cost){}
    };

    int V;
    int root;
    int E;
    vector<vector<Edge>>G;

    vector<int>par_,dep_,sz_,head_;
    vector<int>tin_,tout_,vs_;
    vector<W>dist_;
    WeightedTree(int V=0,int root=0):V(V),root(root),G(V),par_(V),sz_(V),dep_(V),head_(V),dist_(V),tin_(V),tout_(V),vs_(V),E(0){}
    void set(int v){
        *this=WeightedTree(v);
    }

    void addEdge(int a,int b,W c=W(1)){
        assert(a<V&&b<V);
        assert(E+1<V);
        G[a].push_back(Edge(b,c));
        G[b].push_back(Edge(a,c));
        E++;
    }

    void dfs(int v,int p,int d,W c){
        par_[v]=p;
        dep_[v]=d;
        sz_[v]=1;
        dist_[v]=c;

        for(auto &e:G[v]){
            if(e.to==p)continue;
            dfs(e.to,v,d+1,c+e.cost);
            sz_[v]+=sz_[e.to];
            if(G[v][0].to==p||sz_[e.to]>sz_[G[v][0].to])swap(G[v][0],e);
        }
    }

    void dfs_hld(int v,int &tt){
        vs_[tt]=v;
        tin_[v]=tt++;
        for(auto &e:G[v]){
            if(e.to==par_[v])continue;
            head_[e.to]=(e.to==G[v][0].to)?head_[v]:e.to;
            dfs_hld(e.to,tt);
        }
        tout_[v]=tt;
    }
    void init(){
        dfs(root,-1,0,W(0));
        int tt=0;
        dfs_hld(root,tt);
    }

    inline int lca(int u,int v)const{
        while(head_[u]!=head_[v]){
            if(dep_[head_[u]]<dep_[head_[v]])swap(u,v);
            u=par_[head_[u]];
        }
        return dep_[u]<dep_[v]?u:v;
    }

    
    inline int ancestor(int v,int k){
        while(v!=-1){
            if(dep_[v]-dep_[head_[v]]<k){
                k-=dep_[v]-dep_[head_[v]]+1;
                v=par_[head_[v]];
                continue;
            }
            return vs_[tin_[v]-k];
        }
        return -1;
    }
    

    inline int par(int v)const{
        return par_[v];
    }

    inline int size(int v)const{
        return sz_[v];
    }
    inline int len(int a,int b=0)const{
        int l=lca(a,b);
        return dep_[a]+dep_[b]-2*dep_[l];
    }
    inline W dist(int a,int b)const{
        int l=lca(a,b);
        return dist_[a]+dist_[b]-2*dist_[l];
    }

    inline W dist(int a)const{
        return dist_[a];
    }

    inline int dep(int v)const{
        return dep_[v];
    }
    inline int tin(int v)const{
        return tin_[v];
    }
    inline int tout(int v)const{
        return tout_[v];
    }

    inline int vs(int k)const{
        return vs_[k];
    }
    inline int heavy(int v)const{
        if(G[v].size()==0||G[v][0].to==par_[v])return -1;
        return G[v][0].to;
    }

    vector<Edge>& operator[](int i){
        return G[i];
    }
};


template<class T,class F>
struct SegmentTree{
    const F f;
    const T ti;
    vector<T>dat;
    int32_t sz;
    SegmentTree(const T &ti,const F &f):ti(ti),f(f){}
    void build(const vector<T>&v){
        assert(v.size());
        sz=1;
        while(sz<v.size())sz<<=1;
        dat.resize(sz<<1,ti);
        for(int32_t i=0;i<v.size();i++)dat[sz-1+i]=v[i];
        for(int32_t i=sz-2;i>=0;i--)dat[i]=f(dat[i*2+1],dat[i*2+2]);
    }

    inline void update(int32_t k,const T &x){
        k+=sz-1;
        dat[k]=x;
        while(k){
            k=(k-1)>>1;
            dat[k]=f(dat[k*2+1],dat[k*2+2]);
        }
    }

    inline void add(int32_t k,const T &x){
        k+=sz-1;
        dat[k]=f(dat[k],x);
        while(k){
            k=(k-1)>>1;
            dat[k]=f(dat[k*2+1],dat[k*2+2]);
        }
    }

    inline T query(int32_t a,int32_t b){
        return query(a,b,0,0,sz);
    }
    T query(int32_t a,int32_t b,int32_t k,int32_t l,int32_t r){
        if(r<=a||b<=l)return ti;
        if(a<=l&&r<=b)return dat[k];
        return f(query(a,b,k*2+1,l,(l+r)>>1),query(a,b,k*2+2,(l+r)>>1,r));
    }


    int solve(T cur,const T &ng,int k,int l,int r){
        if(l+1==r){
            if(f(cur,dat[k])==ng)return 0;
            return 1;
        }


        int m=(l+r)>>1;
        const auto &nex=f(cur,dat[k*2+1]);
        if(nex==ng){
            return solve(cur,ng,k*2+1,l,m);
        }
        else{
            return (m-l)+solve(nex,ng,k*2+2,m,r);
        }
    }
    int solve(T ng){
        return solve(ti,ng,0,0,sz);
    }
};

WeightedTree<int>wt;


pint ti{-1,-1};
pint ng{-2,-2};

inline int dist(int a,int b){
    const int l=lca(a,b);
    return wt.dep(a)+wt.dep(b)-2*wt.dep(l);
}
inline bool ok(int a,int b,int c,int d){
    return dist(a,c)+dist(c,b)==dist(a,b)&&dist(a,d)+dist(d,b)==dist(a,b);
}
auto ff=[&](pint x,pint y)->pint{
    if(x==ti)return y;
    if(y==ti)return x;

    if(x==ng)return ng;
    if(y==ng)return ng;

    vector<int>vs{x.fi,x.se,y.fi,y.se};
    if(ok(vs[0],vs[1],vs[2],vs[3]))return {vs[0],vs[1]};
    if(ok(vs[0],vs[2],vs[1],vs[3]))return {vs[0],vs[2]};
    if(ok(vs[0],vs[3],vs[1],vs[2]))return {vs[0],vs[3]};
    if(ok(vs[1],vs[2],vs[0],vs[3]))return {vs[1],vs[2]};
    if(ok(vs[1],vs[3],vs[0],vs[2]))return {vs[1],vs[3]};
    if(ok(vs[2],vs[3],vs[0],vs[1]))return {vs[2],vs[3]};
    return ng;
};


SegmentTree<pint,decltype(ff)>seg(ti,ff);

int P[222222];


signed main(){
    int N;scanf("%lld",&N);
    wt.set(N);lca.set(N);

    
    rep(i,N)scanf("%lld",&P[i]);
    
    for(int i=1;i<N;i++){
        int p;scanf("%lld",&p);
        p--;
        wt.addEdge(p,i);
        lca.addEdge(p,i);
    }
    wt.init();lca.init();

    vector<pint>ini(N);
    rep(i,N)ini[P[i]]={i,i};
    seg.build(ini);

    int Q;scanf("%lld",&Q);
    while(Q--){
        int t;scanf("%lld",&t);
        if(t==1){
            int a,b;
            scanf("%lld%lld",&a,&b);
            a--;b--;
            swap(P[a],P[b]);
            seg.update(P[a],{a,a});
            seg.update(P[b],{b,b});
        }
        else{
            int tmp=seg.solve(ng);
            chmin(tmp,N);
            printf("%lld\n",tmp);
        }
    }
    return 0;
}