#include<bits/stdc++.h>
using namespace std;


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

struct Node{
    int mi,ma,dep;
    int lopt,ropt;
    int opt;

    Node(char c){
        if(c=='('){
            mi=0;
            ma=1;
            dep=1;
            lopt=0;
            ropt=1;
            opt=1;
        }
        else{
            mi=-1;
            ma=0;
            dep=-1;
            lopt=2;
            ropt=0;
            opt=1;
        }
    }
    Node(){
        mi=ma=dep=lopt=ropt=opt=0;
    }
};

auto ff=[](Node a,Node b)->Node{
    b.mi+=a.dep;
    b.ma+=a.dep;
    b.dep+=a.dep;
    b.lopt-=a.dep;
    b.ropt-=a.dep;

    Node c;
    c.mi=min(a.mi,b.mi);
    c.ma=max(a.ma,b.ma);
    c.dep=b.dep;
    c.lopt=max(a.lopt,max(b.lopt,a.ma-2*b.mi));
    c.ropt=max(a.ropt,max(b.ropt,b.ma-2*a.mi));

    c.opt=max(a.opt,max(b.opt,max(a.lopt+b.ma,b.ropt+a.ma)));
    return c;
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
};
SegmentTree<Node,decltype(ff)>seg(Node(),ff);
char buf[222222];
signed main(){
    int N,Q;
    scanf("%d%d",&N,&Q);
    string S;
    scanf("%s",buf);S=buf;

    vector<Node>ini;
    for(auto c:S)ini.eb(c);
    seg.build(ini);

    printf("%d\n",seg.query(0,S.size()).opt);
    while(Q--){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;b--;
        swap(S[a],S[b]);
        seg.update(a,Node(S[a]));
        seg.update(b,Node(S[b]));
        printf("%d\n",seg.query(0,S.size()).opt);
    }
    return 0;
}