#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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

ll fact[10001];
ll ifact[10001];
// Please write the recurances once :(
void pre(){
    fact[0]=1;
    ifact[0]=1;
    for(int i=1;i<=10000;i++){
        fact[i] = mul(fact[i-1],i);
        ifact[i] = divi(1,fact[i]);
    }
}

ll ncr(int n,int r){
    if( n < r || r < 0 || n < 0){
        return 0;
    }
    return mul(fact[n],mul(ifact[n-r],ifact[r]));
}
void solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    int dp[n+1];
    dp[0] = 0;
    for(int i=0;i<n;i++){
        dp[i+1] = dp[i] + s[i] - '0'; 
    }
    ll ans = 1;
    if(dp[n]<k){
        cout<<ans<<"\n";
        return;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int no_of_1 = dp[j] - dp[i-1];
            if(no_of_1 > k) continue;
            if(s[i-1]=='0') no_of_1--;
            if(s[j-1]=='0') no_of_1--;
            ll cases = ncr(j-i-1,no_of_1);
            ans = ans + cases;
        }
    }
    cout<<ans%mod<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}