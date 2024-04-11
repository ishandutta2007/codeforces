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
    int n,m;cin>>n>>m;
    ll r[n];
    for(int i=0;i<n;i++) cin>>r[i];
    string correct[n];
    for(int i=0;i<n;i++) cin>>correct[i];
    vector<int>ans(m);
    vector<int>temp(m);
    ll comp = 0;
    vector<vector<int>>a(m);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(correct[j][i]-'0') a[i].push_back(j);
        }
    }
    for(int i=0;i<(1<<n);i++){
        vector<vector<int>>v(21);
        ll curr = 0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                curr+=r[j];
            }else{
                curr-=r[j];
            }
        }
        for(int j=0;j<m;j++){
            int coeff = 0;
            for(auto k:a[j]){
                if(i&(1<<k)){
                    coeff--;
                }else{
                    coeff++;
                }
            }
            v[10+coeff].push_back(j);
        }
        ll val = m;
        for(int i=20;i>=0;i--){
            for(auto j:v[i]){
                temp[j] = val;
                curr += val*(i-10);
                val--;
            }
        }
        if(curr>=comp){
            comp = curr;
            ans = temp;
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
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}