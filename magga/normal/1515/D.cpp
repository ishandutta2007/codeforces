#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
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
// Please write the recurances once :(
void pre(){}
void solve(){
    ll n,l,r,d;cin>>n>>l>>r;
    vector<vector<ll>> dp(2,vector<ll>(n+1,0)) ;
    for(int i=0;i<n;i++){
        cin>>d;
        if(i<l) dp[0][d]++;
        else dp[1][d]++;
    }
    ll ans = 0;
    ll done = 0;
    for(int i=0;i<=n;i++){
        d = min(dp[0][i],dp[1][i]);
        dp[0][i] -= d;
        dp[1][i] -= d;
        done+=2*d;
    }
    for(int i=0;i<=n;i++){
        while(dp[0][i]>1 && l>r){
            dp[0][i]-=2;
            l--;
            r++;
            ans++;
            done+=2;
        }
        while(dp[1][i]>1 && l<r){
            dp[1][i]-=2;
            l++;
            r--;
            ans++;
            done+=2;
        }
        //cout<<i<<ans<<"\n";
    }
    ans += abs(l-r)/2 + (n-done)/2;
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