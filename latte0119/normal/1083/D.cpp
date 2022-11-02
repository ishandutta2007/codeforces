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
//using mint=ModInt<998244353>;

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

struct Node{
    int sumR;
    int sumL;
    int sumLR;
    int sumRi;
    int l;
    int r;
};
Node ei{-1,-1,-1,-1,-1,-1};

auto ff=[](Node a,Node b)->Node{
    if(a.l==-1)return b;
    if(b.l==-1)return a;
    return{a.sumR+b.sumR,a.sumL+b.sumL,a.sumLR+b.sumLR,a.sumRi+b.sumRi,a.l,b.r};
};
auto gg=[](Node a,pint p,int len){
    if(a.l==-1)return ei;
    if(p.fi!=-1){
        a.sumLR=a.sumL*p.fi;
        a.sumR=(a.r-a.l)*p.fi;
        a.sumRi=(a.r*(a.r-1)/2-a.l*(a.l-1)/2)*p.fi;
    }
    if(p.se!=-1){
        a.sumLR=a.sumR*p.se;
        a.sumL=(a.r-a.l)*p.se;
    }
    return a;
};
auto hh=[](pint p,pint q){
    if(q.fi!=-1)p.fi=q.fi;
    if(q.se!=-1)p.se=q.se;
    return p;
};
pint ti{-1,-1};

LazySegmentTree<Node,pint,decltype(ff),decltype(gg),decltype(hh)>
seg(ei,ti,ff,gg,hh);

int N;
int pre[111111],nex[111111];

void solve(){
    vector<Node>ini(N);
    rep(i,N){
        ini[i]={0,0,0,0,i,i+1};
    }
    seg.build(ini);

    deque<int>envR,envL;
    int curL=0;

    mint ans;
    for(int i=0;i<N;i++){
        seg.modify(i,i+1,{nex[i]-1,pre[i]+1});
        pint chL{-1,pre[i]+1},chR{nex[i]-1,-1};
        while(envR.size()&&nex[envR.back()]>=nex[i]){
            int r=envR.back()+1;
            envR.pop_back();
            int l;
            if(envR.size())l=envR.back()+1;
            else l=curL;
            seg.modify(l,r,chR);
        }
        envR.pb(i);
        while(envL.size()&&pre[envL.back()]<=pre[i]){
            int r=envL.back()+1;
            envL.pop_back();
            int l;
            if(envL.size())l=envL.back()+1;
            else l=curL;
            seg.modify(l,r,chL);
        }
        envL.pb(i);

        if(curL<=pre[i]){
            curL=pre[i]+1;
            while(envR.front()<curL)envR.pop_front();
            while(envL.front()<curL)envL.pop_front();
        }

        auto t=seg.query(curL,i+1);
        ans+=t.sumRi;
        ans-=t.sumLR;
        ans-=(t.r*(t.r-1)/2-t.l*(t.l-1)/2)*i;
        ans+=t.sumL*i;
    }
    cout<<ans<<endl;
}

signed main(){
    scanf("%lld",&N);
    vint A(N);rep(i,N)scanf("%lld",&A[i]);
    map<int,int>mem;
    rep(i,N){
        if(mem.find(A[i])!=mem.end())pre[i]=mem[A[i]];
        else pre[i]=-1;
        mem[A[i]]=i;
    }
    mem=map<int,int>();
    for(int i=N-1;i>=0;i--){
        if(mem.find(A[i])!=mem.end())nex[i]=mem[A[i]];
        else nex[i]=N;
        mem[A[i]]=i;
    }
    solve();
    return 0;
}