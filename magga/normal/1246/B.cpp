#include<bits/stdc++.h>
using namespace std;
void pre(){}
#define MAXN   1000001  
int spf[MAXN]; 
long long int n,k,d;
struct primeFactorization { 
    int countOfPf, primeFactor; 
}; 
void sieve(){ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
        spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
    for (int i=3; i*i<MAXN; i++){ 
        if (spf[i] == i){ 
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
vector<pair<int,int>> getFactorization(int x){ 
    vector<pair<int,int>> ret,pet; 
    while (x != 1){ 
        if(ret.size()==0 || ret.back().first!=spf[x]){
            ret.push_back({spf[x],1});
        }else{
            ret[ret.size()-1].second++;
        }
        x = x / spf[x];
    } 
    for(auto i:ret){
        if(i.second%k==0){
            continue;
        }else{
            pet.push_back({i.first,i.second%k});
        }
    }
    return pet; 
}
vector<pair<int,int>> alt(vector<pair<int,int>> a){
    vector<pair<int,int>> o;
    for(auto i:a){
        o.push_back({i.first,(k-i.second)%k});
    }
    return o;
}
void solve(){
    cin>>n>>k;
    map<vector<pair<int,int>>,long long int>m;
    for(auto i=0;i<n;i++){
        cin>>d;
        m[getFactorization(d)]++;
    }
    long long int ans = 0;
    for(auto i:m){
        auto p = alt(i.first);
        if(i.first==p){
            ans+=(i.second*(i.second-1));
        }else{
            ans+=i.second*m[p];
        }
    }
    cout<<ans/2<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    sieve();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}