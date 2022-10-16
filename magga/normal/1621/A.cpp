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
    int n,k;cin>>n>>k;
    vector<pii>ans;
    for(int i=1;i<=n;i+=2){
        ans.push_back({i,i});
    }
    if(ans.size()<k) cout<<-1<<"\n";
    else{
        string arr[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i]+='.';
            }
        }
        for(int i=0;i<k;i++){
            arr[ans[i].F-1][ans[i].S-1] = 'R';
        }
        for(auto i:arr){
            cout<<i<<"\n";
        }
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