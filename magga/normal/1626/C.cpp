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
    int n;cin>>n;
    vector<pair<ll,pii>>events(2*n);
    for(int i=0;i<n;i++){
        cin>>events[i].F;
        events[i].S.F = 1;
        events[i].S.S = i;
    }
    for(int i=n;i<2*n;i++){
        cin>>events[i].F;
        events[i].F = events[i-n].F - events[i].F + 1;
        events[i].S.F = 0;
        events[i].S.S = i-n;
    }
    sort(events.begin(),events.end());
    ll last = -1;
    ll ans = 0;
    set<int>c;
    for(auto i:events){
        if(c.find(i.S.S)==c.end()){
            c.insert(i.S.S);
            if(last==-1){
                last = i.F;
            }
        }else{
            c.erase(i.S.S);
            if(c.size()==0){
                ll num = i.F - last + 1;
                ans += (num*(num+1))/2;
                last = -1;
            }
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