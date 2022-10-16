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
map<ll,ll>m[2];
map<pii,ll>m2;
ll cost(int a,int b){
    if(m2.find({a,b})==m2.end()){
        return m[0][a] + m[1][b];
    }else{
        return min(m2[{a,b}], m[0][a] + m[1][b]);
    }
}
void solve(){
    int n;cin>>n;
    ll min_label = 1e15;
    ll max_label = -1e15;
    ll a,b,c;
    m[0].clear();
    m[1].clear();
    m2.clear();
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        if(m[0].find(a)==m[0].end()) m[0][a] = 1e14;
        if(m[1].find(b)==m[1].end()) m[1][b] = 1e14;
        if(m2.find({a,b})==m2.end()) m2[{a,b}] = 1e14;
        m[0][a] = min(m[0][a],c);
        m[1][b] = min(m[1][b],c);
        m2[{a,b}] = min(m2[{a,b}],c);
        min_label = min(min_label,a);
        max_label = max(max_label,b);
        cout<<cost(min_label,max_label)<<"\n";
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