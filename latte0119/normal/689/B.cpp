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

int N;
int A[222222];
int dp[222222];
signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]),A[i]--;
    fill_n(dp,222222,1001001001);
    dp[0]=0;
    for(int i=0;i+1<N;i++){
        chmin(dp[i+1],dp[i]+1);
        chmin(dp[A[i]],dp[i]+1);
        int t=A[i];
        while(t>0&&dp[t-1]>dp[t]+1){
            dp[t-1]=dp[t]+1;
            t--;
        }
    }
    rep(i,N)printf("%lld ",dp[i]);
    puts("");
    return 0;
}