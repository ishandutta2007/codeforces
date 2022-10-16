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
    int qa,d,a,b;cin>>qa;
    map<int,int>m;
    vector<pair<int,pii>>q;
    vector<int>v;
    for(int i=0;i<qa;i++){
        cin>>d;
        if(d==1){
            cin>>a;
            q.push_back({1,{a,-1}});
        }else{
            cin>>a>>b;
            q.push_back({0,{a,b}});
        }
    }
    while(q.size()>0){
        auto i = q.back();
        q.pop_back();
        if(i.F==1){
            if(m.find(i.S.F)==m.end()) m[i.S.F]=i.S.F;
            v.push_back(m[i.S.F]);
        }else{
            if(m.find(i.S.S)==m.end()) m[i.S.S]=i.S.S;
            m[i.S.F] = m[i.S.S];
        }
    }
    reverse(v.begin(),v.end());
    for(auto i:v) cout<<i<<" ";
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