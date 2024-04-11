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
ll cache[2001][2001];
ll dp(int i,int j,ll k){
    if(i==0 || j==0) return 0;
    if(i==j) return mul(k,i);
    if(cache[i][j]!=-1) return cache[i][j];
    ll val = divi(sub(dp(i-1,j,k),dp(i-1,j-1,k)),2);
    cache[i][j] = add(divi(sub(dp(i-1,j,k),dp(i-1,j-1,k)),2),dp(i-1,j-1,k));
    return cache[i][j]; 
}
// Please write the recurances once :(
void pre(){}
void solve(){
    int n,m,k;cin>>n>>m>>k;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cache[i][j]=-1;
        }
    }
    cout<<dp(n,m,k)<<"\n";
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


// n turns 
// choose i [0,k] 
// add or sub 
// add m of n 
// (m - n)*k 
// 6 3 10 75/8 
// dp [1001][1001];
// choose val = (dp[i-1][j] - dp[i-1][j-1])/2; 
// dp[i][j] = dp[i-1][j] - val or dp[i][j-1] + val