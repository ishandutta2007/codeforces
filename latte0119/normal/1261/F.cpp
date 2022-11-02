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
using mint=ModInt<998244353>;

vpint in(){
    int n;scanf("%lld",&n);
    vpint v;
    rep(i,n){
        int l,r;
        scanf("%lld%lld",&l,&r);
        r++;
        v.eb(l,r);
    }
    sort(all(v));
    vpint vv;
    for(auto &p:v){
        if(vv.size()==0||vv.back().se<p.fi){
            vv.pb(p);
            continue;
        }
        chmax(vv.back().se,p.se);
    }
    return vv;
}


void dfs(int l,int r,int b,vpint &v,vector<vint>&rX,vector<vint>&vX){
    bool isR=false,isV=false;
    for(auto &p:v){
        if(r<=p.fi||p.se<=l)continue;
        if(p.fi<=l&&r<=p.se)isR=true;
        isV=true;
    }

    if(isR){
        rX[b].pb(l);
    }
    if(isV){
        vX[b].pb(l);
    }

    if(isR)return;
    if(!isV)return;
    dfs(l,(l+r)/2,b-1,v,rX,vX);
    dfs((l+r)/2,r,b-1,v,rX,vX);
}

signed main(){
    vpint A=in();
    vpint B=in();

    

    vector<vint>rA(61),vA(61);
    vector<vint>rB(61),vB(61);
    dfs(0,1ll<<60,60,A,rA,vA);
    dfs(0,1ll<<60,60,B,rB,vB);


    vpint lis;

    rep(i,60+1){
        for(auto a:rA[i])for(auto b:vB[i])lis.eb(a^b,(a^b)+(1ll<<i));
        for(auto a:vA[i])for(auto b:rB[i])lis.eb(a^b,(a^b)+(1ll<<i));
    }
    sort(all(lis));

    /*
    lis.erase(unique(all(lis)),lis.end());
    vpint nex;
    for(auto &p:lis){
        bool ok=true;
        for(auto &q:lis){
            if(p==q)continue;
            if(q.fi<=p.fi&&p.fi+(1ll<<p.se)<=q.fi+(1ll<<q.se))ok=false;
        }
        if(ok)nex.pb(p);
    }
    */

    vpint nex;
    for(auto &p:lis){
        if(nex.size()==0||nex.back().se<p.fi){
            nex.pb(p);
        }
        else{
            chmax(nex.back().se,p.se);
        }
    }
    lis=nex;
    


    mint ans=0;

    for(auto &p:lis){
        mint n(p.se-p.fi);
        ans+=n*p.fi*2;
        ans+=n*(n-1);
    }
    ans/=2;
    cout<<ans<<endl;
    return 0;
}