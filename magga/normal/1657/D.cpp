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
    ll n,c,h,d;cin>>n>>c;
    pii arr[n];
    vector<ll>max_dmg(c+1);
    for(int i=0;i<n;i++){
        cin>>arr[i].F>>d>>h;
        arr[i].S = d*h;
        max_dmg[arr[i].F] = max(max_dmg[arr[i].F],arr[i].S);
    }
    vector<ll>dp(c+1);
    for(int i=1;i<=c;i++){
        for(int j=1;j*i<=c;j++){
            dp[i*j] = max(dp[i*j],j*max_dmg[i]);
        }
    }
    ll m;cin>>m;
    vector<pii>monsters(m);
    for(int i=0;i<m;i++){
        cin>>monsters[i].F>>monsters[i].S;
        monsters[i].F *= monsters[i].S;
        monsters[i].S = i; 
    }
    sort(monsters.begin(),monsters.end());
    ll ans[m];
    int curr = 0;
    for(int i=0;i<m;i++){
        while(curr<=c){
            if(monsters[i].F >= dp[curr]){
                curr++;
            }else{
                break;
            }
        }
        if(curr==c+1){
            ans[monsters[i].S] = -1;
        }else{
            ans[monsters[i].S] = curr;
        }
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
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}