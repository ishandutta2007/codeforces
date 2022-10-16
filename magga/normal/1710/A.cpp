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
    long long int n,m,k;cin>>n>>m>>k;
    long long int arr[k];
    for(int i=0;i<k;i++) cin>>arr[i];
    long long int curr = 0;
    bool flag = true;
    for(int i=0;i<k;i++){
        if(arr[i]<2*n) continue;
        if(arr[i]/n !=2 ) flag = false;
        curr += arr[i]/(n);
    }
    if(curr>=m && (!(m%2==1 && flag)) ){
        cout<<"Yes"<<"\n";
        return;
    }
    curr = 0;
    flag = true;
    for(int i=0;i<k;i++){
        if(arr[i]<2*m) continue;
        if(arr[i]/m !=2 ) flag = false;
        curr += arr[i]/(m);
    }
    if(curr>=n && (!(n%2==1 && flag) )){
        cout<<"Yes"<<"\n";
        return;
    }
    cout<<"No"<<"\n";
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