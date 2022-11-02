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

const int INF=1001001001001001001;

signed main(){
    int N,M;
    scanf("%lld%lld",&N,&M);
    vint A(N),B(M);
    rep(i,N)scanf("%lld",&A[i]);
    rep(i,M)scanf("%lld",&B[i]);

    sort(all(B));
    int ans=0;
    rep(i,N){
        int tmp=INF;

        int k=lower_bound(all(B),A[i])-B.begin();
        if(k<B.size())chmin(tmp,B[k]-A[i]);
        k--;
        if(0<=k)chmin(tmp,A[i]-B[k]);

        chmax(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}