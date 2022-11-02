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

int N,M,K;
string S,T;

int dp[2][1010][11][2];

signed main(){
    cin>>N>>M>>K;
    cin>>S>>T;

    fill_n(***dp,2*1010*11*2,-1001001001);
    dp[0][0][0][0]=0;
    int ma=0;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=M;j++){
            for(int k=0;k<=K;k++){
                rep(l,2){
                    if(i<N)chmax(dp[(i+1)&1][j][k][0],dp[i&1][j][k][l]);
                    if(j<M)chmax(dp[i&1][j+1][k][0],dp[i&1][j][k][l]);
                }
                if(i<N&&j<M&&S[i]==T[j]){
                    if(k<K){
                        chmax(dp[(i+1)&1][j+1][k+1][1],dp[i&1][j][k][0]+1);
                        chmax(dp[(i+1)&1][j+1][k+1][1],dp[i&1][j][k][1]+1);
                    }
                    chmax(dp[(i+1)&1][j+1][k][1],dp[i&1][j][k][1]+1);
                }
                rep(l,2){
                    if(k==K)chmax(ma,dp[i&1][j][k][l]);
                    dp[i&1][j][k][l]=-1001001001;
                }
            }
        }
    }

    cout<<ma<<endl;
    return 0;
}