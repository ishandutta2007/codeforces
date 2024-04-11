#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void pre(){}
void solve(){
    long long int n,m;cin>>n>>m;
    if( (n%2==0 && m%2==1) || n>m ){
        cout<<"NO"<<"\n";
        return;
    }
    cout<<"YES"<<"\n";
    if(n%2==1){
        for(int i=0;i<n-1;i++) cout<<1<<" ";
        cout<<m-n+1<<"\n";
    }else{
        for(int i=0;i<n-2;i++) cout<<1<<" ";
        cout<<(m-n+2)/2<<" "<<(m-n+2)/2<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}