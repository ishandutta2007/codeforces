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
    int l,r,k;cin>>l>>r>>k;
    int num_odd = r-l+1;
    if(l%2==0) num_odd = (num_odd)/2;
    else num_odd = (num_odd+1)/2;
    if(l==r && r==1) cout<<"NO"<<"\n";
    else if(l==r) cout<<"YES"<<"\n";
    else if(num_odd <= k) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
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

// l r k 
// [l    r]
// 1 for odd and even 
// l l+1 r 
// 2 to aayega hi
// 2k+1 2k+3

// get rid of 1 
// l==r then 0 if l==r==1 this is no 
// No of odds 
// (l-r+1)