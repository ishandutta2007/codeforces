#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int N;
string S;

int dp[100010][4][2];

signed main(){
    cin>>N>>S;
    fill_n(**dp,100010*4*2,-114514);
    dp[0][0][0]=dp[0][0][1]=0;

    rep(i,N){
        rep(j,3){
            rep(k,2){
                if((S[i]-'0'+j)%2==k){
                    chmax(dp[i+1][j][k],dp[i][j][k]);
                    chmax(dp[i+1][j+1][k^1],dp[i][j][k]+1);
                }
                else{
                    chmax(dp[i+1][j][k^1],dp[i][j][k]+1);
                    chmax(dp[i+1][j+1][k],dp[i][j][k]);
                }
            }
        }
    }

    int ans=-114514;
    rep(i,3)rep(j,2)chmax(ans,dp[N][i][j]);
    cout<<ans<<endl;

    return 0;
}