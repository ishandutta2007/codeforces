#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void pre(){}
void wrap(pii &a){
    a.F%=2;
    a.S%=2;
}
void solve(){
    int n;cin>>n;
    vector<pii>v(3);
    vector<vector<pii>>corners{{{1,1},{1,2},{2,1}},{{n,1},{n-1,1},{n,2}},{{n,n},{n-1,n},{n,n-1}},{{1,n},{1,n-1},{2,n}}};
    for(auto &i:corners) sort(i.begin(),i.end());
    for(int i=0;i<3;i++) cin>>v[i].F>>v[i].S;
    pii d;cin>>d.F>>d.S;
    sort(v.begin(),v.end());
    bool possible = false;
    if(v==corners[0]){
        //cout<<"case 1\n";
        if(d.F==1 || d.S==1){
            possible = true;
        }
    }else if(v==corners[1]){
        //cout<<"case 2\n";
        if(d.F==n || d.S==1){
            possible = true;
        }
    }else if(v==corners[2]){
        //cout<<"case 3\n";
        if(d.F==n || d.S==n){
            possible = true;
        }
    }else if(v==corners[3]){
        //cout<<"case 4\n";
        if(d.F==1 || d.S==n){
            possible = true;
        }
    }else{
        wrap(d);
        //cout<<"case 5\n";
        for(auto &i:v) wrap(i);
        if(d==v[0] || d==v[1] || d==v[2]){
            possible = true;
        }
    }
    if(possible) cout<<"YES\n";
    else         cout<<"NO\n";
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