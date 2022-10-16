#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void pre(){}
void solve(){
    int n,m;cin>>n>>m;
    string s,t;cin>>s>>t;
    for(int i=m-1;i>=1;i--){
        if(t[i]!=s[n-m+i]){
            cout<<"No"<<"\n";
            return;
        }
    }
    bool found = false;
    for(int i=0;i<=n-m;i++){
        if(s[i]==t[0]) found = true;
    }
    if(found){
        cout<<"Yes"<<"\n";
    }else{
        cout<<"No"<<"\n";
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