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
int dp[2222][2222];
int sum[2222][2222];
int N,K;
string S;
int A[2222];

inline void add(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}

signed main(){
    cin>>N>>K;
    cin>>S;

    rep(i,N)A[i]=S[i]-'a';

    dp[0][0]=1;
    sum[0][0]=1;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=K;j++){
            dp[i][j]=sum[i-1][j]*A[i-1]%mod;

            for(int k=1;i-k>=0&&j-(N-i+1)*k>=0;k++)add(dp[i][j],dp[i-k][j-(N-i+1)*k]*(25-A[i-1])%mod);

            sum[i][j]=(sum[i-1][j]+dp[i][j])%mod;
        }
    }

    cout<<sum[N][K]<<endl;
}