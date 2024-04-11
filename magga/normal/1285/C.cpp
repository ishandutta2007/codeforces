#include<bits/stdc++.h>
using namespace std;
set<long long int>s;
map<long long int,long long int>m;
vector<long long int>v;
void primeFactors(long long int n){  
    while (n % 2 == 0)  {  
        m[2]++;  
        n = n/2;  
    }  
    long long int j = sqrt(n);
    for (long long int i = 3; i <= j; i = i + 2){  
        while (n % i == 0)  {  
            m[i]++;  
            n = n/i;  
        }  
    }  
    if (n > 2)  
        m[n]++;  
} 
void rec(long long int ans,long long int i){
    if(i==v.size()){
        return;
    }
    rec(ans*v[i],i+1);
    rec(ans,i+1);
    s.insert(ans*v[i]);
}
void solve(){
    long long int n;cin>>n;
    primeFactors(n);
    for(auto i:m){
        v.push_back(pow(i.first,i.second));
    }
    v.push_back(1);
    sort(v.begin(),v.end());
    rec(1,0);
    long long int t =sqrt(n);
    auto k = *s.lower_bound(t);
    cout<<n/k<<" "<<k<<"\n";
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