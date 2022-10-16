#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;

const long long int mod = 998244353;
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long int dp[2011][2011]{0};
void pre(){
    dp[0][0] = 1;
    for(int i=1;i<=2000;i++){
        for(int j=0;j<=2000;j++){
            dp[i][j] = mul(dp[i-1][j],j);
            if(j!=0)
                dp[i][j] = add(dp[i][j],dp[i-1][j-1]);
        }
    }
}  
void solve(){
    ll n,m,k;cin>>n>>m>>k;
    long long int s = 1;
    long long int odd = (m + 1)/2;
    long long int even = m - odd;
    long long int ans = 0;
    long long int t = power(m,n);
    long long int ik = inv(m);
    for(int i=1;i<=k;i++){
        s = mul(mul(s,odd),n-i+1);
        t = mul(t,ik);
        ans = add(ans,mul(mul(s,dp[k][i]),t));
    }
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