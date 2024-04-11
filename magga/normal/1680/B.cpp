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
// WRITE DOWN THE RECCURANCES FFS 
// Please write the recurances once :(
void pre(){}
void solve(){
    int n,m;cin>>n>>m;
    string arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int c[2]{n+1,m+1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='R'){
                c[0] = min(c[0],i);
                c[1] = min(c[1],j);
            }
        }
    }
    if(arr[c[0]][c[1]]=='R')
        cout<<"YES"<<"\n";
    else
        cout<<"NO"<<"\n";
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