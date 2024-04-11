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
    ll w,h;cin>>w>>h;
    vector<ll>a[4];
    ll ans =0;
    for(int i=0;i<4;i++){
        int k;cin>>k;
        a[i].resize(k);
        for(int j=0;j<k;j++){
            cin>>a[i][j];
        }
        sort(a[i].begin(),a[i].end());
        if(i<2)
            ans = max(ans,(a[i][k-1]-a[i][0])*h);
        else 
            ans = max(ans,(a[i][k-1]-a[i][0])*w);
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