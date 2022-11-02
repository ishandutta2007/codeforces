#include<bits/stdc++.h>
using namespace std;

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
WeightedTree<int>wt;

template<uint32_t mod>
struct ModInt{
    uint32_t a;
    ModInt& s(uint32_t vv){
        a=vv<mod?vv:vv-mod;
        return *this;
    }

    ModInt(int64_t x=0){s(x%mod+mod);}

    ModInt& operator+=(const ModInt &x){return s(a+x.a);}
    ModInt& operator-=(const ModInt &x){return s(a+mod-x.a);}
    ModInt& operator*=(const ModInt &x){
        a=uint64_t(a)*x.a%mod;
        return *this;
    }
    ModInt& operator/=(const ModInt &x){
        *this*=x.inv();
        return *this;
    }

    ModInt operator+(const ModInt &x)const{return ModInt(*this)+=x;}
    ModInt operator-(const ModInt &x)const{return ModInt(*this)-=x;}
    ModInt operator*(const ModInt &x)const{return ModInt(*this)*=x;}
    ModInt operator/(const ModInt &x)const{return ModInt(*this)/=x;}
    bool operator==(const ModInt &x)const{return a==x.a;}
    bool operator!=(const ModInt &x)const{return a!=x.a;}
    bool operator<(const ModInt &x)const{return a<x.a;}

    ModInt operator-()const{return ModInt()-*this;}
    ModInt pow(int64_t n)const{
        ModInt res(1),x(*this);
        while(n){
            if(n&1)res*=x;
            x*=x;
            n>>=1;
        }
        return res;
    }

    ModInt inv()const{return pow(mod-2);}
};

template<uint32_t mod>
istream& operator>>(istream& in,const ModInt<mod>& a){
    return (in>>a.a);
}
template<uint32_t mod>
ostream& operator<<(ostream& out,const ModInt<mod>& a){
    return (out<<a.a);
}
using mint=ModInt<1000000007>;

// template<class T,class E,class F,class G,class H>
// struct LazySegmentTree{
//     F f;
//     G g;
//     H h;

//     T ti;
//     E ei;

//     vector<T>dat;
//     vector<E>put;
//     int sz;
//     LazySegmentTree(const T &ti,const E &ei,const F &f,const G &g,const H &h):ti(ti),ei(ei),f(f),g(g),h(h){}

//     void build(const vector<T>&v){
//         assert(v.size());
//         sz=1;
//         while(sz<v.size())sz<<=1;
//         dat.resize(sz<<1,ti);
//         put.resize(sz<<1,ei);
//         for(int i=0;i<v.size();i++)dat[sz-1+i]=v[i];
//         for(int i=sz-2;i>=0;i--)dat[i]=f(dat[i*2+1],dat[i*2+2]);
//     }
//     inline void push(int k,int l,int r){
//         dat[k]=g(dat[k],put[k],r-l);
//         if(k<sz-1){
//             put[k*2+1]=h(put[k*2+1],put[k]);
//             put[k*2+2]=h(put[k*2+2],put[k]);
//         }
//         put[k]=ei;
//     }

//     void modify(int a,int b,E x,int k,int l,int r){
//         push(k,l,r);
//         if(r<=a||b<=l)return;
//         if(a<=l&&r<=b){
//             put[k]=x;
//             push(k,l,r);
//             return;
//         }
//         modify(a,b,x,k*2+1,l,(l+r)/2);
//         modify(a,b,x,k*2+2,(l+r)/2,r);
//         dat[k]=f(dat[k*2+1],dat[k*2+2]);
//     }

//     inline void modify(int a,int b,E x){
//         return modify(a,b,x,0,0,sz);
//     }
//     T query(int a,int b,int k,int l,int r){
//         push(k,l,r);
//         if(r<=a||b<=l)return ti;
//         if(a<=l&&r<=b)return dat[k];
//         return f(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
//     }
//     inline T query(int a,int b){
//         return query(a,b,0,0,sz);
//     }
// };

// auto ff=[](mint a,mint b){return a+b;};
// auto gg=[](mint a,mint b,int l){return a+b*l;};
// auto hh=[](mint a,mint b){return a+b;};


// LazySegmentTree<mint,mint,decltype(ff),decltype(gg),decltype(hh)>
// segdep(0,0,ff,gg,hh),segnum(0,0,ff,gg,hh);
// struct SegInit{
//     SegInit(){
//         segdep.build(vector<mint>(111111,0));
//         segnum.build(vector<mint>(111111,0));
//     }
// }SegInitDummy;

struct segtree{
    static const int SEG=1<<17;
    vector<mint>dat,put;
    segtree():dat(SEG*2),put(SEG*2){}
    void modify(int a,int b,mint x,int k=0,int l=0,int r=SEG){
        if(r<=a||b<=l)return;
        if(a<=l&&r<=b){
            put[k]+=x;
            dat[k]+=x*(r-l);
            return;
        }
        modify(a,b,x,k*2+1,l,(l+r)/2);
        modify(a,b,x,k*2+2,(l+r)/2,r);
        dat[k]=dat[k*2+1]+dat[k*2+2]+put[k]*(r-l);
    }

    mint query(int a,int b,int k=0,int l=0,int r=SEG){
        if(r<=a||b<=l)return 0;
        if(a<=l&&r<=b)return dat[k];
        return query(a,b,k*2+1,l,(l+r)/2)+query(a,b,k*2+2,(l+r)/2,r)+put[k]*(min(b,r)-max(a,l));
    }
};

segtree segdep,segnum;

int N;
int L[111111],R[111111];

mint inv[111111];
mint ov;
mint ans;
namespace DSUOnTree{
    void check(int v,int b){
        mint s=segdep.query(L[v],R[v]);
        mint n=segnum.query(L[v],R[v]);
        ans+=(s+n*(wt.dep(v)-2*wt.dep(b)))*inv[v];
    }
    void add(int v){
        segdep.modify(L[v],R[v],inv[v]*wt.dep(v));
        segnum.modify(L[v],R[v],inv[v]);
    }
    void dfs(int v,int p,bool keep){
        int hv=wt.heavy(v);
        for(auto &e:wt[v]){
            if(e.to!=p&&e.to!=hv)dfs(e.to,v,false);
        }

        if(hv!=-1)dfs(hv,v,true);
        check(v,v);add(v);
        for(auto &e:wt[v])if(e.to!=p&&e.to!=hv){
            for(int i=wt.tin(e.to);i<wt.tout(e.to);i++)check(wt.vs(i),v);
            for(int i=wt.tin(e.to);i<wt.tout(e.to);i++)add(wt.vs(i));
        }

        //calc
    
        if(!keep){
        //delete
            for(int i=wt.tin(v);i<wt.tout(v);i++){
                int u=wt.vs(i);
                segdep.modify(L[u],R[u],-inv[u]*wt.dep(u));
                segnum.modify(L[u],R[u],-inv[u]);
            }
        }
    }
    void solve(){
        dfs(0,-1,false);
    }
}



signed main(){
    scanf("%d",&N);
    wt.set(N);
    rep(i,N){
        scanf("%d%d",&L[i],&R[i]);
        L[i]--;
    }
    rep(i,N-1){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;b--;
        wt.addEdge(a,b);
    }
    wt.init();

    rep(i,N)inv[i]=mint(R[i]-L[i]).inv();


    DSUOnTree::solve();
    rep(i,N)ans*=R[i]-L[i];
    cout<<ans<<endl;
    return 0;
}