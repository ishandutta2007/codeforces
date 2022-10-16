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
vector<int>arr[100000+1];
int pref[100000+1]{0};
void pre(){
    for(int i=1;i<=100000;i++){
        for(int j=1;i*j<=100000;j++){
            arr[i*j].push_back(i);
        }
    }
}
long long int val(int i){
    long long int ret = 1;
    int oo = 0;
    for(int j=arr[i].size()-1;j>=0;j--){
        if(arr[i][j]!=i)
            ret*=power(j+1,pref[arr[i][j]]-oo);
        else{
            long long int o1 = power(j+1,pref[arr[i][j]]-oo) - power(j,pref[arr[i][j]]-oo) + mod;
            ret *= o1%mod;
        }
        oo=pref[arr[i][j]];
        ret%=mod;
    }
    //cout<<i<<" "<<ret<<"\n";
    return ret;
}
void solve(){
    int n,d;cin>>n;
    for(int i=0;i<n;i++){
        cin>>d;pref[d]++;
    }
    for(int i=100000-1;i>=0;i--) pref[i]+=pref[i+1];
    long long int ans = 0;
    for(int i=1;i<100001;i++){
        ans+=val(i);
    }
    cout<<ans%mod<<"\n";
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