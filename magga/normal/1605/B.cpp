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
    string s;cin>>s;
    int a = 0;
    for(auto i:s){
        if(i=='0') a++;
    }
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(i<a && s[i]=='1') ans.push_back(i);
        if(i>=a && s[i]=='0') ans.push_back(i);
    }
    if(ans.size()==0) cout<<0<<"\n";
    else{
        cout<<1<<"\n";
        cout<<ans.size()<<" ";
        for(auto i:ans){
            cout<<i+1<<" ";
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