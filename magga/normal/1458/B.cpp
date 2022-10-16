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
ll dp[101][10001]{0};
ll arr[101];
ll brr[101];
void solve(){
    ll n;cin>>n;
    ll tot = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        cin>>brr[i];
        tot+=brr[i];
    }
    for(int k=n;k>=0;k--){
        for(int sum=0;sum<=n*100;sum++){
            dp[k][sum]  = -1e18;
        }
    }
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        for(int k=n-1;k>=0;k--){
            for(int sum=0;sum<=n*100;sum++){
                if(dp[k][sum]!=-1e18)
                    dp[k+1][sum+arr[i]]  = max(dp[k+1][sum+arr[i]],dp[k][sum]+brr[i]);
            }
        }
    }
    for(int k=1;k<=n;k++){
        long double ans = 0;
        for(int sum=0;sum<=n*100;sum++){
            ans = max(ans, min((long double)sum,(long double)(dp[k][sum] + (tot - dp[k][sum])/2.0)) );
            if(ans==8.5){
                cout<<k<<" "<<sum<<"\n";
            }
        }
        cout<<setprecision(20)<<ans<<" ";
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