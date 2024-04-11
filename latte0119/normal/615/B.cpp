#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int N,M;
vint G[100000];

int dp[100000];

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,M){
        int a,b;scanf("%lld%lld",&a,&b);a--;b--;
        G[a].pb(b);G[b].pb(a);
    }

    int ans=0;

    rep(i,N){
        dp[i]++;
        rep(j,G[i].size()){
            int to=G[i][j];
            if(to<i)continue;
            dp[to]=max(dp[to],dp[i]);
        }
        ans=max(ans,dp[i]*G[i].size());
    }

    printf("%lld\n",ans);
    return 0;
}