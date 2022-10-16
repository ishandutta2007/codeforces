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
    ll n,d;cin>>n;
    //ll dp[n][n];
    map<int,vector<int>>m;
    for(int i=0;i<2*n;i++){
        cin>>d;
        m[d].push_back(i+1);
    }    
    ll dp[100001];
    dp[0]=0;
    for(int i=1;i<=n;i++){
        if(i==1){
            dp[i]=m[1][0]+m[1][1];
            continue;
        }
        //dp[i][0]=min(dp[i-1][0]+abs(m[i-1][0]-m[i][0]),dp[i-1][1]+abs(m[i-1][1]-m[i][0]));
        //dp[i][1]=min(dp[i-1][0]+abs(m[i-1][0]-m[i][1]),dp[i-1][1]+abs(m[i-1][1]-m[i][1]));
        dp[i]=dp[i-1]+min( abs(m[i][0]-m[i-1][0]) +  abs(m[i][1]-m[i-1][1]), abs(m[i][1]-m[i-1][0]) +  abs(m[i][0]-m[i-1][1]) );
    }
    cout<<dp[n]-2<<"\n";
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