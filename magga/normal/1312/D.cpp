#include<bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
long long int fact[200001];
long long int power(long long int x,long long int y) {
    if (y == 0)
        return 1;
    long long int p = power(x, y/2) % mod;
    p = (p * p) % mod;
    return (y%2 == 0)? p : (x * p) % mod;
}
long long int modInverse(long long int a) {
    return  power(a,mod-2);
}
long long int mult(long long int a,long long int b){
    //return 0;
    return ((a%mod)*(b%mod))%mod;
}
long long int sub(long long int a,long long int b){
    return ((a%mod)-(b%mod)+mod)%mod;
}
void pre(){
    fact[0]=1;
    for(long long int i=1;i<=200000;i++){
        fact[i]=mult(fact[i-1],i);
    }
}
long long int ncr(long long int n,long long int r){
    return mult(mult(modInverse(fact[n-r]),modInverse(fact[r])),fact[n]);
}
void solve(){
    long long int n,m;cin>>n>>m;
    n--;
    if(n>m){
        cout<<0<<"\n";
        return;
    }
    long long int ans = sub(mult(n-1,power(2,n-2)),0);
    long long int b = mult(modInverse(fact[n]),modInverse(fact[m-n]));
    b=mult(b,fact[m]);
    cout<<mult(b,ans)<<"\n";
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