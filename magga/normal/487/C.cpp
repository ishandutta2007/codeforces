#include<bits/stdc++.h>
using namespace std;
long long int mod = 1e9+7;
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
#define MAXN   1000001 
int spf[MAXN];  
void sieve(){ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++)  spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) spf[i] = 2; 
    for (int i=3; i*i<MAXN; i++){  
        if (spf[i] == i){  
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}
bool prime(int i){
    if(spf[i]==i){
        return true;
    }
    return false;
}  
vector<int> getFactorization(int x){ 
    vector<int> ret; 
    while (x != 1){ 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
}
bool flag[100001]{0};
int ans[100001];
void pre(){
    sieve();
}
void solve(){
    int n;cin>>n;
    mod=n;
    if(n==1){
         cout<<"YES"<<"\n";
        cout<<1<<"\n";
        return;
    }else if(n==2){
         cout<<"YES"<<"\n";
        cout<<1<<"\n";
        cout<<2<<"\n";
        return;
    }
    if(n==4){
         cout<<"YES"<<"\n";
        cout<<"1\n3\n2\n4\n";
        return;    
    }
    if(!prime(n)){
        cout<<"NO"<<"\n";
        return;
    }
    cout<<"YES"<<"\n";
    int j = 1;
    ans[0]=1;
    ans[n-1]=n;
    for(int i=2;i<n;i++){
        ans[i-1]=(i*power(i-1,n-2))%mod;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<"\n";
    }
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