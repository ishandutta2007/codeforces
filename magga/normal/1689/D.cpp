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
struct manhattenExtremes{
    pii mark[4];
    manhattenExtremes(vector<pii>arr){
        for(int i=0;i<4;i++) mark[i] = {1e18,-1e18};
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<4;j++){
                ll x = arr[i].F*pow(-1,(j&1)>0);
                ll y = arr[i].S*pow(-1,(j&2)>0);
                mark[j].F = min(mark[j].F,x+y);
                mark[j].S = max(mark[j].S,x+y);
            }
        }
    }
    long long query(pii a){
        ll ret = 0;
        for(int j=0;j<4;j++){
            ll x = a.F*pow(-1,(j&1)>0);
            ll y = a.S*pow(-1,(j&2)>0);
            ret = max(ret,abs(mark[j].F-(x+y)));
            ret = max(ret,abs(mark[j].S-(x+y)));
        }
        return ret;
    }
};
void pre(){}
void solve(){
    int n,m;cin>>n>>m;
    vector<pii>blackCells;
    string arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<m;j++){
            if(arr[i][j]=='B') blackCells.push_back({i,j});
        }
    }
    manhattenExtremes fixer(blackCells);
    pii ans = {0,0};
    ll ma = fixer.query(ans);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ll t = fixer.query({i,j});
            if(t<ma){
                ma = t;
                ans = {i,j};
            }
        }
    }
    cout<<ans.F+1<<" "<<ans.S+1<<"\n";
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