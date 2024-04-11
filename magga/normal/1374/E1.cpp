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
vector<long long int>arr[4];
vector<long long int>dp[4];
void construct(){
    sort(arr[0].begin(),arr[0].end());
    sort(arr[1].begin(),arr[1].end());
    sort(arr[2].begin(),arr[2].end());
    sort(arr[3].begin(),arr[3].end());
    dp[0].resize(arr[0].size()+1,0);
    dp[1].resize(arr[1].size()+1,0);
    dp[2].resize(arr[2].size()+1,0);
    dp[3].resize(arr[3].size()+1,-0);
    for(int i=0;i<4;i++){
        for(int j=1;j<=arr[i].size();j++){
            dp[i][j]=dp[i][j-1]+arr[i][j-1];
        }
    }
}
void solve(){
    ll n,k;cin>>n>>k;
    ll a,b,c;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        if(b & c){
            arr[3].push_back(a);
        }else if(b){
            arr[1].push_back(a);
        }else if(c){
            arr[2].push_back(a);
        }else{
            arr[0].push_back(a);
        }
    }
    construct();
    ll ans = 1e18;
    for(int i=0;i<=k;i++){
        if(arr[3].size()>=i && arr[1].size()>=k-i && arr[2].size()>=k-i){
            ans = min(ans,dp[3][i]+dp[1][k-i]+dp[2][k-i]);
        }
    }
    if(ans!=1e18){
        cout<<ans<<"\n";
    }else{
        cout<<-1<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}