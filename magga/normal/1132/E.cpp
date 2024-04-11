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
ll dp[9][841];
void solve(){
    ll w;cin>>w;
    ll arr[9];
    for(int i=1;i<=8;i++){
        cin>>arr[i];
    }
    for(int j=0;j<=840;j++){
        dp[0][j]=-1e15;
    }
    dp[0][0]=0;
    ll oo = 0;
    for(ll i=1;i<=8;i++){
        for(ll j=0;j<=840;j++){
            dp[i][j]=dp[i-1][j];
        }
        for(ll j=0;j<=840;j++){
            for(ll k=0;k<min(840/i,arr[i]);k++){
                oo = (j + (arr[i]-k)*i)%840;
                dp[i][oo]=max(dp[i][oo],dp[i-1][j]+(j+(arr[i]-k)*i)/840);
            }
        }
    }
    ll ans = 1e18;
    for(int i=0;i<840;i++){
        if(dp[8][i]<0)
            continue;
        if(i>w){
            break;
        }
        ans = min(ans,w-i-840*min( dp[8][i] , (w - i)/840  ));
    }
    cout<<w-ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();   
}