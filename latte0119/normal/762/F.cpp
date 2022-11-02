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
istream& operator>>(istream& in,ModInt<mod>& a){
    return (in>>a.a);
}
template<uint32_t mod>
ostream& operator<<(ostream& out,const ModInt<mod>& a){
    return (out<<a.a);
}
using mint=ModInt<1000000007>;

int N;
int M;
vint S[1111],T[22];
int id[22][22];
pint mem[33];

mint dp[1111][33];

mint dp2[1<<12];

mint ans;
void dfs(int v,int p){
    for(auto u:S[v]){
        if(u==p)continue;
        dfs(u,v);
    }

    rep(i,M){
        int cs=T[i].size();
        rep(j,1<<cs)dp2[j]=0;
        dp2[0]=1;
        for(auto u:S[v]){
            if(u==p)continue;
            for(int j=(1<<cs)-1;j>=0;j--){
                rep(k,cs)if(!(j>>k&1))dp2[j|(1<<k)]+=dp2[j]*dp[u][id[i][T[i][k]]];
            }
        }
        ans+=dp2[(1<<cs)-1];
        rep(k,cs){
            dp[v][id[T[i][k]][i]]=dp2[((1<<cs)-1)^(1<<k)];
        }
    }
}

signed main(){
    cin>>N;
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        S[a].pb(b);S[b].pb(a);
    }
    cin>>M;
    rep(i,M-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        T[a].pb(b);T[b].pb(a);
        id[a][b]=i*2;
        mem[i*2]=pint(a,b);
        id[b][a]=i*2+1;
        mem[i*2+1]=pint(b,a);
    }

    dfs(0,-1);

    mint tmp=ans;

    ans=0;
    rep(i,M){
        S[i]=T[i];
    }

    rep(i,M)rep(j,33)dp[i][j]=0;

    dfs(0,-1);

    ans=tmp/ans;

    cout<<ans<<endl;
    return 0;
}