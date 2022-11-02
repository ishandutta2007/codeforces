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

double dp[111][111][111];
double p[111][111][111];

int N;
double T[111][111];

signed main(){
    cin>>N;
    rep(i,1<<N)rep(j,1<<N){
        cin>>T[i][j];
        T[i][j]/=100;
    }

    for(int i=0;i<1<<N;i++)p[i][i+1][i]=1.0;
    for(int len=2;len<=1<<N;len<<=1){
        for(int i=0;i<1<<N;i+=len){
            int j=i+len;
            double ma=0;
            for(int k=i+len/2;k<j;k++)chmax(ma,dp[i+len/2][j][k]);
            for(int k=i;k<i+len/2;k++){
                    dp[i][j][k]=dp[i][i+len/2][k]+ma;
                for(int l=i+len/2;l<j;l++){
                    dp[i][j][k]+=len/2*T[k][l]*p[i][i+len/2][k]*p[i+len/2][j][l];
                    p[i][j][k]+=p[i][i+len/2][k]*p[i+len/2][j][l]*T[k][l];
                }
            }

            ma=0;
            for(int k=i;k<i+len/2;k++)chmax(ma,dp[i][i+len/2][k]);
            for(int l=i+len/2;l<j;l++){
                    dp[i][j][l]=dp[i+len/2][j][l]+ma;
                for(int k=i;k<i+len/2;k++){

                    dp[i][j][l]+=len/2*T[l][k]*p[i][i+len/2][k]*p[i+len/2][j][l];
                    p[i][j][l]+=p[i][i+len/2][k]*p[i+len/2][j][l]*T[l][k];
                }
            }
        }
    }

    printf("%.20f\n",*max_element(dp[0][1<<N],dp[0][1<<N]+(1<<N)));
    return 0;
}