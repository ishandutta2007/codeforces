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

signed main(){
    int N,K;cin>>N>>K;

    if(K>1000000||K*(K+1)/2>N){
        cout<<-1<<endl;
        return 0;
    }

    int s=K*(K+1)/2;


    int G=0;
    for(int g=1;g*g<=N;g++){
        if(N%g)continue;
        if(N/s>=g)chmax(G,g);
        if(N/s>=N/g)chmax(G,N/g);
    }

    vint ans(K);
    iota(all(ans),1);
    ans[K-1]+=N/G-s;
    rep(i,K)ans[i]*=G;
    rep(i,K){
        if(i)cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}