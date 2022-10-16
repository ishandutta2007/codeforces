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
    ll n,m;cin>>n>>m;
    ll arr[n][m];
    vector<ll>s;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            arr[i][j]-=(j+i);
            s.pb(arr[i][j]);
            //cout<<arr[i][j]<<" ";
        }
        //cout<<"\n";
    }
    ll dp[n+1][m+1];
    ll ans = 9e18;
    for(auto o:s){
        if(o>arr[0][0] || o>arr[n-1][m-1]){
            continue;
        }
       // cout<<o<<"\n";
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j]=9e18;
            }
        }
        dp[1][1]=arr[0][0]-o;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1 && j==1){
                    continue;
                }
                if(arr[i-1][j-1]<o){
                    continue;
                }
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+arr[i-1][j-1]-o;
            }
        }
        ans=min(ans,dp[n][m]);
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}