#include<bits/stdc++.h>
using namespace std;


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
const int X=30000;
int N,D;

int cnt[33333];

const int B=300;
int dp[X+1][B];
map<int,int>dp2[X+1];
signed main(){
    cin>>N>>D;
    rep(i,N){
        int p;cin>>p;
        cnt[p]++;
    }

    fill_n(*dp,(X+1)*B,-INF);
    if(D>=B){
        dp2[D][D]=0;
    }
    else{
        dp[D][D]=0;
    }

    int ans=0;
    for(int i=D;i<=X;i++){
        for(int j=1;j<B;j++){
            if(dp[i][j]==-INF)continue;
            dp[i][j]+=cnt[i];
            chmax(ans,dp[i][j]);
            for(int k=-1;k<=1;k++){
                int d=j+k;
                if(d<=0||i+d>X)continue;
                if(d<B)chmax(dp[i+d][d],dp[i][j]);
                else chmax(dp2[i+d][d],dp[i][j]);
            }
        }

        for(auto &p:dp2[i]){
            p.se+=cnt[i];
            int j=p.fi;
            chmax(ans,p.se);
            for(int k=-1;k<=1;k++){
                int d=j+k;
                if(d<=0||i+d>X)continue;
                if(d<B)chmax(dp[i+d][d],p.se);
                else chmax(dp2[i+d][d],p.se);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}