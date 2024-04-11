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
long long int di(long long int a,long long int b){return (a*inv(b))%mod;}
long long int fact[100001];
void pre(){
    fact[0]=1;
    for(long long int i=1;i<=100000;i++){
        fact[i]=mul(fact[i-1],i);
    }
}
long long int ncr(long long int n,long long int r){
    return di( di( fact[n] , fact[r] ) , fact[n-r] );
}
void solve(){
    long long int n,m,k;cin>>n>>m>>k;
    if(2*k>n-1 || 2*k>m-1){
        cout<<0<<"\n";
        return;
    }
    cout<<mul(ncr(n-1,2*k),ncr(m-1,2*k))<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
	//cout<<"Case #"<<i+1<<": ";
       	solve();
    }   
}