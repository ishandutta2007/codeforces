#include<bits/stdc++.h>
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
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
ll dp[251][251][251]{0}; // number of nodes,largest number yet,count
// Pleasef write the recurances once :(
void solve(){
    ll n,k;cin>>n>>k;
    for(int i=1;i<=k;i++) 
        dp[2][i][1] = 1;
    for(ll i=3;i<=n;i++){
        ll pref = 0;
        for(ll j=1;j<=k;j++){
            dp[i][j][1] = mul(pref,mul(power(k-j+1,i-2),i-1));
            for(ll p=2;p<=n;p++)
                dp[i][j][p] = mul(dp[i-1][j][p-1],mul(power(k-j+1,i-2),divi(i-1,p)));
            for(ll p=1;p<=n;p++)
                pref = add(pref,dp[i-1][j][p]);
        }
    }
    ll ans = 0;
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
            ans = add(ans,dp[n][i][j]);
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}
// 1 1 
//