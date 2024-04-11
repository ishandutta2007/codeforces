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

const int INF=1001001001;

int N;
int A[222222];
int ans[222222];

signed main(){
    cin>>N;
    rep(i,N)cin>>A[i];

    int d=INF;
    rep(i,N){
        if(A[i]==0)d=0;
        else d++;
        ans[i]=d;
    }

    d=INF;
    for(int i=N-1;i>=0;i--){
        if(A[i]==0)d=0;
        else d++;
        chmin(ans[i],d);
    }

    rep(i,N){
        if(i)cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}