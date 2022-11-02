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

int N,K;
int F[111111],W[111111];

int nex[40][111111];
int sum[40][111111];
int mi[40][111111];

signed main(){
    scanf("%lld%lld",&N,&K);
    rep(i,N)scanf("%lld",&F[i]);
    rep(i,N)scanf("%lld",&W[i]);

    rep(i,N){
        nex[0][i]=F[i];
        sum[0][i]=mi[0][i]=W[i];
    }

    for(int k=0;k+1<40;k++){
        rep(i,N){
            sum[k+1][i]=sum[k][i]+sum[k][nex[k][i]];
            mi[k+1][i]=min(mi[k][i],mi[k][nex[k][i]]);
            nex[k+1][i]=nex[k][nex[k][i]];
        }
    }

    rep(i,N){
        int pos=i,s=0,m=INF;
        rep(j,40){
            if(K>>j&1){
                s+=sum[j][pos];
                chmin(m,mi[j][pos]);
                pos=nex[j][pos];
            }
        }
        printf("%lld %lld\n",s,m);
    }
    return 0;
}