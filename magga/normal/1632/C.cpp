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
    int a,b;cin>>a>>b;
    int ans = b - a;
    for(int i=b;i<=2*b;i++){
        int curr = i;
        for(int j=20;j>=0;j--){
            if( (curr&(1<<j)) && (curr^(1<<j))>=a ){
                curr^=(1<<j);
            }
        }
        int val = i - b + curr - a + 1; 
        ans = min(ans,val); 
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
/*
bits different b/w a and b will be covered via addition of 1 
or operation will occur only once 
optimal value to jump for each b 
or optimal value to jump from for each a z
*/