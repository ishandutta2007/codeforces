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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// WRITE DOWN THE RECCURANCES FFS 
void pre(){}
ll query(string s){
    cout<<"? "<<s<<"\n";
    cout.flush();
    ll ret;cin>>ret;
    return ret;
}
void answer(ll k){
    cout<<"! "<<k<<"\n";
    cout.flush();
}
void solve(){
    int n,m;cin>>n>>m;
    string s;
    for(int i=0;i<m;i++) s+='0';
    pii arr[m];
    for(int i=0;i<m;i++){
        s[i] = '1';
        arr[i].F = query(s);
        arr[i].S = i;
        s[i] = '0';
    }
    sort(arr,arr+m);
    ll ans = 0;
    for(int i=0;i<m;i++){
        s[arr[i].S] = '1';
        ll ret = query(s);
        if(ret != ans + arr[i].F){
            s[arr[i].S] = '0'; 
        }else{
            ans = ret;
        }
    }
    answer(ans);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}