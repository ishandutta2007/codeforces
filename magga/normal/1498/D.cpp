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
    ll n,m;cin>>n>>m;
    vector<ll>v(m+1),dp(m+1),ans(m+1);
    v[0]=1;
    for(int i=0;i<=m;i++){
        ans[i]=-1;
    }
    ll t,x,y;
    ll c = 100000;
    for(int i=0;i<n;i++){
        cin>>t>>x>>y;
        if(t==1){
            for(int j=0;j<=m;j++){
                dp[j]=-1;
                if(v[j]==1){
                    dp[j]=y;
                }
            }
            for(int j=0;j<=m;j++){
                if(j + (x+c-1)/c <=m && dp[j]>0){
                    dp[j + (x+c-1)/c] = max(dp[j]-1,dp[j + (x+c-1)/c]);
                }
            }
            for(int j=0;j<=m;j++){
                if(!v[j] && dp[j]>=0){
                    v[j]=1;
                    ans[j] = i+1;
                }
            }
        }else{
            for(int j=0;j<=m;j++){
                dp[j]=-1;
                if(v[j]==1){
                    dp[j]=y;
                }
            }
            for(int j=0;j<=m;j++){
                if((j * x + c - 1 )/c <=m && dp[j]>0){
                    dp[(j * x + c - 1)/c] = max(dp[j]-1,dp[(j * x + c - 1)/c]);
                }
            }
            for(int j=0;j<=m;j++){
                if(!v[j] && dp[j]>=0){
                    v[j]=1;
                    ans[j] = i+1;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
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