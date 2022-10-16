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
void solve(){
    int n,m,a,b;cin>>n>>m;
    int r_m = 0;
    int w_m = 0;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        r_m = max(r_m,a);
        w_m = max(w_m,b);
    }
    if(r_m+w_m>n){
        cout<<"IMPOSSIBLE"<<"\n";
    }else{
        for(int i=0;i<r_m;i++){
            cout<<'R';
        }
        for(int i=r_m;i<n;i++){
            cout<<'W';
        }
        cout<<"\n";
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