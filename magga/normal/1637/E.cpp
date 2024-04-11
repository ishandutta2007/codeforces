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
    ll n,m,a,b,d;cin>>n>>m;
    map<ll,ll>f;
    for(int i=0;i<n;i++){
        cin>>d;
        f[d]++;
    }
    vector<pii>v;
    for(auto i:f) v.push_back(i);
    f.clear();
    for(int i=0;i<v.size();i++){
        f[v[i].F]=i;
    }
    vector<vector<ll>>g(v.size());
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a = f[a];
        b = f[b];
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<v.size();i++) g[i].push_back(i);
    ll ans = 0;
    map<int,set<int,greater<int>>>inf;
    for(auto &i:v){
        inf[i.S].insert(i.F);
    }
    for(int i=0;i<v.size();i++){
        ll node = v[i].F;
        ll fx = v[i].S;
        for(auto j:g[i]){
            inf[v[j].S].erase(v[j].F);
        }
        for(auto &i:inf){
            if(i.S.size()!=0){
                ans = max(ans,(node + (*i.S.begin()))*(fx + i.F));
            }
        }
        for(auto j:g[i]){
            inf[v[j].S].insert(v[j].F);
        }
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