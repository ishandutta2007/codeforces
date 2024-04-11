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
    ll n,m,k;cin>>n>>m>>k;
    vector<vector<ll>> dp(n+2,vector<ll>(m+2));
    vector<vector<ll>> dp2(n+2,vector<ll>(m+2));
    ll wside[n+2][m+2];
    ll wdown[n+2][m+2];
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            dp[i][j] = 0;
            wside[i][j] = 1e15;
            wdown[i][j] = 1e15;
            if(i==0 || i==n+1 || j==0 || j==m+1) dp[i][j] = 0;
        }
        
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m-1;j++){
            cin>>wside[i][j];
        }
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m;j++){
            cin>>wdown[i][j];
        }
    }
    for(int s=1;s<=k/2;s++){
        dp2 = dp;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j] = min(dp2[i][j-1]+wside[i][j-1],min(dp2[i][j+1]+wside[i][j],min(dp2[i-1][j]+wdown[i-1][j],dp2[i+1][j]+wdown[i][j])));
            }
        }
    }
    if(k%2==1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<-1<<" ";
            }
            cout<<"\n";
        }
        return;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<2*dp[i][j]<<" ";
        }
        cout<<"\n";
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