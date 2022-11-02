#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

bitset<501>dp[501][501];
int N,K;
int C[500];
signed main(){
    dp[0][0][0]=1;
    cin>>N>>K;
    rep(i,N)cin>>C[i];

    rep(i,N){
        for(int j=0;j<=K;j++){
            dp[i+1][j]|=dp[i][j];
            if(j+C[i]<=K){
                dp[i+1][j+C[i]]|=dp[i][j];
                dp[i+1][j+C[i]]|=dp[i][j]<<C[i];
            }
        }
    }

    vint ans;
    for(int i=0;i<=K;i++)if(dp[N][K][i])ans.pb(i);
    printf("%lld\n",(int)ans.size());
    rep(i,ans.size())printf("%lld ",ans[i]);
    puts("");
    return 0;
}