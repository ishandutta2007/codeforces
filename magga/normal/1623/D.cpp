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

// Please write the recurances once :(
void pre(){}
void solve(){
    ll n,m,rb,cb,rd,cd,p;cin>>n>>m>>rb>>cb>>rd>>cd>>p;
    ll dp[4][n][m][2]; // 0 = t 1 = li 
    rb--;cb--;
    rd--;cd--;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                dp[k][i][j][0]=-1;
                dp[k][i][j][1]=-1;
            }
        }
    }
    int pr = 1;
    int pc = 1;
    ll curr = 3;
    ll counter = 0;
    ll L = 0;
    while(true){
        
        if(rb==n-1 && pr==1){
            pr *= -1;
            curr^=1;
        }
        if(rb==0 && pr==-1){
            pr *= -1;
            curr^=1;
        }
        if(cb==m-1 && pc==1){
            pc *= -1;
            curr^=2;
        }
        if(cb==0 && pc==-1){
            pc *= -1;
            curr^=2;
        }
        if(dp[curr][rb][cb][0]!=-1) break;
        dp[curr][rb][cb][0] = counter;
        dp[curr][rb][cb][1] = L;
        L++;
        if(rb==rd || cb==cd) counter++;   
        rb += pr;
        cb += pc;
    }
    p = divi(p,100);
    ll p_ = sub(1,p);
    ll ans = 0;
    ll p_k = power(p_,counter); 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                if((i==rd || j==cd) && (dp[k][i][j][0]!=-1) ){
                    ll t = dp[k][i][j][0];
                    ll li = dp[k][i][j][1];
                    ll h1  = divi(mul(p,power(p_,t)),sub(1,p_k));
                    ll h2 = add(li,divi(mul(L,p_k),sub(1,p_k)));
                    ans = add(ans,mul(h1,h2));
                }
            }
        }
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