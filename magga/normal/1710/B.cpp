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
    long long int n,m;cin>>n>>m;
    pii arr[n];
    long long int coeff = 0;
    set<long long int>pos;
    map<long long int,long long int>w;
    long long int val = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i].F>>arr[i].S;
        pos.insert(arr[i].F);
        pos.insert(arr[i].F-arr[i].S);
        pos.insert(arr[i].F+arr[i].S);
        w[arr[i].F]+=2;
        w[arr[i].F-arr[i].S]--;
        w[arr[i].F+arr[i].S]--;
    }
    vector<pii>p(pos.size());
    int t = pos.size();
    for(int i=0;i<t;i++){
        auto j = (*pos.begin());
        pos.erase(j);
        p[i].S = j;
        p[i].F = val + coeff*j;
        coeff -= 2*w[j];
        val   += 2*w[j]*j; 
    }
    long long int a = -1e18;
    long long int b = -1e18;
    for(int i=0;i<t;i++){
        p[i].F/=2;
        if(p[i].F>m){
            a = max(a,p[i].F+p[i].S-m);
            b = max(b,p[i].F-p[i].S-m);
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i].F+arr[i].S<a || arr[i].S-arr[i].F<b){
            cout<<0;
        }else{
            cout<<1;
        }
    }
    cout<<"\n";
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