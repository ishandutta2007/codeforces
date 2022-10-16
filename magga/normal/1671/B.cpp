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
// Please write the recurances once :(
void pre(){}
bool is_valid(int x,vector<int>arr){
    int curr = x;
    for(int i=0;i<arr.size();i++){
        if(abs(curr-arr[i])>1){
            return false;
        }
        curr++;
    }
    return true;
}
void solve(){
    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    if(is_valid(arr[0]-1,arr) || is_valid(arr[0],arr) || is_valid(arr[0]+1,arr)  ){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
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