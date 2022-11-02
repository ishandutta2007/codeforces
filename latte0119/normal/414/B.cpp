#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int mod=1000000007;
inline void add(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}

int dp[2222][2222];

signed main(){
    int N,K;
    cin>>N>>K;
    dp[0][1]=1;
    for(int i=0;i<K;i++){
        for(int j=1;j<=N;j++){
            for(int k=j;k<=N;k+=j)add(dp[i+1][k],dp[i][j]);
        }
    }

    int ans=0;
    for(int i=1;i<=N;i++)add(ans,dp[K][i]);
    cout<<ans<<endl;
    return 0;
}