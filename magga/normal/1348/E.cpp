#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
typedef long long ll;
using namespace std;
void pre(){}
void solve(){
    ll n,k;cin>>n>>k;
    pii arr[n+1];
    for(int i=1;i<=n;i++) cin>>arr[i].first>>arr[i].second;
    bool dp[501][500]{0};
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<k;j++){
            if(arr[i].first>=j && (k-(arr[i].first-j)%k)%k<=arr[i].second){
                for(int p=0;p<k;p++){
                    if(dp[i-1][p])
                        dp[i][(p+j)%k]=dp[i-1][p];
                }
            }
        }
    }
    ll a = 0,b=0;
    for(int i=1;i<=n;i++){
        a+=arr[i].first;
        b+=arr[i].second;
    }
    ll ans = 0;
    for(int i=0;i<k;i++){
        //cout<<i<<" "<<dp[n][i]<<"\n";
        if(dp[n][i]){
            ans = max(ans,(a+b-i)/k);
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}