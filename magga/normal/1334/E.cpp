#include<bits/stdc++.h>
using namespace std;
long long int fac[1000001];
long long int ifac[1000001];
long long int mod = 998244353;
long long int power(long long int x, long long int y = mod-2){  
    long long int res = 1;
    long long int p = mod;
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0)  {  
        if (y & 1)  
            res = (res*x) % p;  
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return res;  
}  
void pre(){
    fac[1]=1;
    fac[0]=1;
    ifac[1]=1;
    ifac[0]=1;
    for(int i=2;i<=1000000;i++){
        fac[i]=(fac[i-1]*i)%mod;
        ifac[i]=power(fac[i]);
    }
}
vector<long long int>v;
long long int process(long long int u){
    long long int ooo = 0;
    long long int ans = 1;
    for(long long int i:v){
        int oo = 0;
        while(u%i==0){
            oo++;
            u/=i;
        }
        ooo+=oo;
        ans*=ifac[oo];
        ans%=mod;
    }
    ans*=fac[ooo];
    ans%=mod;
    return ans;
}
void solve(){
    long long int n;cin>>n;
    long long int oups = sqrt(n);
    for(long long int i=2;i<=oups;i++){
        if(n%i==0){
            v.push_back(i);
            while(n%i==0){
                n/=i;
            }
        }
    }
    //cout<<n<<"\n";
    if(n>=2){
        v.push_back(n);
    }
    int q;cin>>q;
    long long int u,o,p;
    for(int i=0;i<q;i++){
        cin>>u>>o;
        p=__gcd(u,o);
        u/=p;o/=p;
        long long int ans = process(u);
        ans*=process(o);
        cout<<ans%mod<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}