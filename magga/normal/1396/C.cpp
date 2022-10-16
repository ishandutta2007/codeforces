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
void pre(){}
void solve(){
    ll n;cin>>n;
    long long int r1,r2,r3,d;cin>>r1>>r2>>r3>>d;
    long long int dp[n+2][2];
    for(int i=0;i<=n+1;i++){
        dp[i][0]=1e18;
        dp[i][1]=1e18;
    }
    dp[0][0]=0;
    dp[0][1]=1e18;
    ll arr[n];
    for(int i=0;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(dp[i][0]<1e18){
            dp[i+1][1]=min(r2,r1*(arr[i]+1))+dp[i][0]+d;
            dp[i+1][0]=r1*(arr[i])+r3+dp[i][0]+d;
        }
        if(dp[i][1]<1e18){
            dp[i+1][0]=min(dp[i+1][0],3*d+min(r2,r1*(arr[i]+1))+2*r1+dp[i][1]);
        }
    }
    long long int ans = dp[n-1][0] + min( arr[n-1]*r1+r3 , min(r2,(arr[n-1]+1)*r1) + 2*d+r1 );
    long long int ans2 = dp[n-1][1] + min(arr[n-1]*r1+r3+d+r1,min(r2,(arr[n-1]+1)*r1)+2*d+2*r1);
    cout<<min(ans,ans2)<<"\n";
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