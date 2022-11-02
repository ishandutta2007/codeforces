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

int N,K;
const int offset=1100;

int dp[1111][2222];
string S;
signed main(){
    cin>>N>>K;
    cin>>S;

    fill_n(*dp,1111*2222,-2);
    dp[0][offset]=0;
    for(int i=0;i<N;i++){
        for(int j=-K+1;j<K;j++){
            if(dp[i][j+offset]==-2)continue;
            int d;
            if(S[i]=='W')d=1;
            else if(S[i]=='L')d=-1;
            else if(S[i]=='D')d=0;
            else d=-2;

            for(int k=-1;k<=1;k++){
                if(d!=-2&&k!=d)continue;
                dp[i+1][j+k+offset]=k;
            }
        }
    }

    int acc;
    if(dp[N][K+offset]==-2&&dp[N][-K+offset]==-2){
        cout<<"NO"<<endl;
        return 0;
    }
    if(dp[N][K+offset]!=-2)acc=K;
    else acc=-K;

    string ans(N,'?');
    for(int i=N-1;i>=0;i--){
        int d=dp[i+1][acc+offset];
        if(d==1)ans[i]='W';
        else if(d==-1)ans[i]='L';
        else ans[i]='D';

        acc-=d;
    }

    cout<<ans<<endl;
    return 0;
}