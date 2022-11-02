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

int N;
int L;

const int INF=1001001001001001001ll;
vint A;
int dp[1<<18][19];

signed main(){
    scanf("%lld",&N);
    L=__lg(N);

    bool ap=false;
    rep(i,N){
        int a;scanf("%lld",&a);
        if(a==-1){
            ap=true;
        }
        else{
            if(!ap)a=0;
            A.pb(a);
        }
    }

    reverse(all(A));
    fill_n(*dp,(1<<18)*19,INF);
    dp[0][0]=0;
    rep(i,N-1){
        rep(j,L+1){
            if(dp[i][j]==INF)continue;
            int cap=((1<<j)-1)<<(L-j);
            if(i+1<=cap)chmin(dp[i+1][j],dp[i][j]);
            if(j+1<=L)chmin(dp[i+1][j+1],dp[i][j]+A[i]);          
        }
    }

    cout<<dp[N-1][L]<<endl;
    return 0;
}