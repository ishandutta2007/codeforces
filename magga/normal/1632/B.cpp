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
    vector<bool>f(n);
    n--;
    int ans = 0;
    for(int i=0;i<=20;i++){
        if(n&(1<<i)){
            ans = i;
        }
    }
    //cout<<ans<<"\n";
    cout.flush();
    vector<int>arr;
    for(int i=0;i<=n;i++){
        if(i&(1<<ans)){
            arr.push_back(i);
            f[i] = 1;
        }
    }
    int a = arr.back() - (1<<ans);
    arr.push_back(a);
    f[a]=1;
    for(int i=0;i<=n;i++) if(!f[i]) arr.push_back(i);
    for(auto i:arr) cout<<i<<" ";
    cout<<"\n";
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