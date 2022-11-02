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
    int N;scanf("%lld",&N);
    map<int,int>cnt;
    rep(i,N){
        int a;scanf("%lld",&a);
        cnt[a]++;
    }

    int ans=0;
    for(auto &w:cnt){
        int v=w.fi;
        int num=w.se;

        for(int i=1;i<=33;i++){
            int tmp=(1ll<<i)-v;
            if(cnt.find(tmp)==cnt.end())continue;
            ans+=cnt[tmp]*num;
        }

        if(popcount(v)==1)ans-=num;
    }
    ans/=2;
    cout<<ans<<endl;
    return 0;
}