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
    int n;cin>>n;
    n*=2;
    string s;cin>>s;
    long long int curr = 0;
    set<int>r;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(s[i]==')'){
            r.erase(curr);
            curr--;
        }else if(s[i]=='('){
            if(r.find(curr)==r.end()){
                r.insert(curr);
                ans++;
            }
            curr++;
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