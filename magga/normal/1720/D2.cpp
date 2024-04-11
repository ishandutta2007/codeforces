#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pii pair<long long int,long long int>
#define F first
#define S second
using namespace std;
const long long int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    long long int operator()(long long int x) const { return x ^ RANDOM; }
};
long long int g(long long int a,long long int b){
    return a*50 + b;
}
void solve(){
    long long int n;cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    //map<long long int,pair<pii,pii>>m;
    gp_hash_table<long long int,pair<pair<int,int>,pair<int,int>>,chash>m;
    int ans = 0;
    for(long long int i=0;i<n;i++){
        int curr = 0;
        int ref = (arr[i]^i);        
        for(int j=0;j<=30;j++){
            ref>>=1;
            if( (arr[i]&(1<<j)) ){
                if( (i&(1<<j)) ){
                    curr = max(curr,m[g(ref,j)].F.S+1);       
                }else{
                    curr = max(curr,m[g(ref,j)].S.S+1);  
                }
            }else{
                if( (i&(1<<j)) ){
                    curr = max(curr,m[g(ref,j)].F.F+1);       
                }else{
                    curr = max(curr,m[g(ref,j)].S.F+1);  
                }
            }
        }
    
        ans = max(ans,curr);
        ref = (arr[i]^i);

        for(int j=0;j<=30;j++){
            ref>>=1;
            if( (arr[i]&(1<<j)) ){
                if( (i&(1<<j)) ){
                    m[g(ref,j)].F.F = max(m[g(ref,j)].F.F,curr);
                }else{
                    m[g(ref,j)].F.S = max(m[g(ref,j)].F.S,curr);
                }
            }else{
                if( (i&(1<<j)) ){
                    m[g(ref,j)].S.F = max(m[g(ref,j)].S.F,curr);
                }else{
                    m[g(ref,j)].S.S = max(m[g(ref,j)].S.S,curr);
                }
            }
        }
        
    }
    cout<<ans<<"\n";
}
int main(void){
    int T;cin>>T;
    while(T>0){
        solve();
        T--;
    }
}