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

// WRITE DOWN THE RECCURANCES FFS 
// Please write the recurances once :(
ll fact[1001];
ll ifact[1001];
ll ncr[1001][1001];
void pre(){
    fact[0]=1;
    ifact[0]=1;
    for(int i=1;i<=1000;i++){
        fact[i]=mul(fact[i-1],i);
        ifact[i] = divi(1,fact[i]);
    }
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=i;j++){
            ncr[i][j] = mul(fact[i],mul(ifact[j],ifact[i-j]));
        }
    }
}
//  dp[j] = number of cases if 2^i below the r 
ll nChoose(int n,int r){
    if(n<0 || n<r || r<0) return 0;
    else return ncr[n][r];
}
ll digitDP(ll n,ll r,ll z){
    if(r<z) return 0;
    r-=z;
    r/=2;
    vector<vector<ll>>dp(2,vector<ll>(1005));
    string indicator = bitset<62>(r).to_string();
    string plusOne = bitset<62>(z).to_string();
    dp[0][0]=1;
    for(int i=0;i<62;i++){
        ll budget = indicator[i] - '0';
        ll bonus = plusOne[i] - '0';
        for(int j=999;j>=1;j--){
            if((j<<1) >= 1000){
                dp[0][1000] = add(dp[0][1000],dp[0][j]); 
            }else{
                dp[0][j<<1] = add(dp[0][j<<1],dp[0][j]);
            } 
            dp[0][j]=0;
        }
        for(auto &i:dp[1]) i = 0;
        for(int i=0;i<=1004;i++){
            for(int j=max(i-budget,0ll);j<=1004;j++){   
                dp[1][i] = add(dp[1][i],mul(nChoose(n,bonus + 2*(j+budget-i)),dp[0][j]));
            }
        }
        dp[1][1000] = (dp[1][1000] + dp[1][1001] + dp[1][1002] + dp[1][1003])%mod;
        dp[1][1001] = 0;
        dp[1][1002] = 0;
        dp[1][1003] = 0;
        swap(dp[0],dp[1]);
    }
    ll ans = 0;
    for(int i=0;i<=1000;i++){
        ans = add(ans,dp[0][i]);
    }
    return ans;
}
void solve(){
    ll n,l,r,z;cin>>n>>l>>r>>z;
    cout<<sub(digitDP(n,r,z),digitDP(n,l-1,z))<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}