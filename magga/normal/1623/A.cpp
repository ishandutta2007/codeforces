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
    int n,m,rb,cb,rd,cd;cin>>n>>m>>rb>>cb>>rd>>cd;
    int ans = 0;
    int pr = 1;
    int pc = 1;
    while(true){
        if(rb==rd || cb==cd) break;
        ans++;    
        if(rb==n && pr==1) pr *= -1;
        if(rb==1 && pr==-1) pr *= -1;
        if(cb==m && pc==1) pc *= -1;
        if(cb==1 && pc==-1) pc *= -1;
        rb += pr;
        cb += pc;
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