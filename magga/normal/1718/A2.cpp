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
struct Veniceset{
    int base = 0;
    set<int>s;
    void insert(int i){
        s.insert(i^base);
    }
    void clear(){
        s.clear();
        base = 0;
    }
    void resetBase(int t){
        base^=t;
    }
    bool isLocated(int i){
        if(s.find(i^base)==s.end()){
            return false;
        }
        return true;
    }
};
void solve(){
    ll n;cin>>n;
    ll arr[n];
    Veniceset vs;
    for(int i=0;i<n;i++) cin>>arr[i];
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            vs.clear();
            continue;
        }else{
            if(vs.isLocated(arr[i])){
                vs.clear();
                continue;
            }
            vs.insert(0);
            vs.resetBase(arr[i]);
            ans++;
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