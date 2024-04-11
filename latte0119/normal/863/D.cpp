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
    int N,Q,M;
    scanf("%lld%lld%lld",&N,&Q,&M);

    vint A(N);rep(i,N)scanf("%lld",&A[i]);
    vint T(Q),L(Q),R(Q);
    rep(i,Q){
        scanf("%lld%lld%lld",&T[i],&L[i],&R[i]);
        L[i]--;
    }

    rep(i,M){
        int b;scanf("%lld",&b);
        b--;
        for(int j=Q-1;j>=0;j--){
            if(R[j]<=b||b<L[j])continue;
            if(T[j]==1){
                if(b==L[j])b=R[j]-1;
                else b--;
            }
            else{
                b=R[j]-1-(b-L[j]);
            }
        }
        if(i)printf(" ");
        printf("%lld",A[b]);
    }
    puts("");
    return 0;
}