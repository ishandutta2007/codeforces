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

int N;
int P[1111];

int dp[1111];
bool used[1111];

signed main(){
    cin>>N;
    rep(i,N)cin>>P[i],P[i]--;

    rep(i,N){
        if(i==P[i]){
            dp[i]=1;
            continue;
        }

        memset(used,0,sizeof(used));
        int v=i;
        while(v!=P[v]){
            v=P[v];
            used[v]=true;
            dp[i]++;
        }

        dp[i]+=1+i-v;
        for(int j=v;j<i;j++)if(!used[j])dp[i]=(dp[i]+dp[j])%mod;
    }

    int ans=N;
    ans=(ans+accumulate(dp,dp+N,0ll))%mod;
    cout<<ans<<endl;
    return 0;
}