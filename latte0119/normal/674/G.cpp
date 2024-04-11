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

vpint op(vpint x,vpint y){
    rep(i,y.size()){
        bool ex=false;
        rep(j,x.size()){
            if(x[j].se==y[i].se){
                x[j].fi+=y[i].fi;
                ex=true;
            }
        }
        if(ex)continue;
        if(x.size()<5){
            x.pb(y[i]);
            continue;
        }

        int k=min_element(all(x))-x.begin();
        int m=x[k].fi;
        rep(j,x.size())x[j].fi-=m;
        y[i].fi-=m;
        if(x[k].fi==0)x[k]=y[i];
    }
    return x;
}

template<class T,class E,class F,class G,class H>
struct LazySegmentTree{
    F f;
    G g;
    H h;

    T ti;
    E ei;

    vector<T>dat;
    vector<E>put;
    int sz;
    LazySegmentTree(const T &ti,const E &ei,const F &f,const G &g,const H &h):ti(ti),ei(ei),f(f),g(g),h(h){}

    void build(const vector<T>&v){
        assert(v.size());
        sz=1;
        while(sz<v.size())sz<<=1;
        dat.resize(sz<<1,ti);
        put.resize(sz<<1,ei);
        for(int i=0;i<v.size();i++)dat[sz-1+i]=v[i];
        for(int i=sz-2;i>=0;i--)dat[i]=f(dat[i*2+1],dat[i*2+2]);
    }
    inline void push(int k,int l,int r){
        dat[k]=g(dat[k],put[k],r-l);
        if(k<sz-1){
            put[k*2+1]=h(put[k*2+1],put[k]);
            put[k*2+2]=h(put[k*2+2],put[k]);
        }
        put[k]=ei;
    }

    void modify(int a,int b,E x,int k,int l,int r){
        push(k,l,r);
        if(r<=a||b<=l)return;
        if(a<=l&&r<=b){
            put[k]=x;
            push(k,l,r);
            return;
        }
        modify(a,b,x,k*2+1,l,(l+r)/2);
        modify(a,b,x,k*2+2,(l+r)/2,r);
        dat[k]=f(dat[k*2+1],dat[k*2+2]);
    }

    inline void modify(int a,int b,E x){
        return modify(a,b,x,0,0,sz);
    }
    T query(int a,int b,int k,int l,int r){
        push(k,l,r);
        if(r<=a||b<=l)return ti;
        if(a<=l&&r<=b)return dat[k];
        return f(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
    }
    inline T query(int a,int b){
        return query(a,b,0,0,sz);
    }
};

auto ff=[](const vpint &a,const vpint &b){return op(a,b);};
auto gg=[](const vpint &a,int x,int l){
    if(x==-1)return a;
    return vpint{{l,x}};
};
auto hh=[](int x,int y){
    if(y==-1)return x;
    return y;
};
LazySegmentTree<vpint,int,decltype(ff),decltype(gg),decltype(hh)>
seg(vpint(),-1,ff,gg,hh);

signed main(){
    int N,Q,P;
    scanf("%lld%lld%lld",&N,&Q,&P);

    vector<vpint>ini;
    rep(i,N){
        int a;scanf("%lld",&a);
        ini.pb(vpint{{1,a}});
    }

    seg.build(ini);
    int K=100/P;
    rep(i,Q){
        int t,l,r,id;
        scanf("%lld%lld%lld",&t,&l,&r);
        l--;
        if(t==1){
            scanf("%lld",&id);
            seg.modify(l,r,id);
        }
        else{
            auto v=seg.query(l,r);
            sort(all(v));reverse(all(v));
            int num=min(K,(int)v.size());
            printf("%lld",num);
            rep(j,num)printf(" %lld",v[j].se);
            puts("");
        }
    }
    return 0;
}