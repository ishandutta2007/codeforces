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
    ll n,k,x;cin>>n>>k>>x;
    string s;cin>>s;
    vector<pair<char,int>>v;
    v.push_back({'a',0});
    for(int i=0;i<n;i++){
        if(s[i]==v.back().F){
            v.back().S++;
        }else{
            v.push_back({s[i],1});
        }
    }
    string ans;
    x--;
    while(v.size()>0){
        auto i = v.back();
        v.pop_back();
        if(i.F=='a'){
            for(int j=0;j<i.S;j++){
                ans+='a';
            }
        }else{
            int p = k*i.S + 1;
            int t = x%p;
            for(int j=0;j<t;j++){
                ans+='b';
            }
            x/=p;
        }
    }
    reverse(ans.begin(),ans.end());
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