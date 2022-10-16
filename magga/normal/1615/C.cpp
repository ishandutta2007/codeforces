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
    int n;cin>>n;
    string a;
    string b;
    cin>>a>>b;
    int arr[4]{0};
    for(int i=0;i<n;i++){
        int s = a[i]-'0';
        int p = b[i]-'0';
        arr[s*2+p]++;
    }
    int ans = 1e9;
    if(arr[1]==arr[2]){
        ans=min(ans,arr[1]+arr[2]);
    }
    if(arr[2] + arr[3]!=0){
        if(arr[3] == arr[0] + 1){
            ans = min(ans,arr[3] + arr[0]) ;
        }
    }
    if(ans==1e9){
        ans = -1;
    }
    cout<<ans<<"\n";
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