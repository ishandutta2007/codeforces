#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
// Please write the recurances once :(
void pre(){}
void solve(){
    int n,d;cin>>n;
    map<int,int>m;
    pii arr[n];
    for(int i=0;i<n;i++){
        cin>>d;
        arr[i].S=d;
        m[d] = i;
    }
    string s;cin>>s;
    for(int i=0;i<n;i++){
        arr[i].F = s[i] - '0';
    }
    sort(arr,arr+n);
    reverse(arr,arr+n);
    int ans[n];
    for(int i=0;i<n;i++){
        ans[m[arr[i].S]] = n-i;
    }
    for(auto i:ans){
        cout<<i<<" ";
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