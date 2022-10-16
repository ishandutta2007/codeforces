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
    if(k!=1 && n%2==1){
        cout<<"NO"<<"\n";
        return;
    }
    cout<<"YES"<<"\n";
    vector<int>odd,even;
    for(int i=1;i<=n*k;i++){
        if(i%2==0) odd.push_back(i);
        else even.push_back(i);
    }
    while(odd.size()>0){
        for(int j=0;j<k;j++){
            cout<<odd.back()<<" ";
            odd.pop_back();
        }
        cout<<"\n";
    }
    while(even.size()>0){
        for(int j=0;j<k;j++){
            cout<<even.back()<<" ";
            even.pop_back();
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