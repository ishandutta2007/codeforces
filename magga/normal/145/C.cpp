#include<bits/stdc++.h>
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
long long int dv(long long int a,long long int b){return (a*inv(b))%mod;}
bool check(int n){
    while(n>0){
        if(n%10!=4 && n%10!=7){
            return false;
        }
        n/=10;
    }
    return true;
}
long long int fact[100001]{0};
void pre(){
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<=100000;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
}
long long int ncr(int n,int r){
    return dv(fact[n],mul(fact[r],fact[n-r]));
}
void solve(){
    int n,k,d;cin>>n>>k;
    unordered_map<int,int>m;
    int oo = 0;
    for(int i=0;i<n;i++){
        cin>>d;
        if(!check(d)){
            oo++;
        }else{
            m[d]++;
        }
    }
    long long int dp[2][k+1];
    for(int i=0;i<=k;i++){
        dp[1][i]=0;    
    }
    dp[1][0]=1;
    int j = 0;
    for(auto i:m){
        for(int p=0;p<=min(j+1,k);p++){
            dp[0][p]=dp[1][p];
        }
        for(int p=0;p<=min(j,k-1);p++){
            dp[1][p+1]+=(dp[0][p]*i.second)%mod;
            dp[1][p+1]%=mod;
        }
        j++;
    }
    long long int ans = 0;
    for(int i=0;i<=k;i++){
        if(oo>=i){
        ans+=(ncr(oo,i)*dp[1][k-i])%mod;
        ans%=mod;
        }else{
            break;
        }
    }
    cout<<ans<<"\n";
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