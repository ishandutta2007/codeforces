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
typedef unsigned long long ll;
using namespace std;
void pre(){}
ll dp[50][50]{0};
ll rec(ll n,ll h){
    if(n<h || n>=(1ll<<h)){
        return 0;
    }
    if(n==0){
        return 1;
    }
    if(dp[n][h]!=0){
        return dp[n][h];
    }
    for(int i=0;i<=n;i++){
        ll oo = 0,op = 0;
        for(int j=0;j<h;j++){
            oo+=rec(n-i-1,j);
            op+=rec(i,j);
        }
        dp[n][h]+=rec(i,h-1)*oo+rec(n-i-1,h-1)*op-rec(n-i-1,h-1)*rec(i,h-1);
    }
    return dp[n][h];
}
void solve(){
    ll n,h;cin>>n>>h;
    ll ans = 0;
    for(int i=h;i<=n;i++){
        ans+=rec(n,i);
    }
    cout<<ans<<"\n";
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