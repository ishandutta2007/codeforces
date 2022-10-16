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

const long long int mod = 1e9+7;
long long int power(long long int x,long long int y){  
    long long int res = 1;
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0){   
        if (y & 1)  
            res = (res*x) % mod;  
        y = y>>1;
        x = (x*x) % mod; 
    }  
    return res;
}  
long long int inv(long long int a){return power(a,mod-2);}
long long int add(long long int a,long long int b){return (a+b)%mod;}
long long int sub(long long int a,long long int b){return (a-b+mod)%mod;}
long long int mul(long long int a,long long int b){return (a*b)%mod;}
long long int divi(long long int a,long long int b){return (a*inv(b))%mod;}

// Please write the recurances once :(
void pre(){}
void solve(){
    ll n,k;cin>>n>>k;
    ll dp[n+2][k+1][2];
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=k;j++)
            for(int t=0;t<2;t++)
                dp[i][j][t]=0;
    dp[1][k][1]=1;
    for(int j=k;j>=2;j--){
        ll count = 0;
        for(int i=1;i<=n;i++){
            count=add(dp[i][j][1],count);
            dp[i-1][j-1][0] = add(dp[i-1][j-1][0],count);
        }
        count = 0;
        for(int i=n;i>=1;i--){
            count=add(count,dp[i][j][0]);
            dp[i+1][j-1][1] = add(dp[i+1][j-1][1],count);
        }
    }
    ll ans = 0;
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=k;j++)
            for(int t=0;t<2;t++)
                ans=add(ans,dp[i][j][t]);
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