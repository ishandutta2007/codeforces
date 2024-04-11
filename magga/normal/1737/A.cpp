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
void solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    vector<int>v(26);
    for(auto i:s) v[i-'a']++;
    string ans;
    for(int i=0;i<k;i++){
        bool inserted = false;
        for(int j=0;j<min(26,n/k);j++){
            if(v[j]==0){
                ans+=('a'+j);
                inserted = true;
                break;
            }else{
                v[j]--;
            }
        }
        if(!inserted) ans += ('a'+n/k);
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