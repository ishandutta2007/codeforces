#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
#define F first
#define S second
typedef long long ll;
using namespace std;
void pre(){}
void solve(){
    ll n;cin>>n;
    pii arr[n+1];
    for(int i=1;i<=n;i++)
        cin>>arr[i].first>>arr[i].second;
    ll dp[n+1][n+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=1e15;
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=dp[i-1][j];
        }
        for(int j=0;j<=n;j++){
            dp[i][min(j+arr[i].first+1,n)]=min(dp[i][min(j+arr[i].first+1,n)],dp[i-1][j]+arr[i].second);
        }
    }
    ll ans = 1e16;
    for(int i=0;i<=n;i++){
        ans=min(ans,dp[i][n]);
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();   
}