#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// WRITE DOWN THE RECCURANCES FFS 
void pre(){}
void solve(){
    int n,m,a,d;cin>>n>>m;
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    set<pii>active;
    ll curr = arr[0];
    active.insert({0,arr[0]});
    for(int i=1;i<n;i++){
        if(arr[i]<curr){
            active.insert({i,arr[i]});
            curr = arr[i];
        }
    }
    for(int i=0;i<m;i++){
        cin>>a>>d;
        a--;
        if(active.find({a,arr[a]})!=active.end()) active.erase({a,arr[a]});
        auto poit = active.lower_bound({a,0});
        arr[a]-=d;
        bool inserted = false;
        if(a==0){
            active.insert({a,arr[a]});
            inserted = true;
        }else{
            poit--;
            if((*poit).S>arr[a]){
                active.insert({a,arr[a]});
                inserted = true;
            }
        }
        if(inserted){
            vector<pii>toBeRemoved;
            poit = active.find({a,arr[a]});
            poit++;
            while(poit!=active.end()){
                if((*poit).S>=arr[a]){
                    toBeRemoved.push_back(*poit);
                }else{
                    break;
                }
                poit++;
            }
            for(auto i:toBeRemoved) active.erase(i);
        }
        cout<<active.size()<<" ";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    int t;cin>>t;
    for(int i=0;i<t;i++)
        solve();
}