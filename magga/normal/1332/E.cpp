#include<bits/stdc++.h>
using namespace std;
void pre(){}
long long int mod = 998244353;
long long int power(long long int x,long long int y ){  
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
long long int sub(long long int a,long long int b){
    return (a-b+mod)%mod;
}
long long int solve(long long int n,long long int l,long long int r){
    long long int odd,even;
    even = (r-l+1)/2;
    odd = r-l+1-even;
    long long int ans;
    return ((power(even+odd,n)+power(abs(even-odd),n))*power(2,mod-2))%mod;
}
void helper(){
    long long int l,r,n,m;cin>>n>>m>>l>>r;
    if(n*m%2==0){
        cout<<solve(n*m,l,r)<<"\n";
    }else{
        cout<<power(r-l+1,n*m)<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	helper();
    }   
}