#include<bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
map<long long int,long long int>cach;
long long int power(long long int x, long long int y) { 
    if (y == 0) 
        return 1; 
    long long int p = power(x, y/2) % mod; 
    p = (p * p) % mod; 
    return (y%2 == 0)? p : (x * p) % mod; 
} 
long long int modInverse(long long int a){
    long long int poo;
    if(cach.find(a)==cach.end()){
        poo = power(a, mod-2);
        cach[a]=poo;
        return poo;
    } 
    return cach[a];
} 
void solve(){
    long long int n,d,g;cin>>n;
    vector<long long int>arr[n];
    long long int m[1000001]{0};
    long long int ans = 0 ;
    for(long long int i=0;i<n;i++){
        cin>>g;
        for(long long int j=0;j<g;j++){
            cin>>d;
            arr[i].push_back(d);
            m[d]++;
        }
    }
    long long int gru = modInverse(n);
    gru*=gru;
    gru%=mod;
    for(long long int i=0;i<n;i++){
        d=0;
        for(long long int j=0;j<arr[i].size();j++){
            d+=m[arr[i][j]];
        }
        d*=modInverse(arr[i].size());
        d%=mod;
        ans+=d;
        ans%=mod;
    }
    ans*=gru;
    ans%=mod;
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}