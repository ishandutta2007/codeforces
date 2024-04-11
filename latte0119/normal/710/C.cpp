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

vint Os,Es;

int odd(){
    int tmp=Os.back();
    Os.pop_back();
    return tmp;
}
int even(){
    int tmp=Es.back();
    Es.pop_back();
    return tmp;
}

int ans[55][55];
signed main(){
    int N;
    cin>>N;
    for(int i=1;i<=N*N;i++){
        if(i&1)Os.pb(i);
        else Es.pb(i);
    }

    if(N%4==1){
        rep(i,N)rep(j,N)ans[i][j]=(j+1)&1;
        rep(j,N)ans[N/2][j]=1;
        rep(i,N)if(i&1)ans[i][0]=ans[i][N-1]=0;
    }
    else{
        rep(i,N)rep(j,N)ans[i][j]=j&1;
        
        rep(j,N)ans[N/2][j]=1;
    }

    rep(i,N)rep(j,N){
        if(ans[i][j])ans[i][j]=odd();
        else ans[i][j]=even();
    }

    rep(i,N){
        rep(j,N){
            if(j)cout<<" ";
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}